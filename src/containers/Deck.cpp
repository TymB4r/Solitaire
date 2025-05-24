#include "Deck.h"
#include <algorithm>  // for shuffle
#include <iostream>
#include <random>     // for random engines
#include <map>
#include <optional>

#include "../logic/Position.h"

std::string Card::print_card(std::optional<bool> override_face_up) const {
    std::string unicode = suit_to_symbol(suit);
    std::string rank = value_to_rank[value];
    if (rank.size() == 1) {
        rank = " " + rank;
    }

    if (override_face_up.has_value() && override_face_up == true) {
        return rank + unicode;
    }

    
    if (override_face_up.has_value() && override_face_up == false) {
        return " * ";
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

    std::vector suits = {Suit::DIAMONDS, Suit::HEARTS, Suit::SPADES, Suit::CLUBS};
    for (Suit suit : suits) {
        Color color;
        if (suit == Suit::DIAMONDS || suit == Suit::HEARTS) {
            color = Color::RED;
        } else {
            color = Color::BLACK;
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

Card &Deck::access_card(int n) {
    return cards.at(n);
}

Card Deck::peek(int n) {
    return cards[cards.size() - n];
}

Card Deck::deal() {
    Card top_card = cards.back();
    cards.pop_back();
    return top_card;
}
