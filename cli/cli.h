//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_CLI_H
#define DUB_DOT_ITO_CLI_H

#include "../core/game.h"


class Cli {
    Game *game;
public:
    void init_game();
    bool game_loop_advance(Command *command);

    void print_screen();

    // region command
    Command *create_command(Player *player, std::string input);
    // endregion command
    Game *get_game();
};


#endif //DUB_DOT_ITO_CLI_H
