//
// Created by lise babé on 22/05/2024.
//

#ifndef GAME_H
#define GAME_H
#include <array>
#include <utility>

#include "Board.h"
#include "Player.h"

class Game {
private:
    std::array<Player,2> _players;
    int _nbTurns;
    int _bank;
    int _communityBank;
    //Board _board;

public:
    Game(const std::array<Player, 2> &players, int nb_turns, int bank, int community_bank)
        : _players(players),
          _nbTurns(nb_turns),
          _bank(bank),
          _communityBank(community_bank) {
    }

    void start();

    void Play();

    void end();

    void nextTurn(Player player);

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

    // Board & board() {
    //     return _board;
    // }
};



#endif //GAME_H
