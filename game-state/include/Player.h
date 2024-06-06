//
// Created by lise babé on 22/05/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Property.h"
#include <string>
#include <array>
#include <iostream>
#include "Property.h"
using namespace std;

class Player {
private:
    bool _type; // 0 for human, 1 for bot
    int _id;
    string _name;
    int _money;
    std::array<int, 40> _properties{}; //we stock the id of the properties the player owns, at most, he can have 40 properties
    int _position;
    int _jail;
    //represents the current number of turns the player has been in jail
    //0 if is not, 1 if 1, 2 if 2, 3 if 3, 3-> he can get out of jail
  
    int _getOutOfJailCards; // Number of get out of jail card the player has
    int _moneyWorth;
  




public:
    Player(){}
    Player(int type, int id, string name, int money, int position, bool jail){
        _type = type;
        _id = id;
        _name = name;
        _money = money;
        _position = position;
        _jail = jail;
        _getOutOfJailCards = 0;
        _moneyWorth = money;
    };


    void setPlayerName(string inputName);
    void setMoneyAmount(int inputNum);

    int getMoneyAmount();
    int getPosition();

    void giveMoney(int amount);
    void takeMoney(int amount);
    void move(int amount);

    void reset();

    string getPlayerName(){
        return _name;
    };

    int isInJail() const{
        return _jail;
    };

    void setJail(int jail){
        _jail = jail;
    };

    void goToJail(){
        _position = 10;
        _jail = 1;
    };

    void getOutOfJail(){
        _jail = 0;
    };

    void oneMoreTurnInJail(){
        _jail++;
    };

    int getId() const{
        return _id;
    };


    int getNumberOfGetOutOfJailCard() {
        return _getOutOfJailCards;
    };

    int getMoneyWorth(){
        return _moneyWorth;
    }

    std::array <int, 40> getProperties(){};

    bool sellProperty(Property* property, Player buyer); //return true if the property has been sold, false otherwise
    
    bool sellPropertyToTheBank(Property property); //return true if the property has been sold, false otherwise
    void buyPropertyFromTheBank(Property property); //add the property to the player's properties
    void buyProperty(Property* tile);


    void buyHouse(Property& tile);
    void buyHostel(Property& tile);

    void payTax(int amount);
    void payRent(Player& player, Property& tile);
};



#endif //PLAYER_H
