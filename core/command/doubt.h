//
// Created by donato on 18/09/23.
//

#ifndef DUB_DOT_ITO_DOUBT_H
#define DUB_DOT_ITO_DOUBT_H


#include "command.h"

class Doubt : public Command {
public:
    void execute() override;

    Doubt(Player *p_player) : Command(p_player);
};


#endif //DUB_DOT_ITO_DOUBT_H
