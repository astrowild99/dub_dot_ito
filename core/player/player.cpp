//
// Created by donato on 16/09/23.
//

#include <iostream>
#include "player.h"
#include "state/idle.h"

using namespace Core;

Player::Player(std::string p_name) {
    this->state = new Idle();
    this->cards = {};
    this->name = p_name;
}

Player::~Player() {
    this->state = NULL;
    this->cards.clear();
}

void Player::set_cards(std::vector<Card *> p_cards) {
    this->cards = p_cards;
}

void Player::print_cards() {
    for(Card *c : this->cards) {
        std::cout << "";
        c->print();
        std::cout << ", ";
    }
}

void Player::append_card(Card *card) {
    this->cards.push_back(card);
}

void Player::remove_card(Core::Card *card) {
    for (int i = 0; i < this->cards.size(); i++) {
        auto c = this->cards.at(i);
        if (c == card)
            this->cards.erase(this->cards.begin() + i);
    }
}

std::string Player::get_name() {
    return this->name;
}

void Player::print_name() {
    std::cout << "currently playing: " << this->name << std::endl;
}

std::vector<Card *> Player::get_cards() {
    return this->cards;
}
