#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QJsonObject>

#include "gamemanager.h"
#include "hand.h"          // Hand / Card

// Repräsentiert eine Server-Session für GENAU einen Client (ein Socket).
// - liest JSON-Nachrichten (zeilenweise)
// - verarbeitet Befehle (join/bet/hit/stand)
// - sendet Antworten als JSON zurück
class GameSession : public QObject
{
    Q_OBJECT

public:
    // Übernimmt Client-Socket + GameManager (Parent sorgt fürs Aufräumen).
    explicit GameSession(QTcpSocket* socket, GameManager* manager, QObject* parent = nullptr);

private slots:
    // Daten vom Client verfügbar.
    void onReadyRead();

    // Client hat getrennt.
    void onDisconnected();

private:
    // ---- Netzwerk / Verwaltung ----
    QTcpSocket*  m_socket  = nullptr;   // Verbindung zu diesem Client
    GameManager* m_manager = nullptr;   // globale Spielverwaltung

    // ---- Session-Zustand ----
    QString m_gameId;                   // optional: Spiel-ID (falls genutzt)
    bool m_joined     = false;          // Client hat "join" gemacht
    bool m_gameActive = false;          // Runde läuft

    Hand m_playerHand;                 // Karten Spieler
    Hand m_dealerHand;                 // Karten Dealer

    // ---- Parsing / Routing ----
    void handleLine(const QByteArray& line);                         // JSON parsen
    void handleMessage(const QString& type, const QString& gameId);  // Befehl ausführen

    // ---- Antworten ----
    void sendJson(const QJsonObject& obj);  // JSON + '\n' senden
    void sendError(const QString& msg);     // {"type":"error","msg":...}
};

#endif // GAMESESSION_H
