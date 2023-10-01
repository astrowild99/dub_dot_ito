//
// Created by donato on 20/09/23.
//

#include "command.h"

using namespace Core;

Player *Command::get_player() {
    return this->player;
}

Command::Command(Player *p_player) {
    this->player = p_player;
}

std::vector<Card *> Command::get_cards() {
    return {};
}

CardValue Command::get_declared_value() {
    return Core::CardValue::null;
}
