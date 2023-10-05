#include <iostream>
#include "cli/cli.h"
#include "core/exception/command_exception.h"
#include <cstdio>


int main(int argc, const char **argv) {
    std::cout << "Dub_dot_ito booting..." << std::endl;
#ifdef CLI_ENABLED
    // the cli is the main entry point for the game
    std::cout << "booting the cli" << std::endl;
    auto *cli = new Cli::CliInterface();
    cli->init_game();

    // the cli has a single-thread, input-driven interface where the game
    // loop is run every time a new valid command is written by the user
    bool playing = true;
    Core::Player *playing_player;

    // I am forced to mock this variable to read
    char check[2] = "y";
    std::cout << "ready? [Y/n]" << std::endl;
    std::cin.getline(check, 1);

    while (playing) {
        auto game = cli->get_game();
        playing_player = game->get_current_player();

        cli->present_field();

        playing_player->print_name();
        playing_player->print_cards();

        char command_string[101];
        std::cout << "enter command for player: " << std::endl;
        std::cin.getline(command_string, 100);

        try {
            auto command = cli->create_command(playing_player, std::string(command_string));
            playing = cli->game_loop_advance(command);
        } catch (Core::CommandException &e) {
            std::cout << "The command is invalid: " << e.what() << std::endl;
            continue;
        }
    }
#endif
    return 0;
}
