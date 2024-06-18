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
        Player player = Player(1,_nbPlayers+1,playerName,500,0,0);
        _players[_nbPlayers] = player;
        _nbPlayers++;
    }

    int getPlayerPosition(int id) {
        return _players[id-1].getPosition();
    }

    int movePlayer(int amount) {
        _players[_currentPlayer-1].move(amount);
        return _players[_currentPlayer-1].getPosition();
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

    void build(int id) {
        if (_board.getTile(id).house() == 4) {
            _players[_currentPlayer-1].buyHostel(_board.getTile(id));
        }
        else {
            _players[_currentPlayer-1].buyHouse(_board.getTile(id));
        }
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

    void payRent(){
        int position = _players[_currentPlayer-1].getPosition();
        _players[_currentPlayer-1].payRent(_players[_board.getTile(position).owned()-1],_board.getTile(position));
    }

    void goToJail() {
        _players[_currentPlayer-1].goToJail();
    }

    void payTax() {
        _players[_currentPlayer-1].payTax(_board.getTile(_players[_currentPlayer-1].getPosition()).price());
        _communityBank += _board.getTile(_players[_currentPlayer-1].getPosition()).price();
    }

    void winCommunityChest() {
        _players[_currentPlayer-1].giveMoney(_communityBank);
        emptyCommunityBank();
    }

    std::string getColor(int position) {
        return _board.getTile(position).group();
    }

    std::string doActionCard() {
        Card newCard = _board.drawCard(rand() % 40);
        _board.doAction(newCard, _players[_currentPlayer-1]);
        return newCard.action();
    }
    std::string getPlayerName(int id) {
        return _players[id-1].getPlayerName();
    }

    std::string owner(int position){
        return _players[_board.getTile(position).owned()-1].getPlayerName();
    }

    int playersBankrupt();

    std::string getWinner();
};



#endif //GAME_H
