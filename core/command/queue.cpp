//
// Created by donato on 16/09/23.
//

#include <stdexcept>
#include "queue.h"

Command *Queue::next() {
    auto command = this->queue.at(this->next_ptr);
    this->next_ptr++;
    return command;
}

Command *Queue::next(Player *p_player) {
    auto player_pointer = this->next_player_ptr.find(p_player);
    if (player_pointer == this->next_player_ptr.end()) {
        return NULL;
    }
    int player_pointer_int = player_pointer->second;
    auto filtered = this->filter_by_player(p_player);
    try {
        auto command = filtered.at(player_pointer_int);
        this->next_player_ptr.at(p_player) += 1;
        return command;
    } catch (std::out_of_range) {
        return NULL;
    }
}

void Queue::push(Command *p_command) {
    this->queue.push_back(p_command);
    this->next_player_ptr.try_emplace(p_command->get_player(), 0);
}

int Queue::get_next_queue_size() {
    return (int)this->queue.size() - this->next_ptr;
}

int Queue::get_next_queue_size(Player *p_player) {
    auto filtered = this->filter_by_player(p_player);
    auto player_pointer = this->next_player_ptr.find(p_player);
    if (player_pointer == this->next_player_ptr.end()) {
        return 0; // the queue is empty for this player
    }

    return (int)filtered.size() - (int)player_pointer->second;
}

std::vector<Command *> Queue::filter_by_player(Player *p_player) {
    std::vector<Command*> to_return;
    for (Command *c : this->queue) {
        if (c->get_player() == p_player) {
            to_return.push_back(c);
        }
    }

    return to_return;
}
