//
// Created by lise babé on 22/05/2024.
//

#ifndef CARD_H
#define CARD_H
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;


class Card {
private:
    int _id=0;
    // 1 is for winning money
    // 2 is for losing money
    // 3 is for moving
    // 4 is for going to jail
    // 5 is for getting out of jail
    // 6 is for going to the start
    int _type=0;
    string _action;
    int _value=0;

public:
    Card()= default; //default constructor

    Card(int id, string action, int value):
        _id(id),
        _action(action),
        _value(value){};

    int getId() {
        return _id;
    }

    string action() {
        return _action;
    }

    int getType() {
        return _type;
    }

    int value() {
        return _value;
    }

    void from_json(const json& j, Card& card) {
        j.at("id").get_to(card._id);
        j.at("type").get_to(card._type);
        j.at("description").get_to(card._action);
        j.at("value").get_to(card._value);
    }
};



#endif //CARD_H
