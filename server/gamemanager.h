#ifndef GAMEMANAGER_H

#define GAMEMANAGER_H

#include <QHash>

#include <QString>
#include "deck.h"
#include "hand.h"

// Sehr einfacher Spielzustand (nur Totals für Prototyp).
enum class GamePhase { Waiting, Playing, Finished };
struct GameState {
    Deck deck;
    Hand player;
    Hand dealer;
    GamePhase phase = GamePhase::Waiting;

    bool playerStood = false;
};

class GameManager
{
public:

    GameManager() = default;
    QString createGame();

    // Prüfen, ob gameId existiert.

    bool exists(const QString& gameId) const;

    // Spielzustand holen

    GameState* state(const QString& gameId);

private:

    // Speichert alle Spiele: gameId -> GameState

    QHash<QString, GameState> m_games;

    // Erzeugt eine einfache ID

    QString newId() const;

};

#endif // GAMEMANAGER_H

