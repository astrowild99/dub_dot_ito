//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_CARD_H
#define DUB_DOT_ITO_CARD_H

#include <vector>
#include <random>

namespace Core {

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
        jack = 11, // j
        queen = 12, // q
        king = 13, // k
        joker = 14, // j
        null = 99, // used when the table is empty
    };

    enum CardSeed {
        hearths = 1, // H
        clubs = 2, // C
        spades = 3, // S
        diamonds = 4, // D
        no_seed = 14, // J
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

        static std::string print_card_value(CardValue value);
    };

    class CardFactory {
    private:
        inline static CardFactory *singleton = NULL;
        CardFactory();

        // random
        std::default_random_engine random_engine;
    public:
        static CardFactory *getSingleton();

        std::vector<Card *> createDeck();

        std::vector<Card *> shuffleDeck(std::vector<Card *> p_deck);

        std::vector<std::vector<Card *>> splitDeck(std::vector<Card *> p_deck, int p_number_of_decks);
    };

}
#endif //DUB_DOT_ITO_CARD_H
