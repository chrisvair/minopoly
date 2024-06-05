//
// Created by lise babé on 22/05/2024.
//

#ifndef GAME_H
#define GAME_H
#include <array>
#include <utility>

#include "Board.h"
#include "Player.h"
#include "Property.h"
#include "Event.h"


class Game {
private:
    std::array<Player,2> _players;
    int _nbTurns = 6;
    int _bank = 10000;
    int _communityBank = 0;
    Board _board{};

public:
    Game(){}

    Game(const std::array<Player, 2> &players, int nb_turns, int bank, int community_bank, Board board)
        : _players(players),
          _nbTurns(nb_turns),
          _bank(bank),
          _communityBank(community_bank),
          _board(board){
    }

    void start();

    void play();

    void end();

    void nextTurn(Player &player);

    void endTurn();

    std::array<Player,2> & players() {
        return _players;
    }

    int nbPlayers() {
        return _players.size();
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

    void onLand(Player player);
};



#endif //GAME_H
