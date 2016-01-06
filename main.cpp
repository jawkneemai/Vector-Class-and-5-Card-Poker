// ITP 365 Fall 2015
// HW5 Vector and Poker Hands
// Name: Tommy Trojan
// Email: ttrojan@usc.edu
// Platform: Windows

#include "console.h"
#include "ITPVector.hpp"
#include "Cards.h"
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Select an option..." << std::endl << "1. Test ITPVector" << std::endl << "2. Poker Hands" << std::endl;
    int option = 0;
    std::cin >> option;
    
    if (option == 1)
    {
        int loopCondition = 0;
        do
        {
            ITPVector<int> testVector;
            std::cout << "Constructing ITPVector of ints!" << std::endl;

            std::cout << "Contents: " << testVector << "Capacity: " << testVector.capacity() << ", Size: " << testVector.size() << std::endl << "Enter number of elements to add: ";
            int input = 0;
            std::cin >> input;
            for (int i = 0; i < input; i++)
            {
                testVector.insert_back(i*5);
            }
            std::cout << "Contents: " << testVector << std::endl << "Capacity: " << testVector.capacity() << ", Size: " << testVector.size() << std::endl << "The back element is: " << testVector.get_back() << std::endl << "Called remove_back" << std::endl;
            testVector.remove_back();
            std::cout << "Contents: " << testVector << std::endl << "Capacity: " << testVector.capacity() << ", Size: " << testVector.size() << std::endl;
            
            // Loop to do it over
            std::cout << "Do you want to make another? (y/n) ";
            std::string condition = "";
            std::cin >> condition;
            if (condition == "n")
            {
                loopCondition = 1;
            }
            else if (condition == "y")
            {
                continue;
            }
            else
            {
                error("Not a valid input!");
            }
        } while (!loopCondition);
    }
    if (option == 2)
    {
        int loopCondition = 0;
        while (!loopCondition)
        {
            std::cout << "Starting a game of poker..." << std::endl;
            
            // Create deck and hand
            ITPVector<Card> deck;
            
            createDeck(deck);
            PokerHand hand(deck);
            std::cout << "You drew: " << hand << std::endl;
            
            // See what you got!
            std::cout << "You got a " << hand.getBestPokerHand() << std::endl;
            
            // Loop to do it over
            std::cout << "Do you want to try again? (y/n) ";
            std::string condition = "";
            std::cin >> condition;
            if (condition == "n")
            {
                loopCondition = 1;
            }
            else if (condition == "y")
            {
                continue;
            }
            else
            {
                error("Not a valid input!");
            }
        }
    }
    return 0;
}
