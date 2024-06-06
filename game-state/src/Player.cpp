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

    if (_position >= 40) { //if the player has done a full turn
        _position = _position - 40; //We reset the position
        _money = _money + 200; //The player gets 200$ for passing by the start
    }
}

void Player::reset() {
    _money = 1500;
    _position = 0;
    _jail = false;
}


// bool Player::sellProperty(Property* property, Player buyer) {
//     int price = property->price();
//     int id = property->getId();
//     for (int i = 0; i < 40; i++) {
//         if (_properties[i] == id) {
//             _properties[i] = 0; //We remove the property from the seller
//             giveMoney(price); // The seller gets the money
//             buyer.takeMoney(price); // The buyer loses the money
//             buyer.buyProperty(id); // The buyer gets the property
//
//             return true; //property sold
//         }
//     }
//     return false; //Player does not own this property
// }

void Player::buyProperty(Property* tile) {
    _properties[tile->getId()] = 1;
    tile->setOwned(_id);
    _money = _money - tile->price();
}

bool Player::sellPropertyToTheBank(Property property) {
    int price = property.price();
    int id = property.getId();
    for (int i = 0; i < 40; i++) {
        if (_properties[i] == id) {
            _properties[i] = 0; //We remove the property from the seller
            giveMoney(price); // The seller gets the money
            return true; //property sold
        }
    }
    return false; //Player does not own this property
}

void Player::buyPropertyFromTheBank(Property property) {
    int id = property.getId();
    for (int i = 0; i < 40; i++) {
        if (_properties[i] == 0) { //First empty slot
            _properties[i] = id; //We add the property to the player's properties
            return;
        }
    }
}

void Player::buyHouse(Property& tile) {
    tile.buyHouse();
    takeMoney(tile.costHouse());
}

void Player::buyHostel(Property& tile) {
    tile.buyHostel();
    takeMoney(tile.costHostel());
}

void Player::payTax(int amount) {
    if (_money < amount) {
        std::cout << "You can't pay the tax" << std::endl;
        if (_moneyWorth > amount) {
            std::cout << "You can sell a property to pay the tax" << std::endl;
        }
    } else {
        std::cout << "we take " << amount << " $$ from your account" << std::endl;
        _money = _money - amount;
        _moneyWorth = _moneyWorth - amount;
    }
}

void Player::payRent(Player& player, Property& tile) {
    if (_money < tile.rent()) {
        std::cout << "You can't pay the rent" << std::endl;
        if (_moneyWorth > tile.rent()) {
            std::cout << "You can sell a property to pay the rent" << std::endl;
        }
    } else {
        std::cout << "we take " << tile.rent() << " $$ from your account" << std::endl;
        _money = _money - tile.rent();
        _moneyWorth = _moneyWorth - tile.rent();
    }
}

void reset();