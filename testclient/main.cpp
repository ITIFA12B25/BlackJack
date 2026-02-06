#include <QCoreApplication>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTextStream>
#include <QDebug>

static void sendJson(QTcpSocket& s, const QJsonObject& obj)
{
    const QJsonDocument doc(obj);
    s.write(doc.toJson(QJsonDocument::Compact) + "\n");
    s.flush();
}

// Liest alle bereits angekommenen Zeilen vom Server und druckt sie.
static void drainServer(QTcpSocket& socket)
{
    // kurz warten, damit Antworten ankommen (nicht blockierend "ewig")
    socket.waitForReadyRead(150);

    while (socket.canReadLine()) {
        const QByteArray line = socket.readLine().trimmed();
        if (!line.isEmpty())
            qDebug() << "SERVER:" << line;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTcpSocket socket;
    QTextStream in(stdin);
    QTextStream out(stdout);

    const QString host = "127.0.0.1";
    const quint16 port = 4242;

    qDebug() << "Connecting to" << host << port;
    socket.connectToHost(host, port);

    if (!socket.waitForConnected(5000)) {
        qDebug() << "Connection failed:" << socket.error() << socket.errorString();
        return 1;
    }

    qDebug() << "Connected!";
    drainServer(socket); // "hello" sofort lesen (sonst rutscht es nach hinten)

    // Interaktives Menü
    while (true) {
        out << "\n1) join\n2) bet 50\n3) hit\n4) stand\n5) quit\n> ";
        out.flush();

        QString cmd = in.readLine();
        if (cmd.isNull()) {                 // stdin geschlossen
            qDebug() << "stdin closed -> exiting";
            break;
        }

        cmd = cmd.trimmed().toLower();
        if (cmd.isEmpty())                  // leere Eingabe ignorieren
            continue;

        if (cmd == "1" || cmd == "join") {
            sendJson(socket, {{"type","join"}});
            drainServer(socket);
        }
        else if (cmd == "2" || cmd.startsWith("bet")) {
            int val = 50;
            const QStringList parts = cmd.split(' ', Qt::SkipEmptyParts);
            if (parts.size() >= 2) {
                bool ok = false;
                const int parsed = parts[1].toInt(&ok);
                if (ok) val = parsed;
            }
            sendJson(socket, {{"type","bet"},{"value", val}});
            drainServer(socket);
        }
        else if (cmd == "3" || cmd == "hit") {
            sendJson(socket, {{"type","hit"}});
            drainServer(socket);
        }
        else if (cmd == "4" || cmd == "stand") {
            sendJson(socket, {{"type","stand"}});
            drainServer(socket);
        }
        else if (cmd == "5" || cmd == "quit" || cmd == "exit") {
            break;
        }
        else {
            out << "Unknown. Use: 1/join, 2/bet [value], 3/hit, 4/stand, 5/quit\n";
        }
    }

    return 0;
}
