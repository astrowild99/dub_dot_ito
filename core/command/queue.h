//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_QUEUE_H
#define DUB_DOT_ITO_QUEUE_H


#include <vector>
#include "command_interface.h"

class Queue {
private:
    std::vector<CommandInterface*> queue;
    int next_ptr = 0;

public:
    CommandInterface *next();
    void push(CommandInterface *p_command);
};


#endif //DUB_DOT_ITO_QUEUE_H
