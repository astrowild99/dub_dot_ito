//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_QUEUE_H
#define DUB_DOT_ITO_QUEUE_H


#include <vector>
#include "command.h"

class Queue {
private:
    std::vector<Command*> queue;
    int next_ptr = 0;

public:
    Command *next();
    void push(Command *p_command);

    int get_next_queue_size();
};


#endif //DUB_DOT_ITO_QUEUE_H
