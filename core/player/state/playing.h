//
// Created by donato on 20/09/23.
//

#ifndef DUB_DOT_ITO_PLAYING_H
#define DUB_DOT_ITO_PLAYING_H


#include "player_state_interface.h"

namespace Core {

    class playing : public PlayerStateInterface {
        std::string get_state_message() override;
        std::string available_commands_string() override;
    };
}


#endif //DUB_DOT_ITO_PLAYING_H
