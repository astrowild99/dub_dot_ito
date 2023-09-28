#include <iostream>
#include "cli/cli.h"


int main(int argc, const char **argv) {
    std::cout << "Dub_dot_ito booting..." << std::endl;
#ifdef CLI_ENABLED
    // the cli is the main entry point for the game
    std::cout << "booting the cli" << std::endl;
    Cli *cli = new Cli();
    cli->init_game();

    // the cli has a single-thread, input-driven interface where the game
    // loop is run every time a new valid command is written by the user
    bool playing = true;
    Player *playing_player;
    while (playing) {
        playing_player = cli->get_game()->get_current_player();
        playing_player->printName();
        playing_player->printCards();

        std::string command_string;
        std::cout << "enter command for player" << std::endl;
        std::cin >> command_string;

        auto command = cli->create_command(playing_player, command_string);

        playing = cli->game_loop_advance(command);

        cli->get_game()->set_current_player(cli->get_game()->get_next_player());
    }
#endif
    return 0;
}
