//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_PLAYER_H
#define DUB_DOT_ITO_PLAYER_H

#include <string>
#include <vector>
#include "../card/card.h"
#include "state/player_state_interface.h"

class Player {
private:
    std::string name;
    std::vector<Card*> cards;
    PlayerStateInterface *state;

public:
    Player(std::string p_name);
    ~Player();

    void setCards(std::vector<Card*> p_cards);
    void appendCard(Card *card);
    void printCards();

    std::string getName();
};


#endif //DUB_DOT_ITO_PLAYER_H
