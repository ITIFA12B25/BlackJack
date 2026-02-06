#include "gamesession.h"

#include <QJsonDocument>
#include <QDebug>

// Konstruktor: verbindet Socket-Signale und sendet "hello"
GameSession::GameSession(QTcpSocket* socket, GameManager* manager, QObject* parent)
    : QObject(parent),
    m_socket(socket),
    m_manager(manager)
{
    connect(m_socket, &QTcpSocket::readyRead,
            this, &GameSession::onReadyRead);

    connect(m_socket, &QTcpSocket::disconnected,
            this, &GameSession::onDisconnected);

    sendJson(QJsonObject{
        {"type", "hello"},
        {"msg",  "connected"}
    });
}

// Liest JSON-Nachrichten zeilenweise (\n als Trenner)
void GameSession::onReadyRead()
{
    while (m_socket->canReadLine()) {
        const QByteArray line = m_socket->readLine().trimmed();
        if (!line.isEmpty())
            handleLine(line);
    }
}

// Client getrennt -> Socket freigeben
void GameSession::onDisconnected()
{
    qDebug() << "Client disconnected";
    m_socket->deleteLater();
}

// JSON parsen und "type" auswerten
void GameSession::handleLine(const QByteArray& line)
{
    qDebug() << "RX:" << line;

    const QJsonDocument doc = QJsonDocument::fromJson(line);
    if (!doc.isObject()) {
        sendError("invalid json");
        return;
    }

    const QJsonObject obj = doc.object();
    const QString type   = obj.value("type").toString();
    const QString gameId = obj.value("gameId").toString(); // optional

    if (type.isEmpty()) {
        sendError("missing type");
        return;
    }

    handleMessage(type, gameId);
}

// Befehle: join / bet / hit / stand (vereinfachte Logik)
void GameSession::handleMessage(const QString& type, const QString& gameId)
{
    Q_UNUSED(gameId); // aktuell nicht benutzt
    qDebug() << "Command:" << type;

    if (type == "join") {
        m_joined = true;
        sendJson(QJsonObject{{"type","joined"},{"msg","ok"}});
        return;
    }

    if (type == "bet") {
        if (!m_joined) {
            sendError("join first");
            return;
        }
        m_gameActive = true;
        sendJson(QJsonObject{{"type","state"},{"phase","playerTurn"},{"msg","game started"}});
        return;
    }

    if (type == "hit" || type == "stand") {
        if (!m_gameActive) {
            sendError("no active game");
            return;
        }

        if (type == "hit") {
            sendJson(QJsonObject{{"type","state"},{"msg","hit received"}});
        } else {
            m_gameActive = false;
            sendJson(QJsonObject{{"type","roundOver"},{"msg","stand received"}});
        }
        return;
    }

    sendError("unknown command");
}

// JSON + '\n' senden (wichtig: \n für canReadLine())
void GameSession::sendJson(const QJsonObject& obj)
{
    const QJsonDocument doc(obj);
    m_socket->write(doc.toJson(QJsonDocument::Compact) + "\n");
    m_socket->flush();
}

// Standard-Fehlerantwort
void GameSession::sendError(const QString& msg)
{
    sendJson(QJsonObject{{"type","error"},{"msg",msg}});
}
