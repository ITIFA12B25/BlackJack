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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    // Konstruktor für UI (.ui) benutzen
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    // Zugriff auf Widgets aus mainwindow.ui
    Ui::MainWindow *ui;

    // Verbindung zum Server
    QTcpSocket m_socket;

    // Hilfsfunktion: JSON senden
    void sendJson(const QJsonObject& obj);

/*private:
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
    void sendJson(const QJsonObject& obj);*/


private slots:
    // Socket-Events
    void onConnected();
    void onReadyRead();
    void onErrorOccurred(QAbstractSocket::SocketError);

    // Game-Buttons (werden von Page 4 und Page 5 genutzt)
    void onHitClicked();
    void onStandClicked();
    void onSplitClicked();
};

#endif // MAINWINDOW_H
