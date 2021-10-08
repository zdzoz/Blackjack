//
//  deck.hpp
//  Blackjack
//
//  Created by Oskar Zdziarski on 10/7/21.
//

#ifndef deck_hpp
#define deck_hpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include "Card.hpp"

class Deck {
    enum suits {clubs, diamonds, hearts, spades};
    std::vector<Card> deck;
public:
    
    Deck();
    
    void shuffle();
    int size();
    void printDeck();
    
};

#endif /* deck_hpp */
