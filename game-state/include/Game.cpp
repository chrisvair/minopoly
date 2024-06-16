//
// Created by lise babé on 22/05/2024.
//

#include "Game.h"
#include <iostream>
#include "Property.h"



void Game::start() {
    //initialize the game

    Board board = Board();
    board.loadBoard("game-state/assets/monopoly.json");
    _board = board;
    _players = board.players;
    // TODO: load the players from a file if they exist and if not, create them with the following code
    selectNumberOfPlayers();
}

void Game::play() {
    for (int i = 0; i < _nbTurns; i++) {
        std::cout << "" << std::endl;
        std::cout << "Turn number :  " << i+1 << std::endl;
        for (int j = 0; j < _players.size(); j++) {
            std::cout << "" << std::endl;
            std::cout << "It's "<< _players[j].getPlayerName() << "'s turn" << std::endl;
            this->nextTurn(_players[j]);
            if (_players[j].isBankrupt()) {
                std::cout << "You are bankrupt, you lose" << std::endl;
                return;
            }
        }
    }
}

void end() {
    //end the game
}

void Game::nextTurn(Player &player) {
    srand(time(0));
    std::string answer;


    //if in jail we check if you can get out of it
    if (player.isInJail() == 3) {
        std::cout << "You were in jail for 3 turn, you can get out of jail" << std::endl;
        player.getOutOfJail();
        return;
    }
    if (player.isInJail() != 0) {
        std::cout << "You are in jail, you have " << 3-player.isInJail() << " turns left" << std::endl;
        //check if the player can get out of jail with a card
        if (player.getNumberOfGetOutOfJailCard() > 0) {
            std::cout << "You can get out of jail with a card, do you want to use it ? (y/n)" << std::endl;
            std::cin >> answer;
            if (answer == "y") {
                std::cout << "You use a card to get out of jail" << std::endl;
                player.useOutOfJailCard();
                return;
            }
        }
    }

    // if you can't get out with a card, you roll the dices
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    // check if you have a double
    bool doubleDice = (dice1 == dice2);

    // if in jail
    if (player.isInJail() != 0){
        // free if double
        if (doubleDice){
            std::cout << "You rolled a " << dice1 << " and a " << dice2 << std::endl;
            std::cout << "You are in jail but you are freed by your double" << std::endl;
            player.getOutOfJail();
            return;
        }
        player.oneMoreTurnInJail();
        return;
    }

    player.move(dice1 + dice2);
    std::cout << "You rolled a " << dice1 << " and a " << dice2 << std::endl;
    std::cout << "Position : " << player.getPosition() << " Money : "<< player.getMoneyAmount() << std::endl;
    this->onLand(player);

    if (player.isBankrupt()) {
        return;
    }

    if (doubleDice) {
        std::cout << "you play again" << std::endl;
        return this->nextTurn(player);
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
        std::cout << "You landed on a card" << std::endl;
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

    // if not, we ask the user to enter the number of players
    std::cout << "How many players ? (1-4)" << std::endl;
    std::cin >> nbPlayers;
    nbBots = 4 - nbPlayers;
    std::cout << "You will play with " << nbPlayers << " players and " << nbBots << " bots" << std::endl;

    for (int i = 0; i < nbPlayers; i++) {
        std::string name;
        std::cout << "Player " << i+1 << " name : ";
        std::cin >> name;
        auto player = Player(1,i+1, name, 1500, 0, false);
        _players[i] = player;
    }
    for (int i = nbPlayers; i < 4; i++) {
        auto player = Player(0,i+1, "bot", 1500, 0, false);
        _players[i] = player;
    }

}