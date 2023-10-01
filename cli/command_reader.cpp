//
// Created by donato on 01/10/23.
//

#include "command_reader.h"
#include "../core/command/doubt.h"
#include "../core/command/no_op.h"
#include "../core/command/kill_game.h"
#include "../core/command/play_cards.h"

using namespace Cli;

/**
 * @see https://cplusplus.com/articles/2wA0RXSz/
 * @param p_command
 * @param p_needle
 * @return
 */
std::vector<std::string> Cli::CommandReader::explode(const std::string& p_command, const char& p_needle) {
    std::string buff{""};
    std::vector<std::string> v;

    for(auto n:p_command)
    {
        if(n != p_needle) buff+=n; else
        if(n == p_needle && buff != "") { v.push_back(buff); buff = ""; }
    }
    if(buff != "") v.push_back(buff);

    return v;
}

Core::Command *Cli::CommandReader::read(Core::Player *p_player, std::string p_command) {
    Core::Command *command;
    if (p_command[0] == 'd') {
        command = new Core::Doubt(p_player);
    }
    else if (p_command[0] == 'k') {
        command = new Core::KillGame(p_player);
    }
    else if (p_command[0] == 'p') {
        // here I am playing cards, so I take the positional value in my hand based on the submitted command
        auto exploded = Cli::CommandReader::explode(p_command.substr(2), ' ');
        std::vector<int> selected_positions;
        auto declared_value = Core::CardValue::null;
        for (std::string arg : exploded) {
            if (Cli::CommandReader::is_numeric(arg)) {
                selected_positions.push_back(std::stoi(arg));
            }
            else {
                declared_value = Cli::CommandReader::read_card_value(arg);
            }
        }
        if (selected_positions.empty()) {
            // todo see how to handle exceptions
            return new Core::NoOp(p_player);
        }

        // at this point I select the card to play from my deck
        std::vector<Core::Card *> selected_cards;
        auto deck = p_player->get_cards();
        int len = deck.size();
        for (int pos : selected_positions) {
            if (len < pos) continue; // todo see how to handle exceptions
            selected_cards.push_back(deck.at(pos));
        }

        return new Core::PlayCards(p_player, selected_cards, declared_value);
    }
    else {
        command = new Core::NoOp(p_player);
    }
    // todo add more commands

    return command;
}

/**
 * courtesy of https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
 * @param p_argument
 * @return
 */
bool CommandReader::is_numeric(const std::string &p_argument) {
    std::string::const_iterator it = p_argument.begin();
    while (it != p_argument.end() && std::isdigit(*it)) ++it;
    return !p_argument.empty() && it == p_argument.end();
}

Core::CardValue CommandReader::read_card_value(std::string p_card_name) {
    if (p_card_name == "one") {
        return Core::CardValue::one;
    } else if (p_card_name == "two") {
        return Core::CardValue::two;
    } else if (p_card_name == "three") {
        return Core::CardValue::three;
    } else if (p_card_name == "four") {
        return Core::CardValue::four;
    } else if (p_card_name == "five") {
        return Core::CardValue::five;
    } else if (p_card_name == "six") {
        return Core::CardValue::six;
    } else if (p_card_name == "seven") {
        return Core::CardValue::seven;
    } else if (p_card_name == "eight") {
        return Core::CardValue::eight;
    } else if (p_card_name == "nine") {
        return Core::CardValue::nine;
    } else if (p_card_name == "ten") {
        return Core::CardValue::ten;
    } else if (p_card_name == "jack") {
        return Core::CardValue::jack;
    } else if (p_card_name == "queen") {
        return Core::CardValue::queen;
    } else if (p_card_name == "king") {
        return Core::CardValue::king;
    }
    return Core::CardValue::null;
}
