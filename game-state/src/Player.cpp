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
    _moneyWorth = _moneyWorth + amount;
}

void Player::takeMoney(int amount) {
    _money = _money - amount;
    _moneyWorth = _moneyWorth - amount;
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

void Player::buyProperty(Property& property) {
    std::string answer;
    std::cout << "This property is not owned" << std::endl;
    if (_money >= property.price()) {
        std::cout << "Do you want to buy the property, it costs " << property.price() << " $$ ? (y/n)" << std::endl;
        std::cin >> answer;
        if (answer == "y") {
            std::cout << "You buy the property" << std::endl;
            _properties[property.getId()] = property;
            property.setOwned(_id);
            takeMoney(property.price());
        } else if (answer == "n"){
            std::cout << "You don't buy the property" << std::endl;
        }
        return;
    }
    std::cout << "You don't have enough money to buy the property" << std::endl;
}

void Player::buyPropertyFromTheBank(Property& property) {
    _properties[property.getId()] = property;
    property.setOwned(_id);
    takeMoney(property.price());
}

bool Player::sellPropertyToTheBank(Property property) {
    showProperties();
    std::cout << "Which property do you want to sell ?" << std::endl;
    // int property;
    // std::cin >> property;



    // for (int i = 0; i < 40; i++) {
    //     if (_properties[i].getId() == property.getId()) {
    //         _properties[i] = 0; //We remove the property from the seller
    //         giveMoney(property.price()); // The seller gets the money
    //         return true; //property sold
    //     }
    // }
    return false; //Player does not own this property
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
            //sellPropertyToTheBank();
        }
        setBankrupt();
        return;
    }
    std::cout << "we take " << amount << " $$ from your account" << std::endl;
    _money = _money - amount;
    _moneyWorth = _moneyWorth - amount;
}

void Player::payRent(Player& player, Property& tile) {
    std::cout << "This property is owned, you have to pay a rent" << std::endl;
    std::cout << "The rent is " << tile.rents()[tile.house()] << " $$" << std::endl;
    if (_money < tile.rents()[tile.house()]) {
        std::cout << "You can't pay the rent" << std::endl;
        if (_moneyWorth > tile.rent()) {
            std::cout << "You can sell a property to pay the rent" << std::endl;
            // TODO : implement sellProperty
        }
        player.setBankrupt();
        return;
    }
    std::cout << "We take " << tile.rent() << " $$ from your account" << std::endl;
    _money = _money - tile.rent();
    _moneyWorth = _moneyWorth - tile.rent();
    player.giveMoney(tile.rent());
}

void reset();

void Player::showProperties() {
    std::cout << "Your properties are : " << std::endl;
    for (int i = 0; i < 40; i++) {
        if (_properties[i].getId() == _id) {
            std::cout << " property number : " << i << " price : " << _properties[i].price() << std::endl;
        }
    }
}