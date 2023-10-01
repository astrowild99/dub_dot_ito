//
// Created by donato on 16/09/23.
//

#include "idle.h"

using namespace Core;

Idle::Idle() = default;

Idle::~Idle() = default;

std::string Idle::get_state_message() {
    return "Awaiting for my turn";
}

std::string Idle::available_commands_string() {
    return "";
}
