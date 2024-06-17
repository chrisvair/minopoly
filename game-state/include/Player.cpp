//
// Created by lise babé on 22/05/2024.
//

#include "Player.h"


void Player::setPlayerName(string inputName) {
    _name = inputName;
}

void Player::setMoneyAmount(int inputNum) {
    _money = inputNum;
}

string Player::getPlayerName() {
    return _name;
}



int Player::getMoneyAmount() {
    return _money;
}

int Player::getPosition() {
    return _position;
}

void Player::giveMoney(int amount) {
    _money = _money + amount;
}

void Player::takeMoney(int amount) {
    _money = _money - amount;
}

void Player::move(int amount) {
    _position = _position + amount;
}

void Player::reset() {
    _money = 1500;
    _position = 0;
    _jail = false;
}

void reset();