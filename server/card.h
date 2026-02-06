#ifndef CARD_H
#define CARD_H

#include <QString>

enum class Suit { Hearts, Diamonds, Clubs, Spades };
enum class Rank {
    Two=2, Three=3, Four=4, Five=5, Six=6, Seven=7, Eight=8, Nine=9, Ten=10,
    Jack=11, Queen=12, King=13, Ace=14
};

struct Card {
    Suit suit;
    Rank rank;
};

inline int cardValueMin(const Card& c)
{
    // Kartenwert (Ass wird hier als 1 behandelt, flexible Logik kommt in handValue)
    if (c.rank == Rank::Ace) return 1;
    if (c.rank == Rank::Jack || c.rank == Rank::Queen || c.rank == Rank::King) return 10;
    return static_cast<int>(c.rank);
}

inline QString cardToString(const Card& c)
{
    // Kurze Darstellung für Client/Log
    QString r;
    switch (c.rank) {
    case Rank::Ace: r="A"; break;
    case Rank::King: r="K"; break;
    case Rank::Queen: r="Q"; break;
    case Rank::Jack: r="J"; break;
    default: r = QString::number(static_cast<int>(c.rank)); break;
    }

    QString s;
    switch (c.suit) {
    case Suit::Hearts: s="H"; break;
    case Suit::Diamonds: s="D"; break;
    case Suit::Clubs: s="C"; break;
    case Suit::Spades: s="S"; break;
    }

    return r + s; // z.B. "AH", "10S"
}

#endif
