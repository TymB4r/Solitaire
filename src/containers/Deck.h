#ifndef DECK_H
#define DECK_H

#include <map>
#include <optional>
#include <vector>
#include <string>

enum class Suit {DIAMONDS, HEARTS, SPADES, CLUBS, INVALID};
enum class Color {RED, BLACK};

inline std::string suit_to_symbol(Suit suit) {
    switch (suit) {
        case Suit::DIAMONDS: return "\u2666";
        case Suit::HEARTS:   return "\u2665";
        case Suit::SPADES:   return "\u2660";
        case Suit::CLUBS:    return "\u2663";
        default: return "?";
    }
}

inline std::map<int, std::string> value_to_rank = {
    {1, "A"},
    {2, "2"},
    {3, "3"},
    {4, "4"},
    {5, "5"},
    {6, "6"},
    {7, "7"},
    {8, "8"},
    {9, "9"},
    {10, "10"},
    {11, "J"},
    {12, "Q"},
    {13, "K"}
};

class Card {
public:
    Color color;                           // "Red", "Black"
    Suit suit;                             // "Diamonds", "Hearts", "Spades", "Clubs"
    int value;                             // 1: ACE, 2-10, 11-13: J-K
    bool is_face_up = false;               // Store whether a card is currently visible to the player

    Card(Color color, Suit suit, int value)
        : color(color), suit(suit), value(value) {}

    // Return the card’s suit and value as a printable string.
    // If override_face_up is provided, use it to decide whether to show the card; otherwise, use is_face_up.
    [[nodiscard]] std::string print_card(std::optional<bool> override_face_up = std::nullopt) const;
};

class Deck {
public:
    void wipe();                            // Wipe all cards from the current deck
    void create();                          // Create a new deck of 52 cards
    void shuffle();                         // Shuffle the deck randomly
    void print_deck() const;                // Print the current state of the deck in order
    void append_card(const Card& card);     // Append a single card to the back of the deck

    [[nodiscard]] bool is_empty() const;    // Check if the current deck is empty
    [[nodiscard]] int deck_size() const;    // Return deck size
    Card& access_card(int n);               // Access the nth card and allow modifying it
    [[nodiscard]] Card peek(int n) const;   // Peek at the nth card from the top (const since no modification)
    Card deal();                            // Deal the top card and remove it from the deck

private:
    std::vector<Card> cards;
};

#endif // DECK_H
