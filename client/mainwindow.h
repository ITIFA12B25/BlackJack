#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include<QAbstractSocket>
#include<QJsonObject>
#include<QString>
class QPushButton;
class QLineEdit;
class QTextEdit;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

private:
    // Verbindung zum Server
    QTcpSocket m_socket;

    // UI Elemente
    QPushButton* m_btnCreate = nullptr;
    QPushButton* m_btnJoin = nullptr;
    QPushButton* m_btnHit = nullptr;
    QPushButton* m_btnStand = nullptr;
    QLineEdit*   m_gameIdEdit = nullptr;
    QTextEdit*   m_log = nullptr;

    // Hilfsfunktionen
    void log(const QString& text);
    void sendJson(const QJsonObject& obj);

private slots:
    // Socket-Events
    void onConnected();
    void onReadyRead();
    void onErrorOccurred(QAbstractSocket::SocketError);

    // Button-Events
    void onCreateClicked();
    void onJoinClicked();
    void onHitClicked();
    void onStandClicked();
};

#endif // MAINWINDOW_H
