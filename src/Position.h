//
// Created by tymek on 01.05.2025.
//

#ifndef POSITION_H
#define POSITION_H
#include <array>

#include "Deck.h"

class Position {
public:
    std::array<Deck, 7> tableau; // 7 stacks of cards in the middle
    std::array<Deck, 4> foundations; // 4 stacks of cards at the finish
    Deck deck; // Current deck
    Deck drawn; // Cards drawn from the deck
    int moves = 0; // Counts moves made so far

    void render(); // Print the current state of the game to the console

    void clear_game(); // Reset the board

    void setup(); // Shuffle the Deck and deal the initial cards to the tableau
    /*
    void undo(Move move); // Undo the last move (go back to the previous position)

    bool check_move(Move move); // Check whether the move user is attempting is legal

    void make_move(Move move); // Perform the move on the board and potentially updates visible cards
        // also update current largest stack with each move made
    */
private:
    int largest_stack = 7;
    void print_foundations_drawn_deck();  // Print the current state of foundations, top deck card and drawn stack

    void print_tableau();  // Print the current state of the tableau

    std::string get_spaces(int n); // Return n whitespaces as a string
};


#endif //POSITION_H