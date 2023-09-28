//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_GAME_H
#define DUB_DOT_ITO_GAME_H

#include <utility>
#include <vector>
#include "player/player.h"
#include "command/command.h"
#include "command/queue.h"

class PlayingCards {
private:
    Player *player;
    std::vector<Card*> cards;

public:
    PlayingCards(Player *p_player, std::vector<Card*> p_cards);
    void distribute(Player *p_player);
};

/**
 * this is a single instance of a game
 * that is being played
 */
class Game {
private:
    std::vector<Player*> players;
    Player *dealer;
    Player *currently_playing;

    std::vector<PlayingCards*> table;
    std::vector<Card*> burned;

    Queue *command_queue;
public:
    Game(std::vector<Player*> p_players, Player *p_dealer);
    explicit Game(std::vector<Player*> p_players) : Game(std::move(p_players), NULL) {};
    ~Game();

    std::vector<Player*> get_players();
    std::vector<Card*> get_burned();
    std::vector<PlayingCards*> get_table();

    Player *get_next_player(Player *player);
    Player *get_next_player();
    Player *get_previous_player(Player *player);

    void set_current_player(Player *player);
    Player *get_current_player();

    /**
     * a player appends a command, that in the next loop will be called
     * @param command
     */
    void append_command(Command *command);

    /**
     * returns false when the loop is supposed to end
     * @return
     */
    bool loop();
};


#endif //DUB_DOT_ITO_GAME_H
