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

void Position::render() {
    std::cout << "Current moves: " << moves << std::endl;
    print_foundations_drawn_deck();
    std::cout << std::endl;
    print_tableau();

}

void Position::print_tableau() {
    std::cout << "Tableau: " << std::endl;
    std::cout << get_spaces(2);
    for (int i = 1; i <= 7; i++) {
        std::cout << i << get_spaces(6);
    }
    std::cout << std::endl;
    for (int i = 0; i < largest_stack; i++) {
        for (Deck& stack : tableau) {
            std::string card = get_spaces(3);
            int stack_size = stack.deck_size();
            if (i < stack_size) {
                card = stack.peek(stack_size - i).print_card();
                std::cout << "[" << card << "]";
            } else {
                std::cout << get_spaces(5); // 5 whitespaces to pad the same size as 1 card printed would
            }
            std::cout << get_spaces(2);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Position::print_foundations_drawn_deck() {
    // Print top cards from the foundation stacks
    std::cout << "Foundations:";
    for (Deck& stack : foundations) {
        std::string current_foundation = "   ";
        if (!stack.is_empty()) {
            current_foundation = stack.peek(1).print_card();
        }
        std::cout << " [" << current_foundation << "]";
    }

    std::cout << get_spaces(6);

    // Print the top card of the deck face-down, or show nothing if the deck is empty
    std::string top_deck_card = "  ";
    if (!deck.is_empty()) {
        top_deck_card = deck.peek(1).print_card();
    }
    std::cout << "Deck: [" << top_deck_card << "]";

    std::cout << get_spaces(6);

    // Print at most 3 recently drawn cards
    std::cout << "Drawn:";
    int printed = 0;
    while (!drawn.is_empty() && printed < 3) {
        std::cout << "[" << drawn.peek(printed + 1).print_card() << "]";
        printed += 1;
    }
}

std::string Position::get_spaces(int spaces_count) {
    return std::string(spaces_count, ' ');
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