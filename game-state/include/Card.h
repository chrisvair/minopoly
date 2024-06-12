//
// Created by lise babé on 22/05/2024.
//

#ifndef CARD_H
#define CARD_H
#include <string>

using namespace std;

class Card {
private:
    int _id=0;
    // 1 is for winning money
    // 2 is for losing money
    // 3 is for moving
    // 4 is for going to jail
    // 5 is for getting out of jail
    // 6 is for going to the start
    string _action;
    int _value=13;

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

    int value() {
        return _value;
    }
};



#endif //CARD_H
