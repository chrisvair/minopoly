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


    std::string name1;
    std::string name2;

    std::cout << "Player 1 name : ";
    std::cin >> name1;
    auto player1 = Player(1,1, name1, 1500, 0, false);

    std::cout << "Player 2 name : ";
    std::cin >> name2;
    auto player2 = Player(1, 2,name2, 1500, 0, false);

    auto tile0 = Property(0,"start",0,200,"",false,std::array<int,6>{0,0,0,0,0,0});
    auto tile1 = Property(1, "mines", 1, 150, "bleu", false, std::array<int, 6>{10, 20, 30, 40, 50, 60});
    auto tile2 = Property(1, "forest", 2, 200, "vert", false, std::array<int, 6>{15, 25, 35, 45, 55, 65});
    auto tile3 = Property(1, "desert", 3, 100, "jaune", false, std::array<int, 6>{5, 15, 25, 35, 45, 55});
    auto tile4 = Property(1, "mountains", 4, 250, "rouge", false, std::array<int, 6>{20, 30, 40, 50, 60, 70});
    auto tile5 = Property(1, "river", 5, 180, "bleu", false, std::array<int, 6>{12, 22, 32, 42, 52, 62});
    auto tile6 = Property(1, "swamp", 6, 130, "vert", false, std::array<int, 6>{17, 27, 37, 47, 57, 67});
    auto tile7 = Property(1, "plains", 7, 110, "jaune", false, std::array<int, 6>{7, 17, 27, 37, 47, 57});
    auto tile8 = Property(1, "jungle", 8, 230, "rouge", false, std::array<int, 6>{18, 28, 38, 48, 58, 68});
    auto tile9 = Property(1, "city", 9, 300, "bleu", false, std::array<int, 6>{25, 35, 45, 55, 65, 75});
    auto tile10 = Property(1, "village", 10, 170, "vert", false, std::array<int, 6>{14, 24, 34, 44, 54, 64});
    auto tile11 = Property(1, "canyon", 11, 140, "jaune", false, std::array<int, 6>{8, 18, 28, 38, 48, 58});
    auto tile12 = Property(1, "lake", 12, 260, "rouge", false, std::array<int, 6>{21, 31, 41, 51, 61, 71});
    auto tile13 = Property(1, "hill", 13, 190, "bleu", false, std::array<int, 6>{13, 23, 33, 43, 53, 63});
    auto tile14 = Property(1, "savannah", 14, 220, "vert", false, std::array<int, 6>{16, 26, 36, 46, 56, 66});
    auto tile15 = Property(1, "valley", 15, 160, "jaune", false, std::array<int, 6>{6, 16, 26, 36, 46, 56});
    auto tile16 = Property(1, "cliff", 16, 240, "rouge", false, std::array<int, 6>{19, 29, 39, 49, 59, 69});
    auto tile17 = Property(1, "volcano", 17, 280, "bleu", false, std::array<int, 6>{11, 21, 31, 41, 51, 61});
    auto tile18 = Property(1, "glacier", 18, 210, "vert", false, std::array<int, 6>{14, 24, 34, 44, 54, 64});
    auto tile19 = Property(1, "bog", 19, 120, "jaune", false, std::array<int, 6>{7, 17, 27, 37, 47, 57});
    auto tile20 = Property(1, "tundra", 20, 270, "rouge", false, std::array<int, 6>{22, 32, 42, 52, 62, 72});
    auto tile21 = Property(1, "cave", 21, 200, "bleu", false, std::array<int, 6>{15, 25, 35, 45, 55, 65});
    auto tile22 = Property(1, "oasis", 22, 150, "vert", false, std::array<int, 6>{18, 28, 38, 48, 58, 68});
    auto tile23 = Property(1, "reef", 23, 130, "jaune", false, std::array<int, 6>{9, 19, 29, 39, 49, 59});
    auto tile24 = Property(1, "delta", 24, 250, "rouge", false, std::array<int, 6>{23, 33, 43, 53, 63, 73});
    auto tile25 = Property(1, "marsh", 25, 180, "bleu", false, std::array<int, 6>{12, 22, 32, 42, 52, 62});
    auto tile26 = Property(1, "steppe", 26, 230, "vert", false, std::array<int, 6>{16, 26, 36, 46, 56, 66});
    auto tile27 = Property(1, "gorge", 27, 140, "jaune", false, std::array<int, 6>{8, 18, 28, 38, 48, 58});
    auto tile28 = Property(1, "cove", 28, 290, "rouge", false, std::array<int, 6>{24, 34, 44, 54, 64, 74});
    auto tile29 = Property(1, "mesa", 29, 170, "bleu", false, std::array<int, 6>{13, 23, 33, 43, 53, 63});
    auto tile30 = Property(1, "prairie", 30, 240, "vert", false, std::array<int, 6>{17, 27, 37, 47, 57, 67});
    auto tile31 = Property(2, "go to jail", 31, 0, "", false, std::array<int, 6>{});
    auto tile32 = Property(3, "tax", 32, 150, "", false, std::array<int, 6>{});
    auto tile33 = Property(4, "card", 33, 0, "", false, std::array<int, 6>{});
    auto tile34 = Property(3, "tax", 34, 150, "", false, std::array<int, 6>{});
    auto tile35 = Property(4, "card", 35, 0, "", false, std::array<int, 6>{});
    auto tile36 = Property(3, "tax", 36, 150, "", false, std::array<int, 6>{});
    auto tile37 = Property(4, "card", 37, 0, "", false, std::array<int, 6>{});
    auto tile38 = Property(4, "card", 38, 0, "", false, std::array<int, 6>{});
    auto tile39 = Property(3, "tax", 39, 150, "", false, std::array<int, 6>{});
    auto tile40 = Property(4, "card", 40, 0, "", false, std::array<int, 6>{});

    std::array<Property,40> tiles = {tile0, tile1, tile2, tile3, tile4, tile5, tile6, tile7, tile8, tile9,
        tile10, tile11, tile12, tile13, tile14, tile15, tile16, tile17, tile18, tile19,
        tile20, tile21, tile22, tile23, tile24, tile25, tile26, tile27, tile28, tile29, tile30,
        tile31, tile32, tile33, tile34, tile35, tile36, tile37, tile38, tile39};


    auto cards = std::array<Card,40>{} ;

    //Board board = Board(cards,tiles);
    //
    auto players = std::array<Player,2>{player1, player2};
    _players = players;
    //_board = board;
}

