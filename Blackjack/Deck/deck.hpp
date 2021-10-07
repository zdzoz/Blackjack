//
//  deck.hpp
//  Blackjack
//
//  Created by Oskar Zdziarski on 10/7/21.
//

#ifndef deck_hpp
#define deck_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Card.hpp"

class Deck {
    enum suits {clubs, diamonds, hearts, spades};
    const std::string suitName[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    std::map<int, std::string> cardName;
    std::vector<Card> deck;
public:
    
    Deck();
    
    void printDeck();
    
};

#endif /* deck_hpp */
