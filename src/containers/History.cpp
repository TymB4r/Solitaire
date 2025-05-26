//
// Created by tymek on 25.05.2025.
//

#include "History.h"
#include <iostream>
#include <ostream>

void History::update(Position& position) {
    position_snapshot snapshot;
    snapshot.tableau = position.tableau;
    snapshot.foundations = position.foundations;
    snapshot.deck = position.deck;
    snapshot.waste = position.waste;
    snapshot.moves = position.moves;
    snapshot.difficulty = position.difficulty;
    current_max_moves_made = std::max(current_max_moves_made, position.moves);
    history.push_back(snapshot);
}

int History::get_max_moves() const {
    return current_max_moves_made;
}

int History::get_max_undo_depth() const {
    return MAX_UNDO_DEPTH;
}

void History::undo() {
    if (history.size() <= 1) {
        std::cout << "No history available!" << std::endl;
        return;
    }

    history.pop_back();
    board.tableau = history.back().tableau;
    board.foundations = history.back().foundations;
    board.deck = history.back().deck;
    board.waste = history.back().waste;
    board.moves = history.back().moves;
    board.difficulty = history.back().difficulty;
}