void Game::play() {
    //play the game
    for (int i = 0; i < _nbTurns; i++) {
    std::cout << "Turn number :  " << i+1 << std::endl;
        for (int j = 0; j < _players.size(); j++) {
            std::cout << "It's "<< _players[j].getPlayerName() << " turn" << std::endl;
            this->nextTurn(_players[j]);
        }
    }
}

void end() {
    //end the game
}

void Game::nextTurn(Player &player) {
    //if in jail we check if you can get out of it
    if (player.isInJail() == 3) {
        std::cout << "You were in jail for 3 turn, you can get out of jail" << std::endl;
        player.setJail(0);
        return;
    }
    else if (player.isInJail() != 0) {
        std::cout << "You are in jail, you have " << 3-player.isInJail() << " turns left" << std::endl;
        //check if the player can get out of jail with a card
    }

    //if you can't get out with a card, you roll the dices

    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    std::cout << "You are at position " << player.getPosition() << std::endl;
    std::cout << "You rolled a " << dice1 << " and a " << dice2 << std::endl;

    bool doubleDice = (dice1 == dice2);

    //if in jail
    if (player.isInJail() != 0){
        // free if double
        if (doubleDice){
            std::cout << "You are in jail but you are freed by your double" << std::endl;
            player.setJail(0);
            //player.move(dice1 + dice2); //must check that after moving is not in jail again TO DO
            return;
        }
        //you stay at the same place
        else {
            std::cout << "You spend one more night in jail" << std::endl;
            player.setJail(player.isInJail() + 1);
            return;
        }
    }
    else {
        //if you dou a double you play again
        if (doubleDice){
            //you move and you play your turn according to where you land
            player.move(dice1 + dice2);
            this->onLand(player);

            //if you're not in jail, you play again
            if (player.isInJail() == 0){
                std::cout << "you play again" << std::endl;
                return this->nextTurn(player);
            }
        }
        else {
            //you move and you play your turn according to where you land
            player.move(dice1 + dice2);
            this->onLand(player);
        }
    }
}

