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
    
    cardName = {{1, "Ace"}, {11, "Jack"}, {12, "Queen"}, {13, "King"}};
    for (int i = 2; i < 11; i++)
        cardName[i] = std::to_string(i);
}

void Deck::printDeck() {
    for (auto card : deck)
        std::cout << suitName[card.getSuit()] << " : " << cardName[card.getFaceVal()] << std::endl;
}
