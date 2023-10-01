//
// Created by donato on 18/09/23.
//

#ifndef DUB_DOT_ITO_PLAY_CARDS_H
#define DUB_DOT_ITO_PLAY_CARDS_H


#include <vector>
#include "command.h"
#include "../card/card.h"

namespace Core {

    class PlayCards : public virtual Command {
    private:
        std::vector<Card *> cards;
        CardValue declared_value;
    public:
        bool execute(Game *p_game) override;

        PlayCards(Player *p_player, std::vector<Card *> p_cards, CardValue p_declared_value);
        explicit PlayCards(Player *p_player, std::vector<Card *> p_cards) : PlayCards(p_player, std::move(p_cards), CardValue::null) {};
    };

}

#endif //DUB_DOT_ITO_PLAY_CARDS_H
