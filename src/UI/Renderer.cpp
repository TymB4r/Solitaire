#include "Renderer.h"
#include <iostream>

void Renderer::render() {
    switch (to_render) {
        case Renderable::DIFFICULTY_DIALOGUE:
            render_difficulty_dialogue();
            break;
        case Renderable::BOARD:
            render_board();
            break;
        case Renderable::HELP:
            render_info_screen();
            break;
        case Renderable::WINSCREEN:
            render_win_screen();
            break;
        default:
            std::cout << "Rendering Error!" << std::endl;
    }
}

void Renderer::update_render_window(const Renderable& new_state) {
    to_render = new_state;
}

void Renderer::render_difficulty_dialogue() {
    std::cout << "What difficulty would you like to play on?" << std::endl;
    std::cout << "1. Easy" << std::endl;
    std::cout << "2. Hard" << std::endl;
}

void Renderer::render_board() {
    std::cout << "Current moves: " << board.moves << get_spaces(10) << "Difficulty: " << difficulty_to_string(board.difficulty) << std::endl;
    print_foundations_and_drawn_deck();
    std::cout << std::endl;
    print_tableau();
}

void Renderer::render_info_screen() {
    std::cout << "\n";
    std::cout << "==================[ HELP MENU ]==================\n";
    std::cout << "\n";
    std::cout << "OBJECTIVE:\n";
    std::cout << "  Move all cards to the four foundations in\n";
    std::cout << "  ascending order (Ace to King, by suit).\n";
    std::cout << "\n";
    std::cout << "TABLEAU RULES:\n";
    std::cout << "  - Cards are built in descending order\n";
    std::cout << "    and alternating colors.\n";
    std::cout << "  - You can only move a King to an empty column.\n";
    std::cout << "\n";
    std::cout << "COMMANDS:\n";
    std::cout << "  MOVE T1 F1 1   -> Move 1 card from Tableau 1 to Foundation 1\n";
    std::cout << "  DRAW           -> Draw from the deck\n";
    std::cout << "  UNDO           -> Undo the last move\n";
    std::cout << "  RESTART        -> Start a new game\n";
    std::cout << "  HELP           -> Show this help screen\n";
    std::cout << "  EXIT           -> Quit the game\n";
    std::cout << "\n";
    std::cout << "NOTATION:\n";
    std::cout << "  T1-T7 -> Tableau columns\n";
    std::cout << "  F1-F4 -> Foundation piles\n";
    std::cout << "  W     -> Waste pile\n";
    std::cout << "\n";
    std::cout << "=================================================\n";
}

void Renderer::render_win_screen() {
    std::cout << "\n\n\n";
    std::cout << "*******************************\n";
    std::cout << "*                             *\n";
    std::cout << "*        YOU WON THE GAME!    *\n";
    std::cout << "*                             *\n";
    std::cout << "*******************************\n\n";
}

void Renderer::print_tableau() {
    std::cout << "Tableau: " << std::endl;
    std::cout << get_spaces(2);
    for (int i = 1; i <= 7; i++) {
        std::cout << i << get_spaces(6);
    }
    std::cout << std::endl;

    for (int i = 0; i < board.get_largest_stack(); i++) {
        for (Deck& stack : board.tableau) {
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

void Renderer::print_foundations_and_drawn_deck() {
    // Print top cards from the foundation stacks
    std::cout << "Foundations:";
    for (Deck& stack : board.foundations) {
        std::string current_foundation = "   ";
        if (!stack.is_empty()) {
            current_foundation = stack.peek(1).print_card();
        }
        std::cout << " [" << current_foundation << "]";
    }

    std::cout << get_spaces(6);

    // Print the top card of the deck face-down, or show nothing if the deck is empty
    std::string top_deck_card = "  ";
    if (!board.deck.is_empty()) {
        top_deck_card = board.deck.peek(1).print_card(false);
    }
    std::cout << "Deck: [" << top_deck_card << "]";

    std::cout << get_spaces(6);

    // Print at most 3 recently drawn cards
    std::cout << "Waste:";
    int printed = 0;
    while (printed < std::min(board.waste.deck_size(), 3)) { // Print at most 3 drawn cardsdi
        std::cout << "[" << board.waste.peek(printed + 1).print_card() << "]";
        printed += 1;
    }
}

std::string Renderer::get_spaces(int spaces_count) {
    return std::string(spaces_count, ' ');
}
