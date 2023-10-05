//
// Created by donato on 16/09/23.
//

#include <iostream>
#include "game.h"
#include "command/queue.h"
#include "exception/command_exception.h"

using namespace Core;

// region playing cards

PlayingCards::PlayingCards(Player *p_player, std::vector<Card *> p_cards) {
    this->player = p_player;
    this->cards = p_cards;
}

std::vector<Card *> PlayingCards::get_cards() {
    return this->cards;
}

bool PlayingCards::check(CardValue expected_value) {
    bool is_same = true;
    CardValue current_value = CardValue::null;
    for (Card *c : this->cards) {
        if (current_value == CardValue::null) {
            current_value = c->get_value();
        } else if (current_value != c->get_value()) {
            is_same = false;
        }
    }

    return is_same && current_value == expected_value;
}

Player *PlayingCards::get_player() {
    return this->player;
}

// endregion playing cards

// region game

Game::Game(std::vector<Player *> p_players, Player *p_dealer) {
    this->command_queue = new Queue();
    this->currently_declared_value = CardValue::null;

    auto card_factory = CardFactory::getSingleton();
    this->players = p_players;
    auto deck = card_factory->createDeck();
    deck = card_factory->shuffleDeck(deck);
    auto decks = card_factory->splitDeck(deck, p_players.size());

    int j = 0;
    for (std::vector<Card*> d : decks) {
        if (j == 0 && !p_dealer)
            p_dealer = p_players.at(j);
        p_players.at(j)->set_cards(d);
        j++;
    }
    this->dealer = p_dealer;
    this->currently_playing = this->get_next_player(this->dealer);
}

Game::~Game() = default;

std::vector<Player *> Game::get_players() {
    return this->players;
}

std::vector<Card *> Game::get_burned() {
    return this->burned;
}

Player *Game::get_next_player(Player *player) {
    int count = (int) this->players.size();
    int position = 0;
    for (int i = 0; i < count; i++) {
        if (this->players.at(i) == player)
            position = i;
    }
    return this->players.at((position + 1) % count);
}

Player *Game::get_previous_player(Player *player) {
    int count = (int) this->players.size();
    int position = 0;
    for (int i = 0; i < count; i++) {
        if (this->players.at(i) == player)
            position = i;
    }
    return this->players.at(abs(position - 1) % count);
}

std::vector<PlayingCards *> Game::get_table() {
    return this->table;
}

void Game::append_command(Command *command) {
    this->command_queue->push(command);
}

Player *Game::get_next_player() {
    return this->get_next_player(this->currently_playing);
}

void Game::set_current_player(Player *player) {
    this->currently_playing = player;
}

Player *Game::get_current_player() {
    return this->currently_playing;
}

bool Game::dispatch_command(Command *p_command) {
    return p_command->execute(this);
}

bool Game::next() {
    auto command = this->command_queue->next();
    try {
        auto move_to_next_player = this->dispatch_command(command);
        if (move_to_next_player)
            this->currently_playing = this->get_next_player();
    } catch (CommandException &e) {
        std::cout << "An exception occurred: " << e.what() << std::endl;
        return false;
    }

    return true; // it is still playing
}

Player *Game::get_dealer() {
    return this->dealer;
}

CardValue Game::get_currently_declared_value() {
    if (this->table.empty())
        return CardValue::null;
    return this->currently_declared_value;
}

void Game::set_currently_declared_value(CardValue p_value) {
    if (!this->table.empty()) {
        return; // you cannot change the declared value when the table is not empty
    }
    if (p_value == CardValue::null) {
        // todo study how to throw exception
    }
    this->currently_declared_value = p_value;
}

void Game::play_cards(
        PlayingCards *cards
    ) {
    this->table.push_back(cards);
}

FieldInfo Game::get_field_info() {
    int count = 0;
    for (PlayingCards *pc : this->table) {
        count += (int) pc->get_cards().size();
    }
    return {
        this->currently_declared_value,
        this->table,
        count
    };
}

PlayingCards *Game::last_played_cards() {
    return this->table.at(this->table.size() - 1);
}

void Game::distribute_cards(Player *p_player) {
    for (auto *playing_cards : this->table) {
        for (auto *card : playing_cards->get_cards()) {
            p_player->append_card(card);
        }
    }
    this->table.clear();
    this->currently_declared_value = CardValue::null;
}

// endregion game