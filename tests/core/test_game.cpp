//
// Created by donato on 20/09/23.
//

#ifndef DUB_DOT_ITO_TEST_GAME_CPP
#define DUB_DOT_ITO_TEST_GAME_CPP
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../thirdparty/doctest.h"
#include "../../core/game.h"
#include "../../core/player/player.h"
#include "../../core/command/play_cards.h"
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
    CHECK(game->get_currently_declared_value() == CardValue::null);

    // first I check the basic game setup
    auto current_player = game->get_current_player();
    CHECK(current_player == player2);
    auto dealer = game->get_dealer();
    CHECK(dealer == player1);
    auto cards2 = current_player->get_cards();
    // I should have 27 cards
    CHECK(cards2.size() == 27);

    // then I launch the first command
    std::vector<Card*> playing;
    for (int i = 0; i < 2; i++) {
        playing.push_back(cards2.at(i));
    }
    auto play_cards = new PlayCards(player2, playing, CardValue::one);
    game->append_command(play_cards);
    game->next();

    // at this point it should have changed
    CHECK(game->get_current_player() == player1);
    CHECK(game->get_next_player() == player2);
    cards2 = game->get_next_player()->get_cards();
    CHECK(cards2.size() == 25);
    auto table = game->get_table();
    CHECK(table.size() == 1);
    CHECK(table.at(0)->get_cards().size() == 2);
    CHECK(game->get_currently_declared_value() == CardValue::one);
}

TEST_CASE("[core] check cards") {
    std::vector<Card*> cards1;
    auto *c1 = new Core::Card(CardSeed::hearths, CardValue::one);
    cards1.push_back(c1);
    auto *c2 = new Core::Card(CardSeed::clubs, CardValue::one);
    cards1.push_back(c2);
    auto *p = new Player("Donato");
    auto playing_cards = new PlayingCards(p, cards1);

    CHECK (true == playing_cards->check(CardValue::one));
    CHECK (false == playing_cards->check(CardValue::two));

    auto *c3 = new Core::Card(CardSeed::spades, CardValue::two);
    cards1.push_back(c3);

    auto playing_cards_1 = new PlayingCards(p, cards1);

    CHECK (false == playing_cards_1->check(CardValue::one));
}
#endif //DUB_DOT_ITO_TEST_GAME_CPP
