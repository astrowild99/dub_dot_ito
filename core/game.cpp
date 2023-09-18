//
// Created by donato on 16/09/23.
//

#include "game.h"

Game::Game(std::vector<Player *> p_players, Player *p_dealer) {
    auto card_factory = CardFactory::getSingleton();
    this->players = p_players;
    auto deck = card_factory->createDeck();
    deck = card_factory->shuffleDeck(deck);
    auto decks = card_factory->splitDeck(deck, p_players.size());

    int j = 0;
    for (std::vector<Card*> d : decks) {
        if (j == 0 && !p_dealer)
            p_dealer = p_players.at(j);
        p_players.at(j)->setCards(d);
        j++;
    }
    this->dealer = p_dealer;
}

Game::~Game() = default;