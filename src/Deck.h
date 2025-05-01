#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <ostream>
#include <vector>
#include <string>


class Card {
public:
    std::string color; // "Red", "Black"
    std::string suit; // "Diamonds", "Hearts", "Spades", "Clubs"
    int value; // 1: ACE, 2-10, 11-13: J-K

    Card(std::string color, std::string suit, int value)
        : color(std::move(color)), suit(std::move(suit)), value(value) {}

    void print_card() const {
        std::cout << color << " " << suit << " " << value << std::endl;
    }
};

class Deck {
public:
    Deck();
    void create();      // Create a new deck of 52 cards
    void shuffle();     // Shuffle the deck randomly
    void print_deck() const; // Print the current state of the deck in order
    Card deal();        // Deal the top card and remove it from the deck

private:
    std::vector<Card> cards;  // Store cards in a vector
};

#endif // DECK_H
