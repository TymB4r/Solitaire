#include "containers/Deck.h"
#include "logic/Position.h"
#include "logic/GameController.h"
#include <iostream>
#include <windows.h>




int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Position game;
    Renderer UI(game);
    Commander commander(game, UI);

    while (commander.is_running()) {
        UI.render();
        commander.handle_input();
    }
}
