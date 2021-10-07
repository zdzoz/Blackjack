//
//  Card.cpp
//  Blackjack
//
//  Created by Oskar Zdziarski on 10/7/21.
//

#include "Card.hpp"

Card::Card(int suit, int faceVal): suit(suit), faceVal(faceVal) {};

int Card::getSuit() {
    return suit;
}

int Card::getFaceVal() {
    return faceVal;
}
