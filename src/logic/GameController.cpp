//
// Created by tymek on 16.05.2025.
//
#include <iostream>
#include "GameController.h"
#include "Position.h"
#include "../UI/Renderer.h"
#include "../containers/Move.h"

bool Commander::is_running() const {
    return running;
}

void Commander::handle_input() {
    get_command();
    execute(renderer, command, input);
}

void Commander::get_command() {
    std::string input_string;
    std::cout << "Command: ";
    std::getline(std::cin, input_string);
    for (char& c : input_string) {
        c = std::toupper(c);
    }

    int first_space_idx = input_string.find_first_of(' ');
    if (first_space_idx == std::string::npos) {
        command = string_to_command(input_string);
    } else {
        std::string command_type_string = input_string.substr(0, first_space_idx);
        command = string_to_command(command_type_string);
        input = input_string.substr(first_space_idx + 1);
    }
}

// In Commander:
bool Commander::handle_move(const std::string& move_str) {
    Move move;
    if (!parse_move_command(move_str, move)) {
        // std::cout << "Invalid move syntax." << std::endl;
        return false;
    }

    if (!position.is_move_valid(move)) {
        // std::cout << "Illegal move." << std::endl;
        return false;
    }

    position.apply_move(move);
    return true;
}

void Commander::quit_game() {
    running = false;
}

void Commander::execute(Renderer& renderer, Command& command, std::string& rest) {
    switch (command) {
        case Command::GET_DIFFICULTY:
            if (rest == "1" or rest == "EASY") {
                position.difficulty = Difficulty::EASY;
                renderer.update_render_window(Renderable::BOARD);
            } else if (rest == "2" or rest == "HARD") {
                position.difficulty = Difficulty::HARD;
                renderer.update_render_window(Renderable::BOARD);
            } else {
                std::cout << "Wrong command!" << std::endl;
            }
            break;

        case Command::DRAW:
            position.draw_from_deck();
            renderer.update_render_window(Renderable::BOARD);
            break;

        case Command::MOVE:
            if (!handle_move(rest)) { // If the move is valid, perform it on position; else return invalid Command type
                Command invalid = Command::INVALID;
                execute(renderer, invalid, rest);
            }
            renderer.update_render_window(Renderable::BOARD);
            break;

        case Command::UNDO:
            position.undo();
            renderer.update_render_window(Renderable::BOARD);
            break;

        case Command::RESTART:
            position.restart();
            renderer.update_render_window(Renderable::BOARD);
            break;

        case Command::HELP:
            renderer.update_render_window(Renderable::HELP);
            // TODO create user information screen
            break;

        case Command::QUIT:
            quit_game();
            break;

        case Command::INVALID:
            std::cout << "Invalid command; please try again" << std::endl;
            break;

        default:
            std::cout << "Input error" << std::endl;
            break;
    }
}
