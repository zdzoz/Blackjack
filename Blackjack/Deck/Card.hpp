//
//  Card.hpp
//  Blackjack
//
//  Created by Oskar Zdziarski on 10/7/21.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>

class Card {
    enum suits {clubs, diamonds, hearts, spades};
    struct valStr {
        int val;
        std::string name;
    };
    struct valStr _suit;
    struct valStr _face;
public:
    
    Card(int, int);
    
    const valStr& suit() const { return _suit; }
    const valStr& face() const { return _face; }
};

#endif /* Card_hpp */
