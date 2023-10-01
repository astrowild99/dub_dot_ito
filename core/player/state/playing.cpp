//
// Created by donato on 20/09/23.
//

#include "playing.h"

using namespace Core;

std::string playing::get_state_message() {
    return "playing";
}

std::string playing::available_commands_string() {
    return "doubt, play_cards";
}
