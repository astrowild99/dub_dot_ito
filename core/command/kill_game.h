//
// Created by donato on 28/09/23.
//

#ifndef DUB_DOT_ITO_KILL_GAME_H
#define DUB_DOT_ITO_KILL_GAME_H

#include "command.h"

class KillGame : public Command {
public:
    explicit KillGame(Player *p_player) : Command(p_player) {};
    void execute();
};


#endif //DUB_DOT_ITO_KILL_GAME_H
