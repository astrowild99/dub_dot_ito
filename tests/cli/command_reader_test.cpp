//
// Created by donato on 01/10/23.
//

#ifndef DUB_DOT_ITO_TEST_COMMAND_READER_CPP
#define DUB_DOT_ITO_TEST_COMMAND_READER_CPP

#include "../../thirdparty/doctest.h"
#include "../../core/player/player.h"
#include "../../cli/command_reader.h"


using namespace Cli;

TEST_CASE("[cli] test command reader play cards") {
    auto *player = new Core::Player("cici");
    auto deck_factory = Core::CardFactory::getSingleton();
    auto deck = deck_factory->createDeck(); // it will always start with the hearths, it is not shuffled
    player->set_cards(deck);

    std::string input = "p jack 0 1 3 23";
    auto command = Cli::CommandReader::read(player, std::move(input));
    CHECK(command->get_player() == player);
    CHECK(command->get_cards().size() == 4);
    CHECK(command->get_cards().at(0)->toString() == "1 of Hearts");
    CHECK(command->get_cards().at(1)->toString() == "1 of Clubs");
    CHECK(command->get_cards().at(2)->toString() == "1 of Diamonds");
    CHECK(command->get_cards().at(3)->toString() == "6 of Diamonds");
    CHECK(command->get_declared_value() == Core::CardValue::jack);
};

#endif