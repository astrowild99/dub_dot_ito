//
// Created by donato on 16/09/23.
//

#ifndef DUB_DOT_ITO_GAME_H
#define DUB_DOT_ITO_GAME_H

#include <utility>
#include <vector>
#include "player/player.h"
#include "command/queue.h"

namespace Core {
    class PlayingCards {
    private:
        Player *player;
        std::vector<Card *> cards;

    public:
        PlayingCards(Player *p_player, std::vector<Card *> p_cards);
        void distribute(Player *p_player);

        std::vector<Card*> get_cards();
    };

/**
 * this is a single instance of a game
 * that is being played
 */
    class Game {
    private:
        std::vector<Player *> players;
        Player *dealer;
        Player *currently_playing;

        std::vector<PlayingCards *> table; // the table always keep reference to the player who put the cards
        CardValue currently_declared_value; // the value that the first to be playing declares for the card
        std::vector<Card *> burned;

        Queue *command_queue;
    protected:
        /**
         * executes the command next in the queue and progresses the queue
         * returns false when the command is supposed to stop the game
         *
         * @param p_command
         * @return
         */
        bool dispatch_command(Command *p_command);
    public:
        // region construction
        Game(std::vector<Player *> p_players, Player *p_dealer);
        explicit Game(std::vector<Player *> p_players) : Game(std::move(p_players), NULL) {};

        ~Game();
        // endregion construction

        // region getter
        std::vector<Player *> get_players();
        std::vector<Card *> get_burned();
        std::vector<PlayingCards *> get_table();
        // endregion getter

        // region player flow
        Player *get_next_player(Player *player);

        Player *get_next_player();

        Player *get_previous_player(Player *player);

        void set_current_player(Player *player);

        Player *get_current_player();
        Player *get_dealer(); // this should not change during a game
        // endregion player flow

        // region cards flow

        /**
         * adds playing cards to the stack
         * @param cards
         */
        void play_cards(PlayingCards *cards);

        /**
         * returns the current value declared for the game
         * when starting, or when the table is empty, will be
         * the special null value
         * @return
         */
        CardValue get_currently_declared_value();

        void set_currently_declared_value(CardValue p_value);

        // endregion cards flow

        // region command progress

        /**
         * a player appends a command, that in the next loop will be called
         * @param command
         */
        void append_command(Command *command);

        /**
         * executes the next command in the queue, and progresses the game one
         * step ahead
         * @return
         */
        bool next();

        // endregion command progress
    };

}


#endif //DUB_DOT_ITO_GAME_H
