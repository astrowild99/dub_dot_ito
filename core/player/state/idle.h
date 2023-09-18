//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_IDLE_H
#define DUB_DOT_ITO_IDLE_H


#include "player_state_interface.h"

class Idle : public PlayerStateInterface {
public:
    Idle();
    ~Idle();

    std::string getStateMessage();
};


#endif //DUB_DOT_ITO_IDLE_H
