//
// Created by lise babé on 22/05/2024.
//

#ifndef GAME_H
#define GAME_H
#include <array>
#include <utility>
#include <__filesystem/operations.h>

#include "Board.h"
#include "Player.h"
#include "Property.h"
#include "Event.h"


class Game {
private:
    std::array<Player,4> _players;
    int _nbPlayers;
    int _nbTurns = 20;
    int _bank = 10000;
    int _communityBank = 0;
    Board _board{};
    int _currentPlayer = 0;

public:
    Game(){}

    Game(int nbPlayer, const std::array<Player, 4> &players, int nb_turns, int bank, int community_bank, Board board)
        : _nbPlayers(nbPlayer),
          _players(players),
          _nbTurns(nb_turns),
          _bank(bank),
          _communityBank(community_bank),
          _board(board){
    }

    void start();

    void play();

    void end();

    void nextTurn();

    std::array<Player,4> & players() {
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

    void payToCommunityBank(int amount) {
        _communityBank += amount;
    }

    void emptyCommunityBank() {
        _communityBank = 0;
    }

    Board & board() {
        return _board;
    }



    void loadBoard(const std::string& filename);
    void saveBoard(const std::string& filename) const;
    void onLand(Player &player);
    void selectNumberOfPlayers();

    std::array<int,2> rollDice() {
        srand(time(0));
        return {rand() % 6 + 1, rand() % 6 + 1};
    }

    void addPlayer(std::string playerName) {
        Player player = Player(1,_nbPlayers+1,playerName,1500,0,0);
        _players[_nbPlayers] = player;
        _nbPlayers++;
    }

    int getPlayerPosition(int id) {
        return _players[id-1].getPosition();
    }

    int movePlayer(int id, int amount) {
        _players[id-1].move(amount);
        return _players[id-1].getPosition();
    }

    void buyProperty() {
        _players[_currentPlayer].buyProperty(_board.getTile(_players[_currentPlayer].getPosition()));
    }

    int getCurrentPlayer() {
        return _currentPlayer;
    }

    int getTypeProperty(int position) {
        return _board.getTile(position).getType();
    }

    void buyHouse(int id) {
        _players[_currentPlayer-1].buyHouse(_board.getTile(id));
    }

    void buyHostel(int id) {
        _players[_currentPlayer-1].buyHostel(_board.getTile(id));
    }

};



#endif //GAME_H
