//
// Created by donato on 28/09/23.
//

#ifndef DUB_DOT_ITO_KILL_GAME_H
#define DUB_DOT_ITO_KILL_GAME_H

#include "command.h"

namespace Core {

    class KillGame : public virtual Command {
    public:
        explicit KillGame(Player *p_player) : Command(p_player) {};

        bool execute(Game *p_game) override;
    };

}

#endif //DUB_DOT_ITO_KILL_GAME_H
