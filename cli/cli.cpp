//
// Created by donato on 16/09/23.
//

#include "cli.h"
#include "../core/command/doubt.h"
#include "../core/command/no_op.h"
#include "../core/command/kill_game.h"
#include <iostream>

void Cli::init_game() {
    std::cout << "Insert number of players " << std::endl;
    int n_pl = 0;
    std::cin >> n_pl;
    std::vector<Player*> players;
    for(int i = 0; i < n_pl; i++) {
        std::cout << "Name: " << std::endl;
        std::string name;
        std::cin >> name;

        auto player = new Player(name);
        players.push_back(player);
    }

    this->game = new Game(players);
    this->game->set_current_player(players[0]);
}

bool Cli::game_loop_advance (Command *p_command) {
    if (this->game == NULL) {
        std::cout << "Game not initialized, exiting" << std::endl;
        throw 1;
    }

    this->game->append_command(p_command);
}

Game *Cli::get_game() {
    return this->game;
}

void Cli::print_screen() {
    // first I print the current player hand
    auto player = this->game->get_current_player();
    player->print_cards();
}

/**
 * d = doubt
 * p(<cards>) = play
 * k = kill game
 *
 * @param player
 * @param input
 * @return
 */
Command *Cli::create_command(Player *player, std::string input) {
    Command *command;
    if (input[0] == 'd') {
        command = new Doubt(player);
    }
    else if (input[0] == 'k') {
        command = new KillGame(player);
    }
    else {
        command = new NoOp(player);
    }
    // todo add more commands

    return command;
}
