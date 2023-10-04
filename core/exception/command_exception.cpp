//
// Created by donato on 04/10/23.
//

#include "command_exception.h"

namespace Core {
    CommandException::CommandException(std::string p_message) {
        this->message = p_message;
    }

    const char *CommandException::what() {
        return this->message.c_str();
    }
} // Core