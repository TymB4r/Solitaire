//
// Created by tymek on 16.05.2025.
//

#ifndef RENDERER_H
#define RENDERER_H
#include "../logic/Position.h"

enum class Renderable {
    DIFFICULTY_DIALOGUE, // Render the menu to ask the user to choose the difficulty
    BOARD, // Current board status
    HELP, // Help dialogue
    WINSCREEN // Screen after winning the game
};

class Renderer {
public:
    explicit Renderer(Position& position, Renderable render_type = Renderable::DIFFICULTY_DIALOGUE) : board(position), to_render(render_type) {}

    void render();                                              // Render the current UI state

    void update_render_window(const Renderable& new_state);     // Set what window render() should print

    void render_difficulty_dialogue();                          // Ask the user what difficulty the want to play on

    void render_board();                                        // Render the current board status

    void render_info_screen();                                  // Render the current help dialogue state

    void render_win_screen();                                   // Render the win message

private:
    Position& board;
    Renderable to_render;

    void print_foundations_and_drawn_deck();   // Print the current state of foundations, top deck card and drawn stack

    void print_tableau();                      // Print the current state of the tableau

    std::string get_spaces(int n);             // Return n whitespaces as a string
};
#endif //RENDERER_H
