//
// Created by donato on 16/09/23.
//

#include "idle.h"

Idle::Idle() = default;

Idle::~Idle() = default;

std::string Idle::getStateMessage() {
    return "Awaiting for my turn";
}