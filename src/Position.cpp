//
// Created by tymek on 01.05.2025.
//

#include "Position.h"

void Position::clear_game() {
    for (Deck& stack : tableau) {
        stack.wipe();
    }

    for (Deck& stack : foundations) {
        stack.wipe();
    }
    drawn.wipe();
    deck.wipe();
    moves = 0;
}

void Position::setup() {
    deck.create();
    deck.shuffle();
    for (int i = 0; i < 7; i++) {
        for (int count = 0; count <= i; count++) {
            tableau[i].append_card(deck.deal());
        }
    }
    deck.shuffle();

}
/*
// TODO
bool Position::check_move(Move move) {

}

// TODO
void Position::make_move(Move move) {

}
// TODO
void Position::undo(Move move) {

}

*/