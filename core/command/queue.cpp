//
// Created by donato on 16/09/23.
//

#include "queue.h"

Command *Queue::next() {
    auto command = this->queue.at(this->next_ptr);
    this->next_ptr++;
    return command;
}

void Queue::push(Command *p_command) {
    this->queue.push_back(p_command);
}

int Queue::get_next_queue_size() {
    return this->queue.size() - this->next_ptr;
}