#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QJsonDocument>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // UI aus der .ui-Datei initialisieren
    ui->setupUi(this);

    // Start: immer Lobby anzeigen
    ui->stackedWidget->setCurrentWidget(ui->pageLobby);

    // Lobby -> Join
    connect(ui->btnGoJoin, &QPushButton::clicked, this, [this]{
        ui->stackedWidget->setCurrentWidget(ui->pageJoinRoom);
    });

    // Lobby -> Create
    connect(ui->btnGoCreate, &QPushButton::clicked, this, [this]{
        ui->stackedWidget->setCurrentWidget(ui->pageCreateRoom);
    });
    //Creat-> Join ->GameSimple
    connect(ui->btnCreateRoom, &QPushButton::clicked, this, [this]{
        ui->stackedWidget->setCurrentWidget(ui->pageGameSimple);
        sendJson(QJsonObject{{"type","create"}});
    });
    // CreateRoom -> Back -> Lobby
    connect(ui->btnBackFromCreate, &QPushButton::clicked, this, [this]{
        ui->stackedWidget->setCurrentWidget(ui->pageLobby);
    });

    // JoinRoom -> Back -> Lobby
    connect(ui->btnBackFromJoin, &QPushButton::clicked, this, [this]{
        ui->stackedWidget->setCurrentWidget(ui->pageLobby);
    });

    // GameSimple -> Leave -> Lobby
    connect(ui->btnLeaveGame1, &QPushButton::clicked, this, [this]{
        ui->stackedWidget->setCurrentWidget(ui->pageLobby);
    });

    // GameTable -> Leave -> Lobby
    connect(ui->btnLeaveGame2, &QPushButton::clicked, this, [this]{
        ui->stackedWidget->setCurrentWidget(ui->pageLobby);
    });

    // GameSimple -> Table View
    connect(ui->btnSwitchToTable, &QPushButton::clicked, this, [this]{
        ui->stackedWidget->setCurrentWidget(ui->pageGameTable);
    });

    // GameTable -> Simple View
    connect(ui->btnSwitchToSimple, &QPushButton::clicked, this, [this]{
        ui->stackedWidget->setCurrentWidget(ui->pageGameSimple);
    });
    // JoinRoom -> JoinSelected -> nur wenn eine Zeile ausgewählt ist
    connect(ui->btnJoinSelected, &QPushButton::clicked, this, [this]{
        const int row = ui->tblRooms->currentRow();
        if (row < 0) {
            // Keine Auswahl -> nicht wechseln
            return;
        }

        auto* idItem = ui->tblRooms->item(row, 0);
        if (!idItem) return;

        const QString gameId = idItem->text().trimmed();
        if (gameId.isEmpty()) return;

        ui->stackedWidget->setCurrentWidget(ui->pageGameSimple);
        sendJson(QJsonObject{{"type","join"}, {"gameId", gameId}});
        //gameID in simple zeigen
        ui->lblGameIdSimple->setText(gameId);
        ui->lblGameIdSimple->setText("creating...");


    });
    // ---------- Button-Connects (Page 4: GameSimple) ----------
    connect(ui->btnHit, &QPushButton::clicked, this, &MainWindow::onHitClicked);
    connect(ui->btnStand, &QPushButton::clicked, this, &MainWindow::onStandClicked);
    connect(ui->btnHit, &QPushButton::clicked, this, &MainWindow::onSplitClicked);

    // ---------- Button-Connects (Page 5: GameTable) ----------
    connect(ui->btnHit2, &QPushButton::clicked, this, &MainWindow::onHitClicked);
    connect(ui->btnStand2, &QPushButton::clicked, this, &MainWindow::onStandClicked);
    connect(ui->btnSplit2, &QPushButton::clicked, this, &MainWindow::onSplitClicked);

    connect(ui->btnSwitchToSimple, &QPushButton::clicked, this, [this]{
        ui->stackedWidget->setCurrentWidget(ui->pageGameSimple);
    });

    connect(ui->btnLeaveGame2, &QPushButton::clicked, this, [this]{
        // Zurück-Navigation: hier später auf Lobby/Room wechseln
        ui->stackedWidget->setCurrentWidget(ui->pageCreateRoom);
    });

    // ---------- Socket-Connects ----------
    connect(&m_socket, &QTcpSocket::connected, this, &MainWindow::onConnected);
    connect(&m_socket, &QTcpSocket::readyRead,  this, &MainWindow::onReadyRead);
    connect(&m_socket, &QTcpSocket::errorOccurred, this, &MainWindow::onErrorOccurred);

    // Verbindung zum Server herstellen
    m_socket.connectToHost("127.0.0.1", 4242);
}

MainWindow::~MainWindow()
{
    // UI-Speicher freigeben
    delete ui;
}

void MainWindow::sendJson(const QJsonObject& obj)
{
    // JSON -> Bytes + '\n' (Line-Delimited JSON)
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    data.append('\n');
    m_socket.write(data);
}

void MainWindow::onConnected()
{
    // Verbindung steht
}

void MainWindow::onReadyRead()
{
    while (m_socket.canReadLine()) {
        const QByteArray line = m_socket.readLine().trimmed();
        if (line.isEmpty()) continue;

        const QJsonDocument doc = QJsonDocument::fromJson(line);
        if (!doc.isObject()) continue;

        const QJsonObject obj = doc.object();
        const QString type = obj.value("type").toString();

        // Nach Create/Join zur GameSimple-Seite wechseln
        if (type == "created" || type == "joined") {
            const QString gameId = obj.value("gameId").toString();

            ui->lblGameIdSimple->setText(gameId);
            ui->stackedWidget->setCurrentWidget(ui->pageGameSimple);
            continue;
        }

        // Spielstatus anzeigen (Page 4)
        if (type == "state") {
            const int playerTotal = obj.value("playerTotal").toInt();
            const int dealerTotal = obj.value("dealerTotal").toInt();

            ui->lblPlayerTotalSimple->setText(QString::number(playerTotal));
            ui->lblDealerTotalSimple->setText(QString::number(dealerTotal));

            // Optional: auch Page 5 updaten (falls sichtbar)
            ui->lblSeat1Total->setText(QString::number(playerTotal));
            ui->lblDealerTotalTable->setText(QString::number(dealerTotal));
            continue;
        }

        // Ergebnis
        if (type == "result") {
            // Hier später Ergebnis-Text anzeigen
            continue;
        }

        // Fehler
        if (type == "error") {
            // Hier später Fehlermeldung anzeigen
            continue;
        }
    }
}

void MainWindow::onErrorOccurred(QAbstractSocket::SocketError)
{
    // Fehlerbehandlung
}

void MainWindow::onHitClicked()
{
    sendJson(QJsonObject{{"type","hit"}});
}

void MainWindow::onStandClicked()
{
    sendJson(QJsonObject{{"type","stand"}});
}

void MainWindow::onSplitClicked()
{
    sendJson(QJsonObject{{"type","split"}});
}
