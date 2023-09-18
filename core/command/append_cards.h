//
// Created by donato on 18/09/23.
//

#ifndef DUB_DOT_ITO_APPEND_CARDS_H
#define DUB_DOT_ITO_APPEND_CARDS_H


#include <vector>
#include "command_interface.h"
#include "../card/card.h"

class AppendCards : public CommandInterface {
private:
    std::vector<Card*> cards;
public:

};


#endif //DUB_DOT_ITO_APPEND_CARDS_H
