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

std::vector<Card *> Game::get_table() {
    return this->table;
}

std::vector<Player *> Game::get_players() {
    return this->players;
}

std::vector<Card *> Game::get_burned() {
    return this->burned;
}

Player *Game::get_next_player(Player *player) {
    int count = (int) this->players.size();
    int position = 0;
    for (int i = 0; i < count; i++) {
        if (this->players.at(i) == player)
            position = i;
    }
    return this->players.at((position + 1) % count);
}

Player *Game::get_previous_player(Player *player) {
    int count = (int) this->players.size();
    int position = 0;
    for (int i = 0; i < count; i++) {
        if (this->players.at(i) == player)
            position = i;
    }
    return this->players.at(abs(position - 1) % count);
}