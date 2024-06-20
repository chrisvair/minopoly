#include "../src/Game.h"

void Game::nextTurn() {
    _currentPlayer++;
    if (_currentPlayer == _nbPlayers + 1) {
        _currentPlayer = 1;
        _nbTurns--;
    }
    if (_nbTurns == 0) {
        _currentPlayer = -1;
        return;
    }
    if (playersBankrupt() == _nbPlayers - 1) {
        _currentPlayer = -2;
        return;
    }
    Player& player = _players[_currentPlayer-1];
    //if in jail we check if you can get out of it
    if (player.isBankrupt()) {
        nextTurn();
    }
    if (player.isInJail() == 3) {
        player.getOutOfJail();
        nextTurn();
    } else if(player.isInJail()!=0) {
        player.oneMoreTurnInJail();
        nextTurn();
    }
}

int Game::playersBankrupt(){
    int nbPlayerBanrkurpt = 0;
    for (int i = 0; i < _players.size(); i++) {
        if (_players[i].isBankrupt()) {
            nbPlayerBanrkurpt++;
        }
    }
    return nbPlayerBanrkurpt;
}

std::string Game::getWinner() {
    for (int i = 0; i < _players.size(); i++) {
        if (!_players[i].isBankrupt()) {
            return _players[i].getPlayerName();
        }
    }
    return "Personne n'";
}

std::array<int,2> Game::rollDice() {
    srand(time(0));
    return {rand() % 6 + 1, rand() % 6 + 1};
}

void Game::addPlayer(std::string playerName) {
    Player player = Player(1,_nbPlayers+1,playerName,1500,0,0);
    _players[_nbPlayers] = player;
    _nbPlayers++;
}

int Game::movePlayer(int amount) {
    _players[_currentPlayer-1].move(amount);
    return _players[_currentPlayer-1].getPosition();
}

void Game::build() {
    int position = _players[_currentPlayer-1].getPosition();
    if (_board.getTile(position).house() == 4) {
        _players[_currentPlayer-1].buyHostel(_board.getTile(position));
    }
    else {
        _players[_currentPlayer-1].buyHouse(_board.getTile(position));
    }
}

void Game::payRent(){
    int position = _players[_currentPlayer-1].getPosition();
    _players[_currentPlayer-1].payRent(_players[_board.getTile(position).owned()-1],_board.getTile(position));
}

void Game::payTax() {
    _players[_currentPlayer-1].payTax(_board.getTile(_players[_currentPlayer-1].getPosition()).price());
    _communityBank += _board.getTile(_players[_currentPlayer-1].getPosition()).price();
}

void Game::winCommunityChest() {
    _players[_currentPlayer-1].giveMoney(_communityBank);
    emptyCommunityBank();
}

std::string Game::doActionCard() {
    Card newCard = _board.drawCard(rand() % 40);
    _board.doAction(newCard, _players[_currentPlayer-1]);
    return newCard.action();
}