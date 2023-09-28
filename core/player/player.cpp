//
// Created by donato on 16/09/23.
//

#include <iostream>
#include "player.h"
#include "state/idle.h"

Player::Player(std::string p_name) {
    this->state = new Idle();
    this->cards = {};
    this->name = p_name;
}

Player::~Player() {
    this->state = NULL;
    this->cards.clear();
}

void Player::setCards(std::vector<Card *> p_cards) {
    this->cards = p_cards;
}

void Player::printCards() {
    for(Card *c : this->cards) {
        std::cout << "";
        c->print();
        std::cout << ", ";
    }
}

void Player::appendCard(Card *card) {
    this->cards.push_back(card);
}

std::string Player::getName() {
    return this->name;
}

void Player::printName() {
    std::cout << "currently playing: " << this->name << std::endl;
}
