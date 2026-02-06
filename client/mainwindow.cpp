#include "mainwindow.h"

#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QJsonDocument>
#include <QJsonObject>

MainWindow::MainWindow()
{
    // UI ohne .ui Datei bauen (Prototyp).
    auto* central = new QWidget(this);
    auto* root = new QVBoxLayout(central);

    auto* title = new QLabel("BLACKJACK (Prototype)", this);
    root->addWidget(title);

    // Eingabe für GameId
    auto* rowGame = new QHBoxLayout();
    rowGame->addWidget(new QLabel("GameId:", this));
    m_gameIdEdit = new QLineEdit(this);
    m_gameIdEdit->setPlaceholderText("z.B. 123456");
    rowGame->addWidget(m_gameIdEdit);
    root->addLayout(rowGame);

    // Buttons
    m_btnCreate = new QPushButton("Create Game", this);
    m_btnJoin   = new QPushButton("Join Game", this);
    m_btnHit    = new QPushButton("Hit", this);
    m_btnStand  = new QPushButton("Stand", this);

    root->addWidget(m_btnCreate);
    root->addWidget(m_btnJoin);

    auto* rowActions = new QHBoxLayout();
    rowActions->addWidget(m_btnHit);
    rowActions->addWidget(m_btnStand);
    root->addLayout(rowActions);

    // Log-Ausgabe
    m_log = new QTextEdit(this);
    m_log->setReadOnly(true);
    root->addWidget(m_log);

    setCentralWidget(central);
    resize(420, 420);

    // Socket Signale verbinden
    connect(&m_socket, &QTcpSocket::connected, this, &MainWindow::onConnected);
    connect(&m_socket, &QTcpSocket::readyRead, this, &MainWindow::onReadyRead);
    connect(&m_socket, &QTcpSocket::errorOccurred, this, &MainWindow::onErrorOccurred);

    // Button Signale verbinden
    connect(m_btnCreate, &QPushButton::clicked, this, &MainWindow::onCreateClicked);
    connect(m_btnJoin,   &QPushButton::clicked, this, &MainWindow::onJoinClicked);
    connect(m_btnHit,    &QPushButton::clicked, this, &MainWindow::onHitClicked);
    connect(m_btnStand,  &QPushButton::clicked, this, &MainWindow::onStandClicked);

    // Verbindung zum Server (localhost)
    log("Connecting to 127.0.0.1:4242 ...");
    m_socket.connectToHost("127.0.0.1", 4242);
}

void MainWindow::log(const QString& text)
{
    m_log->append(text);
}

void MainWindow::sendJson(const QJsonObject& obj)
{
    // JSON -> Bytes + '\n'
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    data.append('\n');
    m_socket.write(data);
}

void MainWindow::onConnected()
{
    log("Connected.");
}

void MainWindow::onReadyRead()
{
    // Zeilenweise lesen
    while (m_socket.canReadLine()) {
        QByteArray line = m_socket.readLine().trimmed();
        if (line.isEmpty()) continue;

        // In Log anzeigen
        log("<< " + QString::fromUtf8(line));

        // JSON parsen
        QJsonDocument doc = QJsonDocument::fromJson(line);
        if (!doc.isObject()) continue;

        // Wenn server "created" sendet, gameId eintragen
        QJsonObject obj = doc.object();
        if (obj.value("type").toString() == "created") {
            m_gameIdEdit->setText(obj.value("gameId").toString());
        }
    }
}

void MainWindow::onErrorOccurred(QAbstractSocket::SocketError)
{
    log("Socket error: " + m_socket.errorString());
}

void MainWindow::onCreateClicked()
{
    log(">> create");
    sendJson(QJsonObject{{"type","create"}});
}

void MainWindow::onJoinClicked()
{
    const QString id = m_gameIdEdit->text().trimmed();
    log(">> join " + id);
    sendJson(QJsonObject{{"type","join"},{"gameId",id}});
}

void MainWindow::onHitClicked()
{
    log(">> hit");
    sendJson(QJsonObject{{"type","hit"}});
}

void MainWindow::onStandClicked()
{
    log(">> stand");
    sendJson(QJsonObject{{"type","stand"}});
}
