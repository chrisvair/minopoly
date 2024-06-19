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
    if (_money <= amount) {
        setBankrupt();
        return;
    }
    _money = _money - amount;
    _moneyWorth = _moneyWorth - amount;
}

void Player::move(int amount) {
    _position = _position + amount;
    if (_position >= 40 ) { //if the player has done a full turn
        _position = _position%40; //We reset the position
        _money = _money + 200; //The player gets 200$ for passing by the start
    } else if (_position < 0) {
        _position = 40 + _position;
    }
}

void Player::reset() {
    _money = 1500;
    _position = 0;
    _jail = false;
}

bool Player::sellProperty() {
    showProperties();
    int idProperty;
    std::cin >> idProperty;
    if (_properties[idProperty].id() == _id) {
        _properties[idProperty].isSell();
        _money = _money + _properties[idProperty].price() + _properties[idProperty].house() * _properties[idProperty].costHouse() + _properties[idProperty].hostel() * _properties[idProperty].costHostel();
        _properties[idProperty] = Property{};
        return true;
    }
    return false;
}

void Player::buyProperty(Property& property) {
    property.setOwned(_id);
    takeMoney(property.price());
    _properties[property.getPosition()] = property;
}

void Player::buyPropertyFromTheBank(Property& property) {
    _properties[property.getPosition()] = property;
    property.setOwned(_id);
    takeMoney(property.price());
}

bool Player::sellPropertyToTheBank(Property property) {
    showProperties();
    // int property;
    // std::cin >> property;



    // for (int i = 0; i < 40; i++) {
    //     if (_properties[i].id() == property.id()) {
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
        setBankrupt();
        return;
    }
    _money = _money - amount;
    _moneyWorth = _moneyWorth - amount;
}

void Player::payRent(Player& owner, Property& tile) {
    if (_money < tile.rent()) {
        setBankrupt();
        return;
    }
    takeMoney(tile.rent());
    owner.giveMoney(tile.rent());
}

void Player::showProperties() {
    for (int i = 0; i < 40; i++) {
        if (_properties[i].id() == _id) {
            std::cout << " property number : " << i << " price : " << _properties[i].price() << std::endl;
        }
    }
}

void Player::goToStart(){
    _position = 0;
    _money = _money + 200;
    _moneyWorth = _moneyWorth + 200;
};

void Player::from_json(const nlohmann::json& j, Player& player){
    j.at("type").get_to(player._type);
    if (j.contains("id")){ //if the json contains the id, we get it
        j.at("id").get_to(player._id);
    }
    j.at("name").get_to(player._name);
    j.at("money").get_to(player._money);
    j.at("position").get_to(player._position);
    j.at("jail").get_to(player._jail);

    // Charger les propriétés (le tableau properties)
    if (j.contains("properties")) {
        auto json_properties = j.at("properties");
        for (size_t i = 0; i < _properties.size() && i < json_properties.size(); ++i) {
            Property property;
            property.from_json(json_properties[i], property);
            player._properties[i] = property;
        }
    }
}

void Player::to_json(json& j, const Player& player) const {
    j = json{{"type", player._type},
             {"id", player._id},
             {"name", player._name},
             {"money", player._money},
             {"position", player._position},
             {"jail", player._jail}};
    json properties;
    for (const auto& property : player._properties) {
        json property_json;
        property.to_json(property_json, property);
        properties.push_back(property_json);
    }
    j["properties"] = properties;
}