//
// Created by lise babé on 22/05/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <array>
using namespace std;

class Player {
private:
    int _type; //1 if human, 0 if bot
    string _name;
    int _money;
    std::array<int, 40> _properties; //we stock the id of the properties the player owns, at most, he can have 40 properties
    int _position;
    bool _jail;

public:
    Player();
    Player(int money);

    void setPlayerName(string inputName);
    void setMoneyAmount(int inputNum);

    string getPlayerName();
    int getMoneyAmount();
    int getPosition();

    void give_money(int amount);
    void take_money(int amount);
    void move_player(int amount);

    void reset();

};



#endif //PLAYER_H
