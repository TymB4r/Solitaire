//
// Created by tymek on 16.05.2025.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <string>
#include "Position.h"
#include "../UI/Renderer.h"

enum class Command {
    MOVE, // Move a number of cards between piles
    DRAW, // Take 1 or 3 cards (depending on difficulty) to the Drawn pile
    UNDO, // Undo the current move (up to 3 moves)
    RESTART, // Reset the current position and start again
    HELP, // Bring up command/mechanics tutorial
    QUIT, // Quit the current game and the program
    GET_DIFFICULTY, // Get input difficulty from the user
    INVALID // Case where the input command wasn't anything listed above
};

inline Command string_to_command(const std::string& input) {
    if (input == "MOVE") return Command::MOVE;
    if (input == "DRAW") return Command::DRAW;
    if (input == "UNDO") return Command::UNDO;
    if (input == "RESTART") return Command::RESTART;
    if (input == "HELP") return Command::HELP;
    if (input == "QUIT") return Command::QUIT;
    if (input == "DIFFICULTY") return Command::GET_DIFFICULTY;
    return Command::INVALID;
}

class Commander {
public:
    explicit Commander(Position& game, Renderer& UI) : position(game), command(), renderer(UI) {}

    [[nodiscard]] bool is_running() const; // Check if the game loop should still be going

    void handle_input(); // Combine all logic associated with input handling and execution calls

    void get_command(); // Gather and parse user input

    bool handle_move(const std::string &move_str); // Check formatting and validity -> call make_move on position

    void quit_game(); // Leave the game loop

    void execute(Renderer& renderer, Command& command, std::string& input); // Call the appropriate functions depending on command type

private:
    Position& position; // Include the current position to call methods on
    Command command; // Command type to call
    Renderer& renderer; // Current rendering instance, keep track of what we need to display
    std::string input; // !!! String handled by each function corresponding to command type !!!
    bool running = true; // Check whether the game loop is still running
};

#endif //GAMECONTROLLER_H
