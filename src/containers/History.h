//
// Created by tymek on 25.05.2025.
//

#ifndef METADATA_H
#define METADATA_H
#include "../logic/Position.h"

struct position_snapshot {
    std::array<Deck, 7> tableau; // 7 stacks of cards in the middle
    std::array<Deck, 4> foundations; // 4 stacks of cards at the finish
    Deck deck; // Current deck
    Deck waste; // Cards drawn from the deck
    int moves = 0; // Counts moves made so far
    Difficulty difficulty;
};

class History {
public:
    explicit History(Position& position, int max_undo_depth = 3) : board(position), MAX_UNDO_DEPTH(max_undo_depth) {}

    void update(Position& position); // Update the history by input Position object

    int get_max_moves() const; // Get the maximum moves made regardless of the undo state

    int get_max_undo_depth() const;

    void undo(); // Change the current position to the latest position from history

private:
    int MAX_UNDO_DEPTH; // Default is 3, can be changed by passing a parameter to the constructor
    int current_max_moves_made = 0;
    Position& board;
    std::vector<position_snapshot> history; // Track all game states after each move
};
#endif //METADATA_H
