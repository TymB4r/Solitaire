#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <optional>
#include <ostream>
#include <vector>
#include <string>


class Card {
public:
    std::string color; // "Red", "Black"
    std::string suit; // "Diamonds", "Hearts", "Spades", "Clubs"
    int value; // 1: ACE, 2-10, 11-13: J-K
    bool is_face_up = false; // Store whether a card is currently visible by the player

    Card(std::string color, std::string suit, int value)
        : color(std::move(color)), suit(std::move(suit)), value(value) {}

    void print_card_parameters() const {
        std::cout << color << " " << suit << " " << value << " " << is_face_up << std::endl;
    }

    // Return the card’s suit and value as a printable string.
    // If override_face_up is provided, use it to decide whether to show the card; otherwise, use is_face_up.
    std::string print_card(std::optional<bool> override_face_up = std::nullopt) const;
};

class Deck {
public:
    void wipe();                             // Wipe all cards from the current deck

    void create();                           // Create a new deck of 52 cards

    void shuffle();                          // Shuffle the deck randomly

    void print_deck() const;                 // Print the current state of the deck in order

    void append_card(const Card& card);      // Append a single card to the back of the deck

    bool is_empty() const;                   // Check if the current deck is empty

    int deck_size();

    Card peek(int n);                        // Peek at the nth card from the top

    Card deal();                             // Deal the top card and remove it from the deck

private:
    std::vector<Card> cards;  // Store cards in a vector
};

#endif // DECK_H
