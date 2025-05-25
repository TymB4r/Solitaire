//
// Created by tymek on 01.05.2025.
//

#include <algorithm>
#include <iostream>
#include <ostream>
#include <sstream>
#include "Position.h"


void Position::clear_game() {
    for (Deck& stack : tableau) {
        stack.wipe();
    }

    for (Deck& stack : foundations) {
        stack.wipe();
    }
    waste.wipe();
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
        tableau[i].access_card(i).is_face_up = true; // Turn the top cards up
    }
    deck.shuffle();

}

void Position::restart() {
    clear_game();
    setup();
}

bool Position::check_game() {
    for (Deck& foundation : foundations) {
        if (foundation.deck_size() == 0 || foundation.peek(1).value != 13) { // Return false if any of the top cards is not a King (13)
            return false;
        }
        return true;
    }
    return false; // Default case where there are no foundations yet
}

bool Position::is_move_valid(const Move& move) {\
    // TODO for now allows all moves
    return true;
}

void Position::draw_from_deck() {
    int cards_to_draw = 0;
    if (difficulty == Difficulty::EASY) {
        cards_to_draw = 1;
    } else { // difficulty == Difficulty::HARD
        cards_to_draw = 3;
    }

    if (deck.is_empty()) {
        deck = std::move(waste);
        deck.shuffle();

    }
    for (int i = 0; i < cards_to_draw; i++) {
        deck.access_card(deck.deck_size() - 1).is_face_up = true;
        waste.append_card(deck.deal());
    }
    moves += 1;
}

Deck& Position::get_deck(Pile pile) {
    if (pile.type == PileType::TABLEAU) {
        return tableau[pile.index-1];
    }
    if (pile.type == PileType::FOUNDATION) {
        return foundations[pile.index-1];
    }
    if (pile.type == PileType::WASTE) {
        return waste;
    }
}

void Position::apply_move(const Move& move) {
    Deck& src_stack = get_deck(move.source);
    Deck& dst_stack = get_deck(move.destination);

    Deck cards_to_transfer;
    for (int i = 0; i < move.count; i++) {
        cards_to_transfer.append_card(src_stack.deal());
    }

    for (int i = 0; i < move.count; i++) {
        dst_stack.append_card(cards_to_transfer.deal());
    }

    moves += 1;
    update_visible_cards();

}

void Position::undo() { // TODO
    // PLAN A - keep only the moves and perform them backwards
    // PLAN B - (inefficient) keep the entire board states and call them back into place
}

void Position::update_visible_cards() {
    for (Deck& stack : tableau) {
        if (stack.is_empty()) {
            continue;
        }
        stack.access_card(stack.deck_size() - 1).is_face_up = true; // Face the top card up
    }
}

int Position::get_largest_stack() {
    int max_height = 0;
    for (Deck& stack : tableau) {
        max_height = std::max(max_height, stack.deck_size());
    }
    return max_height;
}