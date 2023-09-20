//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_COMMAND_H
#define DUB_DOT_ITO_COMMAND_H

#include "../player/player.h"

/**
 * the commands hold in themselves the player who executes them
 */
class Command {
protected:
    Player *player;
public:
    virtual void execute() = 0;
    Player *get_player();

    explicit Command(Player *p_player);
};

#endif //DUB_DOT_ITO_COMMAND_H
