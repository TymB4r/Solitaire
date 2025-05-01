#include "Deck.h"
#include "Position.h"
#include <iostream>
int main()
{
    Deck deck;
    deck.create();
    deck.shuffle();

    deck.print_deck();
    Position game;
    game.setup();
    std::cout << std::endl << std::endl;
    deck.print_deck();
}
