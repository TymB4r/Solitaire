#include "Deck.h"
#include "Position.h"
#include <iostream>
#include <windows.h>


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "🂡 Ace of Spades\n";
    std::cout << "10\u2666  J\u2663  Q\u2665  K\u2660\n";
    std::cout << "\u266610  \u2663J  \u2665Q  \u2660K\n";

    Deck deck;
    deck.create();
    deck.shuffle();

    deck.print_deck();
    Position game;
    game.setup();
    std::cout << std::endl << std::endl;
    deck.print_deck();
}
