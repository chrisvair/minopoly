//
// Created by lise babé on 22/05/2024.
//

#include "Game.h"
#include <iostream>
#include "Property.h"



void Game::start() {
    //initialize the game


    Board board = Board();
    // TODO: choisir le file qu'on importe (partie sauvegardée) ou celle par défaut (nouvelle partie)
    board.loadBoard("game-state/assets/monopoly.json");

  
    auto players = std::array<Player,4>{};
    _players = players;
    _board = board;
    //_players = board.players;
    // TODO: load the players from a file if they exist and if not, create them with the following code
    //selectNumberOfPlayers();
}

void Game::play() {
    for (int i = 0; i < _nbTurns; i++) {
        for (int j = 0; j < _players.size(); j++) {
            // this->nextTurn(_players[j]);
            if (_players[j].isBankrupt()) {
                return;
            }
        }
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
    }

    Player player = _players[_currentPlayer-1];
    //if in jail we check if you can get out of it
    if (player.isInJail() == 3) {
        player.getOutOfJail();
        nextTurn();
    }
    else if(player.isInJail()!=0) {
        player.oneMoreTurnInJail();
        nextTurn();
    }



    // // if in jail
    // if (player.isInJail() != 0){
    //     // free if double
    //     if (doubleDice){
    //         std::cout << "You rolled a " << dice1 << " and a " << dice2 << std::endl;
    //         std::cout << "You are in jail but you are freed by your double" << std::endl;
    //         player.getOutOfJail();
    //         return;
    //     }
    //     player.oneMoreTurnInJail();
    //     return;
    // }
    //
    // player.move(dice1 + dice2);
    // std::cout << "You rolled a " << dice1 << " and a " << dice2 << std::endl;
    // std::cout << "Position : " << player.getPosition() << " Money : "<< player.getMoneyAmount() << std::endl;
    // this->onLand(player);
    //
    // if (player.isBankrupt()) {
    //     return;
    // }
    //
    // if (doubleDice) {
    //     std::cout << "you play again" << std::endl;
    //     return this->nextTurn(player);
    // }
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