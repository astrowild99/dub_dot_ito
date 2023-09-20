//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_GAME_H
#define DUB_DOT_ITO_GAME_H

#include <vector>
#include "player/player.h"
#include "command/command.h"
#include "command/queue.h"


/**
 * this is a single instance of a game
 * that is being played
 */
class Game {
private:
    std::vector<Player*> players;
    Player *dealer;

    std::vector<Card*> table;
    std::vector<Card*> burned;

    Queue *command_queue;

public:
    Game(std::vector<Player*> p_players, Player *p_dealer);
    Game(std::vector<Player*> p_players) : Game(p_players, NULL) {};
    ~Game();

    std::vector<Card*> get_table();
    std::vector<Player*> get_players();
    std::vector<Card*> get_burned();

    Player *get_next_player(Player *player);
    Player *get_previous_player(Player *player);

    void append_command(Command *command);
    void next_command();
};


#endif //DUB_DOT_ITO_GAME_H
