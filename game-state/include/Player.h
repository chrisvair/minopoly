//
// Created by lise babé on 22/05/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <array>
#include "Property.h"
using namespace std;

class Player {
private:
    int _type; //1 if human, 0 if bot
    string _name;
    int _money;
    std::array<int, 40> _properties{}; //we stock the id of the properties the player owns, at most, he can have 40 properties
    int _position;
    int _jail;
    //represents the current number of turns the player has been in jail
    //0 if is not, 1 if 1, 2 if 2, 3 if 3, 3-> he can get out of jail
    int _id;

public:
    Player(){}
    Player(int type, int id, string name, int money, int position, bool jail){
        _type = type;
        _name = name;
        _money = money;
        _position = position;
        _jail = jail;
        _id = id;
    };


    void setPlayerName(string inputName);
    void setMoneyAmount(int inputNum);

    string getPlayerName();
    int getMoneyAmount();
    int getPosition();

    void giveMoney(int amount);
    void takeMoney(int amount);
    void move(int amount);

    void reset();

    int isInJail() const{
        return _jail;
    };

    void setJail(int jail){
        _jail = jail;
    };

    int getId() const{
        return _id;
    };

    void buyProperty(Property property){
        _properties[property.id()] = 1;
    };
};



#endif //PLAYER_H
