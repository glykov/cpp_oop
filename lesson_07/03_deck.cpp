#include <iostream>
#include <algorithm>
#include "03_deck.h"
#include "generic_player.h"

Deck::Deck()
{
    hand.reserve(52);
    populate();
}

Deck::~Deck()
{}

void Deck::populate()
{
    clear();

    for (int s = HEARTS; s <= SPADES; ++s) {
        for (int f = ACE; f <= KING; ++f) {
            add(new Card(s, f))
        }
    }
}

void Deck::shuffle()
{
    std::random_shuffle(hand.begin(), hand.end());
}

void Deck::deal(Hand& a_hand)
{
    if (!hand.empty()) {
        a_hand.add(hand.back());
        hand.pop_back();
    } else {
        std::cout << "No cards left.\n";
    }
}

void Deck::additional_cards(GenericPlayer& gp)
{
    while (!gp.is_boosted() && gp.is_hitting()) {
        deal(gp);
        std::cout << gp << std::endl;
        if (gp.is_boosted()) {
            gp.boost();
        }
    }
}