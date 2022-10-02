//
//  game.cpp
//  Blackjack
//
//  Created by Oskar Zdziarski on 10/11/21.
//

#include "game.hpp"

void game() {
    Deck deck;
    deck.shuffle();
    Player dealer(deck, "Dealer");
    Player player (deck, "Player");
    int winCount = 0;
    int passCount = 0;
    int loseCount = 0;
    char choice;

    while (true) {
        player.clearHand();
        dealer.clearHand();
        bool bj = false;
        clear();
        std::cout << "Play (p), Quit (q)\t\tWin: " << winCount << "\tPass: " << passCount << "\tLose: " << loseCount << "\n";
        std::cin >> choice;
        switch (choice) {
            case 'q':
            case 'Q':
                std::cout << "\nThanks for playing!\n\n";
                return;
                break;
            case 'p':
            case 'P':
                player.hit();
                player.hit();
                dealer.hit();

                do {
                    std::cin.ignore();
                    clear();
                    dealer.printHand();
                    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
                    player.printHand();
                    if (player.handVal() == 21) {bj = true; break;}
                    std::cout << "Hit (h), Stand (s)\n";
                    std::cin >> choice;
                    if (choice == 'h' || choice == 'H') player.hit();
                } while (player.handVal() < 21 && (choice == 'h' || choice == 'H'));

                std::cout << "Press enter key to continue..\n";
                std::cin.ignore();

                do {
                    clear();
                    dealer.printHand();
                    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
                    player.printHand();
                    dealer.hit();
                    if (bj || player.handVal() > 21) break;
                    std::cout << "Press enter key to continue..\n";
                    std::cin.ignore();
                } while (dealer.handVal() < 17);

                clear();

                dealer.printHand();
                std::cout << std::endl << "\t";
                if (player.handVal() > 21) {
                    std::cout << "Player Bust!";
                    loseCount++;
                } else if (dealer.handVal() > 21) {
                    std::cout << "Dealer Bust!";
                    winCount++;
                } else if (player.handVal() == dealer.handVal()) {
                    std::cout << "\tPass!";
                    passCount++;
                } else if (bj) {
                    std::cout << "Blackjack!";
                    winCount++;
                } else if (player.handVal() > dealer.handVal()) {
                    std::cout << "  You Win!";
                    winCount++;
                } else {
                    std::cout << "  You Lose!";
                    loseCount++;
                }
                std::cout << "\n\n\tWin/Pass/Loss\n\t   " << winCount << "/" << passCount << "/" << loseCount << "\n\n";
                std::cout << std::endl;
                player.printHand();
                std::cout << "Press enter key to continue..\n";
                std::cin.ignore();
                break;
            default:
                std::cout << "Invalid input\n\n";
        }
    }
}

void clear() {
    for (int i = 0; i < 100; i++)
        std::cout << "\n";
}
