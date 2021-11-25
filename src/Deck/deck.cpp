//
//  deck.cpp
//  Blackjack
//
//  Created by Oskar Zdziarski on 10/7/21.
//

#include "deck.hpp"

Deck::Deck() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
            deck.push_back(Card(i, j+1));
}

void Deck::shuffle() {
    srand((unsigned int) time(nullptr));
    std::vector<Card> temp;
    while (deck.size() > 0) {
        unsigned int r = (unsigned int) (rand() % deck.size());
        temp.push_back(deck.at(r));
        deck.erase(deck.begin() + r);
    }
    deck = temp;
}

Card Deck::getCard() {
    if (deck.size() == 0) {
        std::cout << "Shuffling..\n";
        Deck tempDeck = Deck();
        tempDeck.shuffle();
        deck = tempDeck.deck;
    }
    Card c = deck.back();
    deck.pop_back();
    return c;
}

int Deck::size() {
    return (int) deck.size();
}

void Deck::printDeck() {
    for (auto card : deck)
        card.printCard();
}
