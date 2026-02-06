#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <QVector>

struct Hand {
    QVector<Card> cards;
};

inline int handValue(const Hand& h)
{
    // Ass-Logik: Ass kann 1 oder 11 sein
    int sum = 0;
    int aces = 0;

    for (const Card& c : h.cards) {
        int v = cardValueMin(c);
        sum += v;
        if (c.rank == Rank::Ace) ++aces;
    }

    // Solange es hilft, ein Ass von 1 auf 11 "upgraden"
    while (aces > 0 && sum + 10 <= 21) {
        sum += 10;
        --aces;
    }

    return sum;
}

inline bool isBlackjack(const Hand& h)
{
    // Blackjack = genau 2 Karten und Wert 21
    return h.cards.size() == 2 && handValue(h) == 21;
}

#endif
