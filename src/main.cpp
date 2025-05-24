#include "containers/Deck.h"
#include "logic/Position.h"
#include "logic/GameController.h"
#include <iostream>
#include <windows.h>




int main()
{

    /*

    std::cout << "🂡 Ace of Spades\n";
    std::cout << "10\u2666  J\u2663  Q\u2665  K\u2660\n";
    std::cout << "\u266610  \u2663J  \u2665Q  \u2660K\n";

    Deck deck;
    deck.create();
    deck.shuffle();

    deck.print_deck();
    */

    SetConsoleOutputCP(CP_UTF8);
    Position game;
    Renderer UI(game);
    Commander commander(game, UI);

    while (commander.is_running()) {
        UI.render();
        commander.handle_input();
    }

}
