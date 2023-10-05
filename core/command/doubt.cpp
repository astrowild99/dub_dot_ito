//
// Created by donato on 18/09/23.
//

#include "doubt.h"
#include "../game.h"
#include "../exception/command_exception.h"

using namespace Core;

/**
 * when the player doubts, its playing cards are declared and the outcome is:
 * if they are of the value declared, the one who doubted picks the cards
 * otherwise, is the one who last played
 * @param p_game
 * @return
 */
bool Doubt::execute(Game *p_game) {
    if (!p_game->get_currently_declared_value() || p_game->get_currently_declared_value() == CardValue::null) {
        throw CommandException("You are doubting without a declared value");
    }
    auto last_played = p_game->last_played_cards();
    if (!last_played) {
        throw CommandException("You are doubting on an empty table");
    }
    if (last_played->check(p_game->get_currently_declared_value())) {
        p_game->distribute_cards(this->player);
        return true;
    } else { // the previous was lying
        p_game->distribute_cards(p_game->last_played_cards()->get_player());
        return false; // it is still my turn now
    }
}
