//
// Created by donato on 20/09/23.
//

#ifndef DUB_DOT_ITO_NO_OP_H
#define DUB_DOT_ITO_NO_OP_H

#include "command.h"

namespace Core {

/**
 * a simple mock command that just does nothing in the execute
 */
    class NoOp : public virtual Command {
    public:
        bool execute(Game *p_game) override;

        explicit NoOp(Player *p_player) : Command(p_player) {};
    };

}

#endif //DUB_DOT_ITO_NO_OP_H
