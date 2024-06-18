//
// Created by lise babé on 22/05/2024.
//

#include "Game.h"
#include <iostream>
#include "Property.h"



void Game::start() {
    //initialize the game

    //std::cout << "Welcome to Monopoly" << std::endl;
    //chooseGame();
    //Board board = Board();
    // TODO: choisir le file qu'on importe (partie sauvegardée) ou celle par défaut (nouvelle partie)
    //board.loadBoard("game-state/assets/monopoly.json");
    //_board = board;
    //_players = board.players;
    // TODO: load the players from a file if they exist and if not, create them with the following code
    //selectNumberOfPlayers();
}

void Game::play() {
    std::cout << "The game is starting with turn " << to_string(_turn) << std::endl;
    for (int turn = _turn; turn < _nbTurns; turn++) {
        std::cout << "" << std::endl;
        std::cout << "Turn number :  " << turn+1 << std::endl;
        for (int j = 0; j < _players.size(); j++) {
            std::cout << "" << std::endl;
            std::cout << "It's "<< _players[j].getPlayerName() << "'s turn" << std::endl;
            this->nextTurn();
            if (_players[j].isBankrupt()) {
                std::cout << "You are bankrupt, you lose" << std::endl;
                return;
            }
        }
        std::cout << "Autosave" << std::endl;
        _board.setTurn(turn+1);
        _board.players = _players;
        _board.saveBoard();
    }
}

void end() {
    // TODO: save the game
    //end the game
}

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

void Game::onLand(Player& player) {
    std::string answer;
    Property& tile = _board.getTile(player.getPosition());

    if (tile.type() == 1) {
        std::cout << "You landed on " << tile.name() << std::endl;
        if (tile.owned() == player.getId() ) {
            std::cout << "It's your property" << std::endl;
            if (tile.house() < 3 && tile.hostel() == 0 && player.getMoneyAmount() >= tile.costHouse()){
                std::cout << "You have " << tile.house() << " house(s), do you want to buy one ? (y/n)" << std::endl;
                std::cin >> answer;
                if (answer == "y") {
                    std::cout << "You buy a house" << std::endl;
                    player.buyHouse(tile);
                } else if (answer == "n") {
                    std::cout << "You don't buy a house" << std::endl;
                }
            }
            else if (tile.house() == 3 && tile.hostel() == 0 && player.getMoneyAmount() >= tile.costHostel()){
                std::cout << "You have " << tile.house() << " houses, do you want to buy a hostel ? (yes/no)" << std::endl;
                std::cin >> answer;
                if (answer == "yes") {
                    std::cout << "You buy a hostel" << std::endl;
                    player.buyHostel(tile);
                } else if (answer == "no") {
                    std::cout << "You don't buy a hostel" << std::endl;
                }
            }
            else {
                std::cout << "You can't buy anything else" << std::endl;
            }
        }
        // if the property is not owned
        else if (tile.owned() == 0 ) {
            // you canbuy it
            player.buyProperty(tile);
        }
        // if the property is owned by the other player
        else {
            // you have to pay the rent
            std::cout << "owner of the property :" << tile.owned() << std::endl;
            player.payRent(_players[tile.owned()-1],tile);
        }
    }
    else if (tile.type() == 2) {
        std::cout << "You landed on a go to jail" << std::endl;
        player.goToJail();
    }
    else if (tile.type() == 3) {
        std::cout << "You landed on a tax, you have to pay " << tile.price() << " $$" << std::endl;
        player.payTax(tile.price());
        payToCommunityBank(tile.price());
    }
    else if (tile.type() == 4) {
        std::cout << "You landed on a chance tile !" << std::endl;
        Card newCard = _board.drawCard(rand() % 40);
        _board.doAction(newCard, player);
    }
    else if (tile.type() == 5) {
        std::cout << "You landed on the community chest" << std::endl;
        std::cout << "You won " << _communityBank << " $$" << std::endl;
        player.giveMoney(_communityBank);
        emptyCommunityBank();
    }
}

void Game::selectNumberOfPlayers() {
    int nbPlayers;
    int nbBots;
    // if players have been loaded
    if (_players[0].getPlayerName() != "") {
        std::cout << "4 Players have been loaded" << std::endl;
        return;
    }

    // if not, we ask the user to enter the number of real players
    std::cout << "With how many real players do you want to play with ? (2-4)" << std::endl;
    std::cin >> nbPlayers;
    nbBots = 4 - nbPlayers;
    std::cout << "You will play with " << nbPlayers << " players and " << nbBots << " bots" << std::endl;

    //Add the real players to the players array
    for (int i = 0; i < nbPlayers; i++) {
        std::string name;
        std::cout << "Player " << i+1 << " name : ";
        std::cin >> name;
        auto player = Player(1,i+1, name, 1500, 0, false);
        _players[i] = player;
    }
    //Create a board of bots to import bots from a file
    Board boardBots = Board();
    boardBots.genBots("game-state/assets/bots.json");

    //Add the bots to the players array
    for (int i = nbPlayers; i < 4; i++) {
        _players[i] = boardBots.players[i-nbPlayers];
    }

    std:: cout << "The 4 players are : " << std::endl;
    for (int i = 0; i < 4; i++) {
        // Si c'est un bot, on lui donne un id
        if (_players[i].type() == 0){
            _players[i].setId(i+1);
        }
        std::cout << _players[i].getPlayerName() << std::endl;
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


void Game::chooseGame() {
    if (_board.getNumberOfSavedGames() != 0) {
        std::cout << "Do you want to load a saved game ? (y/n)" << std::endl;
        std::string answer;
        std::cin >> answer;
        if (answer == "y") { // load a saved game
            std::cout << "They are " << _board.getNumberOfSavedGames() << " saved games :" << std::endl;
            for (int i = 1; i <= _board.getNumberOfSavedGames(); i++) {
                std::cout << "Game number " << i << std::endl;
            }
            std::cout << "Which one do you want to load ?" << std::endl;
            int gameNumber;
            while (true) {
                std::cin >> gameNumber;
                if (gameNumber > _board.getNumberOfSavedGames()) {
                    std::cout << "This game doesn't exist, please enter a valid number" << std::endl;
                } else {
                    break;
                }
            }
            _board.loadBoard("game-state/assets/partie" + std::to_string(gameNumber) + ".json");
            _players = _board.players;
            _turn = _board.getTurn();
            std::cout << "You are starting the game number " << _board.getGameNumber() << std::endl;
        } else if (answer == "n") {// start a new game
            std::cout << "You will start a new game" << std::endl;
            _board.loadBoard("game-state/assets/monopoly.json");
            std::cout << "You are starting the game number " << _board.getGameNumber() << std::endl;
            selectNumberOfPlayers();
        }
    } else {
        std::cout << "There is no saved games. Let's start a new game" << std::endl;
        _board.loadBoard("game-state/assets/monopoly.json");
        std::cout << "You are starting the game number " << _board.getGameNumber() << std::endl;
        selectNumberOfPlayers();
    }
}

std::string Game::getWinner() {
    for (int i = 0; i < _players.size(); i++) {
        if (!_players[i].isBankrupt()) {
            return _players[i].getPlayerName();
        }
    }
    return "Personne n'";
}