#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>

#include "gamesession.h"
#include "gamemanager.h"

int main(int argc, char *argv[])
{
    // Qt-Konsolenanwendung starten (Event-Loop für TCP notwendig).
    QCoreApplication a(argc, argv);

    // TCP-Server + zentrale Spielverwaltung
    QTcpServer server;
    GameManager manager;

    // Wird ausgelöst, wenn ein neuer Client verbindet.
    QObject::connect(&server, &QTcpServer::newConnection, [&]() {
        while (server.hasPendingConnections()) {
            QTcpSocket* socket = server.nextPendingConnection();
            qDebug() << "Client connected from" << socket->peerAddress().toString()
                     << "port" << socket->peerPort();

            // Eigene Session pro Client (Parent = server => wird automatisch aufgeräumt)
            new GameSession(socket, &manager, &server);
        }
    });

    // Server starten
    const quint16 port = 4242;

    if (!server.listen(QHostAddress::AnyIPv4, port)) {
        qCritical() << "Server konnte nicht starten auf Port" << port
                    << "-" << server.errorString();
        return 1; // ohne laufenden Server macht Event-Loop keinen Sinn
    }

    qDebug() << "Server hört auf" << server.serverAddress().toString()
             << "Port" << server.serverPort();

    // Event-Loop starten
    return a.exec();
}
