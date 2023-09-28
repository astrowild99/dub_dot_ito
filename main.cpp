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
    while (playing) {
        std::string command;
    }
#endif
    return 0;
}
