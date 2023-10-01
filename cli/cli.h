//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_CLI_H
#define DUB_DOT_ITO_CLI_H

#include "../core/game.h"
#include "command_reader.h"

namespace Cli {
    class CliInterface {
        Core::Game *game;
    public:
        void init_game();

        bool game_loop_advance(Core::Command *command);

        void print_screen();

        // region command
        Core::Command *create_command(Core::Player *player, std::string input);

        // endregion command
        Core::Game *get_game();
    };
}


#endif //DUB_DOT_ITO_CLI_H
