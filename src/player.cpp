//
//  Player.cpp
//  Blackjack
//
//  Created by Oskar Zdziarski on 10/8/21.
//

#include "player.hpp"

Player::Player(Deck& deck, std::string name) {
    this->_name = name;
    this->_deck = &deck;
}

void Player::hit() {
    _hand.push_back(this->_deck->getCard());
}

int Player::handVal() {
    int total = 0;
    bool ace = false;
    
    for (auto card : _hand) {
        if (card.face().val == 1 && ace != true) {
            total += 11;
            ace = true;
        } else {
            total += card.face().val;
        }
    }
    if (ace == true && total > 21)
        total -= 10;
    return total;
}

void Player::clearHand() {
    _hand.clear();
}

void Player::printHand() {
    std::stringstream ss;
    for (auto card : hand()) ss << "┌───────┐  ";
    ss << "\n";
    for (auto card : hand()) ss << "│ " << card.suit().name << "     │  ";
    ss << "\n";
    for (auto card : hand()) ss << "│       │  ";
    ss << "\n";
    for (auto card : hand()) ss << "│   " << card.face().name[0] << "   │  ";
    ss << "\n";
    for (auto card : hand()) ss << "│       │  ";
    ss << "\n";
    for (auto card : hand()) ss << "│     " << card.suit().name << " │  ";
    ss << "\n";
    for (auto card : hand()) ss << "└───────┘  ";
    ss << "\n" << this->_name << ": " << handVal() << "\n\n";
    std::cout << ss.str();
}
