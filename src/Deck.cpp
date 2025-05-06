#include "Deck.h"
#include <algorithm>  // for shuffle
#include <random>     // for random engines
#include <map>
#include <optional>

#include "Position.h"

std::string Card::print_card(std::optional<bool> override_face_up) const {
    std::map<std::string, std::string> suit_to_unicode = {
        {"Diamonds", "\u2666"},
        {"Hearts", "\u2665"},
        {"Spades", "\u2660"},
        {"Clubs", "\u2663"}
    };

    std::map<int, std::string> value_to_rank = {
        {1, "A"},
        {2, "2"},
        {3, "3"},
        {4, "4"},
        {5, "5"},
        {6, "6"},
        {7, "7"},
        {8, "8"},
        {9, "9"},
        {10, "10"},
        {11, "J"},
        {12, "Q"},
        {13, "K"}
    };
    std::string unicode = suit_to_unicode[suit];
    std::string rank = value_to_rank[value];
    if (rank.size() == 1) {
        rank = " " + rank;
    }

    if (override_face_up.has_value() && override_face_up == true) {
        return rank + unicode;
    }

    if (is_face_up) {
        return rank + unicode;
    }
    return " * ";
}

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
        std::cout << card.print_card(true) << std::endl;
    }
}

void Deck::append_card(const Card& card) {
    cards.push_back(card);
}

bool Deck::is_empty() const {
    return cards.empty();
}

int Deck::deck_size() {
    return cards.size();
}

Card Deck::peek(int n) {
    return cards[cards.size() - n];
}

Card Deck::deal() {
    Card top_card = cards.back();
    cards.pop_back();
    return top_card;
}
