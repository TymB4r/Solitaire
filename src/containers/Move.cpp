//
// Created by tymek on 24.05.2025.
//

// Move.cpp
#include "Move.h"
#include <string>
#include <cctype>
#include <sstream>
#include <iostream>

Pile Pile::from_string(const std::string& str) {
    if (str.empty()) return {PileType::UNKNOWN, -1};
    char t = std::toupper(str[0]);
    int idx = -1;
    try {
        idx = std::stoi(str.substr(1));
    } catch (...) {
        idx = -1;
    }

    switch (t) {
        case 'T': return {PileType::TABLEAU, idx};
        case 'F': return {PileType::FOUNDATION, idx};
        case 'W': return {PileType::DRAWN, -1};
        // case 'S': return {PileType::STOCK, -1};
        default:  return {PileType::UNKNOWN, -1};
    }
}

bool parse_move_command(const std::string& input, Move& out_move) {
    std::istringstream iss(input);
    std::string src_str, dst_str;
    int count = 1;

    if (!(iss >> src_str >> dst_str)) return false;
    if (!(iss >> count)) count = 1;

    Pile src = Pile::from_string(src_str);
    Pile dst = Pile::from_string(dst_str);

    if (!src.is_valid() || !dst.is_valid() || count < 1) return false;

    out_move = Move{src, dst, count};
    return true;
}
