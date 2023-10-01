//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_QUEUE_H
#define DUB_DOT_ITO_QUEUE_H


#include <vector>
#include <map>
#include "../player/player.h"

namespace Core {
    class Command;

    class Queue {
    private:
        std::vector<Command*> queue;
        int next_ptr = 0;
        std::map<Player *, int> next_player_ptr;

    protected:
        std::vector<Command*> filter_by_player(Player *p_player);

    public:
        Command *next();

        Command *next(Player *p_player);

        void push(Command *p_command);

        int get_next_queue_size();

        int get_next_queue_size(Player *p_player);
    };

}

#endif //DUB_DOT_ITO_QUEUE_H
