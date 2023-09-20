//
// Created by donato on 18/09/23.
//

#ifndef DUB_DOT_ITO_PLAY_CARDS_H
#define DUB_DOT_ITO_PLAY_CARDS_H


#include <vector>
#include "command.h"
#include "../card/card.h"

class PlayCards : public Command {
private:
    std::vector<Card*> cards;
public:
    void execute() override;
};


#endif //DUB_DOT_ITO_PLAY_CARDS_H
