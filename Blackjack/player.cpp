//
//  Player.cpp
//  Blackjack
//
//  Created by Oskar Zdziarski on 10/8/21.
//

#include "player.hpp"

Player::Player(Deck& deck) {
    this->_deck = &deck;
}

void Player::hit() {
    _hand.push_back(this->_deck->getCard());
}

int Player::handVal() {
    int total = 0;
    for (auto card : _hand) total += card.face().val;
    return total;
}

void Player::printHand() {
    std::stringstream ss;
    std::string h = "";
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
    ss << "\nHand Value: " << handVal() << "\n\n";
    std::cout << ss.str();
//    |-----|
//    |     |
//    |  A  |
//    |     |
//    |_____|
}
