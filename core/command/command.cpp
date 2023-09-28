//
// Created by donato on 20/09/23.
//

#include "command.h"

Player *Command::get_player() {
    return this->player;
}

Command::Command(Player *p_player) {
    this->player = p_player;
}
