//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_COMMAND_H
#define DUB_DOT_ITO_COMMAND_H

#include "../player/player.h"

namespace Core {
    class Game;
/**
 * the commands hold in themselves the player who executes them
 */
    class Command {
    protected:
        Player *player;
    public:
        /**
         * when false, the command is not terminating so the player should not change
         * if he is the playing one
         * @param p_game
         * @return
         */
        virtual bool execute(Game *p_game) = 0;

        Player *get_player();

        explicit Command(Player *p_player);

        // region debug
        virtual std::vector<Card*> get_cards();
        virtual CardValue get_declared_value();
        // endregion debug
    };

}

#endif //DUB_DOT_ITO_COMMAND_H
