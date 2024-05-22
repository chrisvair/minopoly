//
// Created by lise babé on 22/05/2024.
//

#include "Player.h"

Player::Player() {
    _type = 0;
    _name = "Francis";
    _money = 2500;
    _properties = {};
    _position = 0;
    _jail = false;
}

Player::Player(string inputName, int inputMoney) {
    _type = 0;
    _name = inputName;
    _money = inputMoney;
    _properties = {};
    _position = 0;
    _jail = false;

}
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

void Player::give_money(int amount) {
    _money = _money + amount;
}

void Player::take_money(int amount) {
    _money = _money - amount;
}

void Player::move_player(int amount) {
    _position = _position + amount;
}

void reset();