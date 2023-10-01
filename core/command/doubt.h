//
// Created by donato on 18/09/23.
//

#ifndef DUB_DOT_ITO_DOUBT_H
#define DUB_DOT_ITO_DOUBT_H


#include "command.h"

namespace Core {

    class Doubt : public Command {
    public:
        bool execute(Game *p_game) override;

        explicit Doubt(Player *p_player) : Command(p_player) {};
    };

}


#endif //DUB_DOT_ITO_DOUBT_H
