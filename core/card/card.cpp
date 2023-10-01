//
// Created by donato on 16/09/23.
//

#include "card.h"
#include <algorithm>
#include <random>
#include <iostream>

using namespace Core;

// region card

Card::Card(CardSeed p_seed, CardValue p_value) {
    this->seed = p_seed;
    this->value = p_value;
}

Card::~Card() = default;

std::string Card::toString() {
    std::string p_value;
    switch (this->value) {
        case CardValue::jack:
            p_value = "J";
            break;
        case CardValue::queen:
            p_value = "Q";
            break;
        case CardValue::king:
            p_value = "K";
            break;
        case CardValue::joker:
            p_value = "JOKER";
            break;
        default:
            p_value = std::to_string((int) this->value);
            break;
    }
    std::string p_seed;
    switch (this->seed) {
        case CardSeed::clubs:
            p_seed = "of Clubs";
            break;
        case CardSeed::spades:
            p_seed = "of Spades";
            break;
        case CardSeed::hearths:
            p_seed = "of Hearts";
            break;
        case CardSeed::diamonds:
            p_seed = "of Diamonds";
            break;
        default:
            p_seed = "";
            break;
    }
    return "" + p_value + " " + p_seed;
}

void Card::print() {
    std::cout << this->toString();
}

// endregion card

// region factory

std::vector<Card *> CardFactory::createDeck() {
    std::vector<Card*> deck;
    for (int value = 1; value <= 13; value++) {
        for (int seed = 1; seed <= 4; seed++) {
            Card *card = new Card((CardSeed) seed, (CardValue) value);
            deck.push_back(card);
        }
    }
    Card *red_joker = new Card(CardSeed::no_seed, CardValue::joker);
    deck.push_back(red_joker);
    Card *black_joker = new Card(CardSeed::no_seed, CardValue::joker);
    deck.push_back(black_joker);

    return deck;
}

std::vector<Card *> CardFactory::shuffleDeck(std::vector<Card *> p_deck) {
    std::shuffle(p_deck.begin(), p_deck.end(), this->random_engine);
    return p_deck;
}

std::vector<std::vector<Card *>> CardFactory::splitDeck(std::vector<Card *> p_deck, int p_number_of_decks) {
    std::vector<std::vector<Card*>> vector;
    for (int i = 0; i < p_number_of_decks; i++) {
        std::vector<Card*> deck;
        vector.push_back(deck);
    }
    int j = 0;
    for (Card *card: p_deck) {
        int offset = j % p_number_of_decks;
        vector.at(offset).push_back(card);
        j++;
    }

    return vector;
}

CardFactory::CardFactory() {
    auto rd = std::random_device {};
    this->random_engine = std::default_random_engine { rd() };

    CardFactory::singleton = NULL;
}

CardFactory *CardFactory::getSingleton() {
    if (!CardFactory::singleton) {
        CardFactory::singleton = new CardFactory();
    }
    return CardFactory::singleton;
}

// endregion factory
