//
// Created by donato on 16/09/23.
//

#include "cli.h"
#include "command_reader.h"
#include <iostream>

void Cli::CliInterface::init_game() {
    std::cout << "Insert number of players " << std::endl;
    int n_pl = 0;
    std::cin >> n_pl;
    std::vector<Core::Player*> players;
    for(int i = 0; i < n_pl; i++) {
        std::cout << "Name: " << std::endl;
        std::string name;
        std::cin >> name;

        auto player = new Core::Player(name);
        players.push_back(player);
    }

    this->game = new Core::Game(players);
    this->game->set_current_player(players[0]);
}

bool Cli::CliInterface::game_loop_advance (Core::Command *p_command) {
    if (this->game == NULL) {
        std::cout << "Game not initialized, exiting" << std::endl;
        throw 1;
    }

    this->game->append_command(p_command);
    this->game->next(); // in the cli, I have one event at the time and I can progress
    return true;
}

Core::Game *Cli::CliInterface::get_game() {
    return this->game;
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
Core::Command *Cli::CliInterface::create_command(Core::Player *player, std::string input) {
    return Cli::CommandReader::read(player, input);
}

void Cli::CliInterface::present_field() {
    auto field_info = this->game->get_field_info();
    if (field_info.table.empty()) {
        std::cout << "The table is empty, pick your card with command p <card_name> <index of card> <...>" << std::endl;
    }
    else {
        std::cout << "The table is of card: " << Core::Card::print_card_value(field_info.currently_declared_value) << std::endl;
        std::cout << "There are currently " << field_info.table_size << " cards" << std::endl;
    }
}
