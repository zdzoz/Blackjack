//
//  Card.cpp
//  Blackjack
//
//  Created by Oskar Zdziarski on 10/7/21.
//

#include "card.hpp"

Card::Card(int suit, int face) {
    switch (suit) {
        case clubs:
            this->_suit = { clubs, "♣" };
            break;
        case diamonds:
            this->_suit = { diamonds, "♦" };
            break;
        case hearts:
            this->_suit = { hearts, "♥" };
            break;
        case spades:
            this->_suit = { spades, "♠" };
            break;
    }
    switch (face) {
        case (1):
            this->_face = { face, "Ace" };
            break;
        case (10):
            this->_face = { face, "Ten" };
            break;
        case (11):
            this->_face = { 10, "Jack" };
            break;
        case (12):
            this->_face = { 10, "Queen" };
            break;
        case (13):
            this->_face = { 10, "King" };
            break;
        default:
            this->_face = { face, std::to_string(face) };
    }
};

void Card::printCard() const {
    std::cout << "┌───────┐\n" <<
        "│ "<< _suit.name << "     │\n" <<
        "│       │\n" <<
        "│   " << _face.name[0] << "   │\n" <<
        "│       │\n" <<
        "│     " << _suit.name << " │\n" <<
        "└───────┘\n\n";
}
