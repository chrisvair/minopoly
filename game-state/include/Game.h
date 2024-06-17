//
// Created by lise babé on 22/05/2024.
//

#ifndef GAME_H
#define GAME_H
#include <array>

#include "Board.h"
#include "Player.h"

class Game {

    Game(int nbPlayers, int nbTurns, int bank, int communityBank, Board board);

private:
    std::array<Player,2> _players;
    int _nbTurns;
    int _bank;
    int _communityBank;
    Board _board;

public:


    void start();

    void Play();

    void end();

    void nextTurn(Player player);

    void endTurn();

    std::array<Player,2> & players() {
        return _players;
    }

    int & currentPlayer() {
        return _currentPlayer;
    }

    int & nbPlayers() {
        return _nbPlayers;
    }

    int & nbTurns() {
        return _nbTurns;
    }

    int & bank() {
        return _bank;
    }

    int & communityBank() {
        return _communityBank;
    }

    Board & board() {
        return _board;
    }
};



#endif //GAME_H
