//
//  Card.hpp
//  Blackjack
//
//  Created by Oskar Zdziarski on 10/7/21.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>

class Card {
    int suit;
    int faceVal;
    
public:
    Card(int, int);
    
    int getSuit();
    int getFaceVal();
};

#endif /* Card_hpp */
