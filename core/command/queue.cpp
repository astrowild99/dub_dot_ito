//
// Created by donato on 16/09/23.
//

#include "queue.h"

CommandInterface *Queue::next() {
    auto command = this->queue.at(this->next_ptr);
    this->next_ptr++;
    return command;
}

void Queue::push(CommandInterface *p_command) {
    this->queue.push_back(p_command);
}