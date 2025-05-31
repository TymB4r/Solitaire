#include "GameController.h"
#include "Position.h"
#include "../UI/Renderer.h"
#include "../containers/Move.h"
#include "../containers/History.h"
#include <iostream>

bool Commander::is_running() const {
    return running;
}

void Commander::handle_input() {
    get_command();
    execute(renderer, command, history, input);
}

void Commander::get_command() {
    std::string input_string;
    std::cout << "Command: ";
    std::getline(std::cin, input_string);
    for (char& c : input_string) {
        c = std::toupper(c);
    }

    int first_space_idx = input_string.find_first_of(' ');
    if (position.difficulty == Difficulty::UNSET) {
        command = Command::GET_DIFFICULTY;
        input = input_string;
        return;
    }
    if (first_space_idx == std::string::npos) {
        command = string_to_command(input_string);
    } else {
        std::string command_type_string = input_string.substr(0, first_space_idx);
        command = string_to_command(command_type_string);
        input = input_string.substr(first_space_idx + 1);
    }
}

bool Commander::handle_move(const std::string& move_str) {
    Move move;
    if (!parse_move_command(move_str, move)) return false;
    if (!position.check_move_legality(move)) return false;

    position.apply_move(move);
    return true;
}

void Commander::quit_game() {
    running = false;
}

void Commander::execute(Renderer& renderer, Command& command, History& history, std::string& rest) {
    switch (command) {
        case Command::GET_DIFFICULTY:
            if (position.difficulty != Difficulty::UNSET) {
                std::cout << "The difficulty has already been chosen!" << std::endl;
                break;
            }
            if (rest == "1" or rest == "EASY") {
                position.difficulty = Difficulty::EASY;
                history.update(position);
                renderer.update_render_window(Renderable::BOARD);
            } else if (rest == "2" or rest == "HARD") {
                position.difficulty = Difficulty::HARD;
                history.update(position);
                renderer.update_render_window(Renderable::BOARD);
            } else {
                std::cout << "Wrong command!" << std::endl;
            }
            break;

        case Command::DRAW:
            position.draw_from_deck();
            renderer.update_render_window(Renderable::BOARD);
            history.update(position);
            break;

        case Command::MOVE:
            if (!handle_move(rest)) { // If the move is valid, perform it on position; else return invalid Command type
                std::cout << "Invalid Move!" << std::endl;
                break;
            }
            if (position.check_game()) {
                renderer.update_render_window(Renderable::WINSCREEN);
            } else {
                renderer.update_render_window(Renderable::BOARD);
            }
            history.update(position);
            break;

        case Command::UNDO:
            if (position.moves <= history.get_max_moves() - history.get_max_undo_depth()) {
                std::cout << "Undo limit exceeded!" << std::endl;
                break;
            }
            history.undo();
            renderer.update_render_window(Renderable::BOARD);
            break;

        case Command::RESTART:
            position.restart();
            renderer.update_render_window(Renderable::BOARD);
            break;

        case Command::HELP:
            renderer.update_render_window(Renderable::HELP);
            break;

        case Command::BACK:
            renderer.update_render_window(Renderable::BOARD);
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
