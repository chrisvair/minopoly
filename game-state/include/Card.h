#ifndef CARD_H
#define CARD_H

#include <string>
#include <nlohmann/json.hpp>

/**
     * This class represents a card in the game.
     * The action of the card can be to win money, to lose money, to move, to go to jail, to get out of jail or to move according to a number.
     * The action is given by the type :
         * 1 is for winning money
         * 2 is for losing money
         * 3 is for moving
         * 4 is for going to jail
         * 5 is for getting out of jail
         * 6 is for moving according to a number
 **/

using namespace std;
using json = nlohmann::json;

class Card {
private:
    int _id=0;
    int _type=0;
    string _action;
    int _value=0;

public:
    Card()= default; //default constructor

    Card(int id, string action, int value):
        _id(id),
        _action(action),
        _value(value){};

    void from_json(const json& j, Card& card);

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

    void to_json(json& j, const Card& card) const {
        j = json{{"id", card._id}, {"type", card._type}, {"description", card._action}, {"value", card._value}};
    }
};

#endif //CARD_H