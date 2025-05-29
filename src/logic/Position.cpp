#include "Position.h"
#include <algorithm>
#include <iostream>

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

int Position::get_largest_stack() {
    int max_height = 0;
    for (Deck& stack : tableau) {
        max_height = std::max(max_height, stack.deck_size());
    }
    return max_height;
}

bool Position::check_move_legality(Move& move) {
    PileType src_type = move.source.type, dst_type = move.destination.type;
    if (!check_pile_existance(move.source)) return false;
    if (!check_pile_existance(move.destination)) return false;
    if (move.destination.type == PileType::WASTE) return false;
    if ((src_type == PileType::WASTE || src_type == PileType::FOUNDATION ||
        dst_type == PileType::FOUNDATION) && move.count != 1) return false;
    if (!check_card_transfer(move)) return false;
    return true;
}

void Position::update_visible_cards() {
    for (Deck& stack : tableau) {
        if (stack.is_empty()) {
            continue;
        }
        stack.access_card(stack.deck_size() - 1).is_face_up = true; // Face the top card up
    }
}

bool Position::check_pile_existance(const Pile& pile) {
    if (pile.type == PileType::WASTE) {
        return pile.index == 1;
    }
    if (pile.type == PileType::TABLEAU) {
        return 1 <= pile.index && pile.index <= 7;
    }
    if (pile.type == PileType::FOUNDATION) {
        return 1 <= pile.index && pile.index <= 4;
    }
    return false;
}

bool Position::check_card_transfer(Move& move) {
    Card src_card = get_deck(move.source).peek(move.count);
    Deck& dstdeck = get_deck(move.destination);
    if (move.destination.type == PileType::WASTE) return false;
    if (move.destination.type == PileType::TABLEAU) {
        if (dstdeck.is_empty()) return src_card.value == 13;
        if (src_card.color == dstdeck.peek(1).color) return false;
        if (src_card.value != dstdeck.peek(1).value - 1) return false;
        if (!src_card.is_face_up) return false;
        return true;
    }
    if (move.destination.type == PileType::FOUNDATION) {
        if (src_card.suit != foundation_to_suit(move.destination.index)) return false;
        if (dstdeck.is_empty()) return src_card.value == 1;
        if (src_card.value != dstdeck.peek(1).value + 1) return false;
        if (!src_card.is_face_up) return false;
        return true;
    }
    return false;
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
    return waste;
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
