//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_CARD_H
#define DUB_DOT_ITO_CARD_H

#include <vector>
#include <random>

enum CardValue {
    one = 1,
    two = 2,
    three = 3,
    four = 4,
    five = 5,
    six = 6,
    seven = 7,
    eight = 8,
    nine = 9,
    ten = 10,
    jack = 11,
    queen = 12,
    king = 13,
    joker = 14
};

enum CardSeed {
    hearths = 1,
    clubs = 2,
    spades = 3,
    diamonds = 4,
    no_seed = 14,
};

class Card {
private:
    CardSeed seed;
    CardValue value;
public:
    Card(CardSeed p_seed, CardValue p_value);
    ~Card();

    void print();
    std::string toString();
};

class CardFactory {
private:
    inline static CardFactory *singleton = NULL;
    CardFactory();

    // random
    std::default_random_engine random_engine;
public:
    static CardFactory *getSingleton();

    std::vector<Card*> createDeck();
    std::vector<Card*> shuffleDeck(std::vector<Card*> p_deck);
    std::vector<std::vector<Card*>> splitDeck(std::vector<Card *> p_deck, int p_number_of_decks);
};

#endif //DUB_DOT_ITO_CARD_H
