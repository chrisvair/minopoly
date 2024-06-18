#ifndef GAME_H
#define GAME_H

#include <array>
#include <utility>
#include <__filesystem/operations.h>
#include <iostream>
#include "Property.h"
#include "Board.h"
#include "Player.h"
#include "Property.h"

class Game {
private:
    std::array<Player,4> _players;
    int _nbPlayers = 0;
    int _nbTurns = 20;
    int _bank = 10000;
    int _communityBank = 0;
    Board _board{};
    int _currentPlayer = 1;

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

    void addPlayer(std::string playerName);

    void loadBoard(const std::string& filename);

    void saveBoard(const std::string& filename) const;

    void selectNumberOfPlayers();

    void onLand(Player &player);

    void nextTurn();

    std::array<int,2> rollDice();

    int movePlayer(int amount);

    void build();

    void payTax();

    void payRent();

    void winCommunityChest();

    std::string doActionCard() ;

    int playersBankrupt();

    std::string getWinner();

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

    int getPlayerPosition(int id) {
        return _players[id-1].getPosition();
    }

    void buyProperty() {
        _players[_currentPlayer-1].buyProperty(_board.getTile(_players[_currentPlayer-1].getPosition()));
    }

    int getCurrentPlayer() {
        return _currentPlayer;
    }

    int getTypeProperty(int position) {
        return _board.getTile(position).getType();
    }

    int getOwnerProperty(int id) {
        return _board.getTile(id).owned();
    }

    int getPriceProperty(int id) {
        return _board.getTile(id).price();
    }

    int getHousePrice(int id) {
        return _board.getTile(id).costHouse();
    }

    int getHostelPrice(int id) {
        return _board.getTile(id).costHostel();
    }

    int getPlayerBalance(int id) {
        return _players[id-1].getMoneyAmount();
    }

    std::string getPropertyName(int id) {
        return _board.getTile(id).name();
    }

    std::array<int,6> getPropertyRents(int id) {
        return _board.getTile(id).rents();
    }

    int getPropertyRent(int id) {
        return _board.getTile(id).rent();
    }

    int getNumberhouse(int id) {
        return _board.getTile(id).house();
    }

    int getNumberhostel(int id) {
        return  _board.getTile(id).hostel();
    }

    int getNumberPlayer() {
        return _nbPlayers;
    }

    void goToJail() {
        _players[_currentPlayer-1].goToJail();
    }

    std::string getColor(int position) {
        return _board.getTile(position).group();
    }

    std::string getPlayerName(int id) {
        return _players[id-1].getPlayerName();
    }

    std::string owner(int position){
        return _players[_board.getTile(position).owned()-1].getPlayerName();
    }
};



#endif //GAME_H