void Game::onLand(Player player) {
    std::string answer;
    auto tile = _board.getTile(player.getPosition());

    if (tile->type() == 1) {
        std::cout << "you landed on a property" << std::endl;
        if (tile->owned() == player.getId() ) {
            std::cout << "it's your property" << std::endl;
            if (tile->house() == 0) {
                std::cout << "you have no house, do you want to buy one ? (yes/no)" << std::endl;
                std::cin >> answer;
                if (answer == "yes") {
                    std::cout << "you buy a house" << std::endl;
                    // you buy a house
                } else if (answer == "no"){
                    std::cout << "you don't buy a house" << std::endl;
                    //do nothing
                }
            }
            else if (tile->house() > 0 && tile->house() < 3 && tile->hostel() == 0 ){
                std::cout << "you have" << tile->house() << "house(s), do you want to buy one ? (yes/no)" << std::endl;
                std::cin >> answer;
                if (answer == "yes") {
                    std::cout << "you buy a house" << std::endl;
                    // you buy a house
                } else if (answer == "no") {
                    std::cout << "you don't buy a house" << std::endl;
                    //do nothing
                }
            }
            else if (tile->house() == 3 && tile->hostel() == 0 ) {
                std::cout << "you have" << tile->house() << "houses, do you want to buy a hostel ? (yes/no)" << std::endl;
                std::cin >> answer;
                if (answer == "yes") {
                    std::cout << "you buy a hostel" << std::endl;
                    // you buy a hostel
                } else if (answer == "no") {
                    std::cout << "you don't buy a hostel" << std::endl;
                    //do nothing
                }
            }
        }
        else if (tile->owned() == 0 ) {
            std::cout << "This property is not owned" << std::endl;
            std::cout << "Do you want to buy the land, it costs " << tile->price() << " $$ ? (yes/no)" << std::endl;
            std::cin >> answer;
            if (answer == "yes") {
                std::cout << "you buy the property" << std::endl;
                player.buyProperty(tile->getId());
                std::cout<< "player id : " <<player.getId() << std::endl;
                tile->setOwned(player.getId());
                std::cout << "tile owner : " << tile->owned() << std::endl;
                // you buy the property
            } else if (answer == "no"){
                std::cout << "you don't buy the property" << std::endl;
                //do nothing
            }
            //you can buy the property
        }
        else {
            std::cout << "This property is owned, you have to pay a rent" << std::endl;
            int amount = tile->rents()[tile->house()];
            std::cout << "the rent is " << amount << " $$" << std::endl;
            if (player.getMoneyAmount() < amount) {
                std::cout << "you can't pay the rent, you are bankrupt" << std::endl;
            } else {
                std::cout << "you have enough money to pay" << std::endl;
                int owner = tile->owned();
                player.takeMoney(amount);
                std::cout << owner << std::endl;
                _players[owner-1].giveMoney(amount);
            }
        }
    }
    else if (tile->type() == 2) {
        std::cout << "you landed on a go to jail" << std::endl;
        std::cout << "you go to jail" << std::endl;
        player.setJail(1);
    }
    else if (tile->type() == 3) {
        std::cout << "You landed on a tax, you have to pay " << tile->price() << " $$" << std::endl;
        if (player.getMoneyAmount() < tile->price()) {
            std::cout << "you can't pay the tax, you are bankrupt" << std::endl;
        } else {
            std::cout << "we take " << tile->price() << " $$ from your account" << std::endl;
            player.takeMoney(tile->price());
        }
    }
    else if (tile->type() == 4) {
        std::cout << "you landed on a card" << std::endl;
        Card newCard = _board.drawCard(rand() % 40);
        //we do something related to the card
        // TODO: implement a function to act as the card ask
        //we add the card to the deck of the player
    }
}

void endTurn(){
    //end the turn
}