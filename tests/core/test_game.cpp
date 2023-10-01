//
// Created by donato on 20/09/23.
//

#ifndef DUB_DOT_ITO_TEST_GAME_CPP
#define DUB_DOT_ITO_TEST_GAME_CPP
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../thirdparty/doctest.h"
#include "../../core/game.h"
#include "../../core/player/player.h"
#include <vector>
#include <string>

using namespace Core;

TEST_CASE("[core] next player") {
    std::string name1 = "cici";
    std::string name2 = "sozio";
    Player *player1 = new Player(name1);
    Player *player2 = new Player(name2);
    std::vector<Player*> players;
    players.push_back(player1);
    players.push_back(player2);
    Game *game = new Game(players);
    CHECK(game->get_next_player(player1) == player2);
    CHECK(game->get_next_player(player2) == player1);
}

TEST_CASE("[core] previous player") {
    std::string name1 = "cici";
    std::string name2 = "sozio";
    Player *player1 = new Player(name1);
    Player *player2 = new Player(name2);
    std::vector<Player*> players;
    players.push_back(player1);
    players.push_back(player2);
    Game *game = new Game(players);
    CHECK(game->get_previous_player(player1) == player2);
    CHECK(game->get_previous_player(player2) == player1);
}

TEST_CASE("[core] first play") {
    Player *player1 = new Player("cici");
    Player *player2 = new Player("sozio");

    std::vector<Player*> players;
    players.push_back(player1);
    players.push_back(player2);

    Game *game = new Game(players);

    // first I check the basic game setup
    auto current_player = game->get_current_player();
    CHECK(current_player == player2);
    auto dealer = game->get_dealer();
    CHECK(dealer == player1);
    auto cards1 = current_player->get_cards();
    // I should have 27 cards
    CHECK(cards1.size() == 27);

    // then I launch the first command
    // todo continue from here
}
#endif //DUB_DOT_ITO_TEST_GAME_CPP
