//
// Created by donato on 18/09/23.
//

#include "play_cards.h"
#include "../game.h"

using namespace Core;

bool PlayCards::execute(Game *p_game) {
    if (this->cards.size() <= 0) {
        // todo study how to throw exceptions
    }

    // then first I try to retrieve the currently declared value
    auto current_declared_val = p_game->get_currently_declared_value();
    if (current_declared_val == CardValue::null)
        p_game->set_currently_declared_value(this->declared_value);

    // then I create the playing card object to be put on top of the table
    auto playing_cards = new PlayingCards(this->player, this->cards);
    p_game->play_cards(playing_cards);

    // and remove the cards from my hand
    for (Card* c : this->cards) {
        this->player->remove_card(c);
    }
    return true;
}

PlayCards::PlayCards(Player *p_player, std::vector<Card *> p_cards, CardValue p_declared_value) : Command(p_player) {
    this->cards = p_cards;
    this->declared_value = p_declared_value;
}

std::vector<Card *> PlayCards::get_cards() {
    return this->cards;
}

CardValue PlayCards::get_declared_value() {
    return this->declared_value;
}
