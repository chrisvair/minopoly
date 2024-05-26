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
    int _currentPlayer;
    int _nbPlayers;
    int _nbTurns;
    int _bank;
    int _communityBank;
    Board _board;

public:
    void start();
};



#endif //GAME_H
