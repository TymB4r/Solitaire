//
// Created by tymek on 24.05.2025.
//

#ifndef MOVE_H
#define MOVE_H
#include <string>

enum class PileType {
    TABLEAU,
    FOUNDATION,
    WASTE,
    //STOCK, // Not necessary as already handled by DRAW command, worth keeping for future-proofing
    UNKNOWN
};

struct Pile {
    PileType type;
    int index;

    static Pile from_string(const std::string& str);

    bool is_valid() const {
        if (type == PileType::UNKNOWN) return false;
        if ((type == PileType::TABLEAU || type == PileType::FOUNDATION) && index < 1) return false;
        return true;
    }
};

struct Move {
    Pile source;
    Pile destination;
    int count;
};

bool parse_move_command(const std::string& input, Move& out_move);
#endif //MOVE_H
