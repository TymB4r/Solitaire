#include "containers/Deck.h"
#include "logic/Position.h"
#include "logic/GameController.h"
#include "containers/History.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    try {
        Position game;
        History history(game);
        Renderer UI(game);
        Commander commander(game, UI, history);

        while (commander.is_running()) {
            UI.render();
            commander.handle_input();
        }
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}