//
//  main.cpp
//  Blackjack
//
//  Created by Oskar Zdziarski on 10/7/21.
//
#define LOG(x) std::cout << x << std::endl

#include <iostream>
#include "deck.hpp"
#include "player.hpp"

void clear() {
    for (int i = 0; i < 100; i++)
        std::cout << "\n";
}

int main() {
    Deck x;
    Player p(x);
    Player d(x);
    x.shuffle();
    p.hit();
    p.hit();
    d.hit();
    d.hit();
    clear();
    d.printHand();
    std::cout << "\tWinner\n\n";
    p.printHand();
    
    std::getchar();
    clear();
    
    d.printHand();
    std::cout << "\tLoser\n\n";
    p.printHand();
    
    return 0;
}
