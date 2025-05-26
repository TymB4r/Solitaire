//
// Created by tymek on 01.05.2025.
//

#ifndef POSITION_H
#define POSITION_H

#include "../containers/Deck.h"
#include "../containers/Move.h"
#include <array>

enum class Difficulty {
    UNSET, // The difficulty hasn't been set yet
    EASY,  // Draw 1 card from the stack
    HARD   // Draw 3 cards from the stack
};

inline std::string difficulty_to_string(Difficulty difficulty) {
    switch (difficulty) {
        case Difficulty::EASY: return "Easy";
        case Difficulty::HARD: return "Hard";
        default: return "";
    }
}

inline Suit foundation_to_suit(int foundation_index) {
    switch (foundation_index) {
        case 1: return Suit::DIAMONDS;
        case 2: return Suit::HEARTS;
        case 3: return Suit::SPADES;
        case 4: return Suit::CLUBS;
        default: return Suit::INVALID;
    }
}

class Position {
public:
    Position() {
        setup();
    }
    std::array<Deck, 7> tableau;                 // 7 stacks of cards in the middle
    std::array<Deck, 4> foundations;             // 4 stacks of cards at the finish
    Deck deck;                                   // Current deck
    Deck waste;                                  // Cards drawn from the deck
    int moves = 0;                               // Counts moves made so far
    Difficulty difficulty = Difficulty::UNSET;   // Set the default difficulty to easy later to be chosen by the user

    void clear_game();                           // Reset the board
    void setup();                                // Shuffle the Deck and deal the initial cards to the tableau
    void restart();                              // Reset the game to the default position
    bool check_game();                           // Check if all foundations are complete
    int get_largest_stack();                     // Get the height of the largest stack in the tableau
    bool check_move_legality(Move &move);        // Check if the attempted move is legal
    void update_visible_cards();                 // Turn the top cards from the tableau stacks up
                                                 // Draw 1 or 3 cards from the deck depending on the difficulty
    void draw_from_deck();                       // if there are none left, transfer cards from drawn to deck and shuffle
    Deck& get_deck(Pile pile);                   // References the deck to operate on
    void apply_move(const Move& move);           // Perform the move on the current position + save current position in history

private:
    bool check_pile_existance(const Pile& pile); // Check whether the referenced pile's index exists on the board
    bool check_card_transfer(Move &move);        // Check if we can transfer a card/stack of cards from one stack to another
};

#endif //POSITION_H
