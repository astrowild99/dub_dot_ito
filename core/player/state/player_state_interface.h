//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_PLAYER_STATE_INTERFACE_H
#define DUB_DOT_ITO_PLAYER_STATE_INTERFACE_H

#include <string>

class PlayerStateInterface {
public:
    virtual std::string getStateMessage() = 0;
};

#endif //DUB_DOT_ITO_PLAYER_STATE_INTERFACE_H
