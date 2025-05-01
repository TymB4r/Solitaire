#include "Deck.h"
#include <algorithm>  // for shuffle
#include <random>     // for random engines


void Deck::wipe() {
    cards.clear();
}

void Deck::create() {
    cards.clear();

    std::vector<std::string> suits = {"Diamonds", "Hearts", "Spades", "Clubs"};
    for (const std::string& suit: suits) {
        std::string color;
        if (suit == "Diamonds" || suit == "Hearts") {
            color = "Red";
        } else {
            color = "Black";
        }

        for (int i = 1; i < 14; i++) {
            cards.emplace_back(color, suit, i);
        }
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::ranges::shuffle(cards, rng);
}

void Deck::print_deck() const {
    for (const auto& card : cards) {
        std::cout << card.color << " " << card.suit << " " << card.value << std::endl;
    }
}

void Deck::append_card(const Card& card) {
    cards.push_back(card);
}

Card Deck::deal() {
    Card top_card = cards.back();
    cards.pop_back();
    return top_card;
}
