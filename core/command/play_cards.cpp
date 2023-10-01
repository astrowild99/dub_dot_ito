//
// Created by donato on 18/09/23.
//

#include "play_cards.h"

using namespace Core;

bool PlayCards::execute(Game *p_game) {
    return true;
}

PlayCards::PlayCards(Player *p_player, std::vector<Card *> p_cards) : Command(p_player) {
    this->cards = p_cards;
}
