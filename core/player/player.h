//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_PLAYER_H
#define DUB_DOT_ITO_PLAYER_H

#include <string>
#include <vector>
#include "../card/card.h"
#include "state/player_state_interface.h"

namespace Core {

    class Player {
    private:
        std::string name;
        std::vector<Card *> cards;
        PlayerStateInterface *state;

    public:
        Player(std::string p_name);

        ~Player();

        void set_cards(std::vector<Card *> p_cards);

        std::vector<Card *> get_cards();

        void append_card(Card *card);

        void print_cards();

        void print_name();

        std::string get_name();
    };

}


#endif //DUB_DOT_ITO_PLAYER_H
