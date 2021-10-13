//
//  Player.hpp
//  Blackjack
//
//  Created by Oskar Zdziarski on 10/8/21.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include "Deck/card.hpp"
#include "Deck/deck.hpp"

class Player {
    std::string _name;
    std::vector<Card> _hand;
    Deck* _deck;
public:
    Player(Deck&, std::string);
    
    void hit();
    int handVal();
    void clearHand();
    const std::vector<Card>& hand() const { return _hand; }
    void printHand();
};

#endif /* Player_hpp */
