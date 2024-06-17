//
// Created by lise babé on 22/05/2024.
//

#include "Game.h"
#include <iostream>
#include "Property.h"

void Game::start() {
    //initialize the game
    std::string name1;
    std::string name2;

    std::cout << "Player 1 name : ";
    std::cin >> name1;
    auto player1 = Player(1,1, name1, 1500, 0, false);

    std::cout << "Player 2 name : ";
    std::cin >> name2;
    auto player2 = Player(1, 2,name2, 1500, 0, false);

    auto tile0 = Property(0,"start",0,200,"",0,std::array<int,6>{0,0,0,0,0,0});
    auto tile1 = Property(1, "mines", 1, 150, "bleu", 0, std::array<int, 6>{10, 20, 30, 40, 50, 60});
    auto tile2 = Property(1, "forest", 2, 200, "vert", 0, std::array<int, 6>{15, 25, 35, 45, 55, 65});
    auto tile3 = Property(1, "desert", 3, 100, "jaune", 0, std::array<int, 6>{5, 15, 25, 35, 45, 55});
    auto tile4 = Property(1, "mountains", 4, 250, "rouge", 0, std::array<int, 6>{20, 30, 40, 50, 60, 70});
    auto tile5 = Property(1, "river", 5, 180, "bleu", 0, std::array<int, 6>{12, 22, 32, 42, 52, 62});
    auto tile6 = Property(1, "swamp", 6, 130, "vert", 0, std::array<int, 6>{17, 27, 37, 47, 57, 67});
    auto tile7 = Property(1, "plains", 7, 110, "jaune", 0, std::array<int, 6>{7, 17, 27, 37, 47, 57});
    auto tile8 = Property(1, "jungle", 8, 230, "rouge", 0, std::array<int, 6>{18, 28, 38, 48, 58, 68});
    auto tile9 = Property(1, "city", 9, 300, "bleu", 0, std::array<int, 6>{25, 35, 45, 55, 65, 75});
    auto tile10 = Property(1, "village", 10, 170, "vert", 0, std::array<int, 6>{14, 24, 34, 44, 54, 64});
    auto tile11 = Property(1, "canyon", 11, 140, "jaune", 0, std::array<int, 6>{8, 18, 28, 38, 48, 58});
    auto tile12 = Property(1, "lake", 12, 260, "rouge", 0, std::array<int, 6>{21, 31, 41, 51, 61, 71});
    auto tile13 = Property(1, "hill", 13, 190, "bleu", 0, std::array<int, 6>{13, 23, 33, 43, 53, 63});
    auto tile14 = Property(1, "savannah", 14, 220, "vert", 0, std::array<int, 6>{16, 26, 36, 46, 56, 66});
    auto tile15 = Property(1, "valley", 15, 160, "jaune", 0, std::array<int, 6>{6, 16, 26, 36, 46, 56});
    auto tile16 = Property(1, "cliff", 16, 240, "rouge", 0, std::array<int, 6>{19, 29, 39, 49, 59, 69});
    auto tile17 = Property(1, "volcano", 17, 280, "bleu", 0, std::array<int, 6>{11, 21, 31, 41, 51, 61});
    auto tile18 = Property(1, "glacier", 18, 210, "vert", 0, std::array<int, 6>{14, 24, 34, 44, 54, 64});
    auto tile19 = Property(1, "bog", 19, 120, "jaune", 0, std::array<int, 6>{7, 17, 27, 37, 47, 57});
    auto tile20 = Property(1, "tundra", 20, 270, "rouge", 0, std::array<int, 6>{22, 32, 42, 52, 62, 72});
    auto tile21 = Property(1, "cave", 21, 200, "bleu", 0, std::array<int, 6>{15, 25, 35, 45, 55, 65});
    auto tile22 = Property(1, "oasis", 22, 150, "vert", 0, std::array<int, 6>{18, 28, 38, 48, 58, 68});
    auto tile23 = Property(1, "reef", 23, 130, "jaune", 0, std::array<int, 6>{9, 19, 29, 39, 49, 59});
    auto tile24 = Property(1, "delta", 24, 250, "rouge", 0, std::array<int, 6>{23, 33, 43, 53, 63, 73});
    auto tile25 = Property(1, "marsh", 25, 180, "bleu", 0, std::array<int, 6>{12, 22, 32, 42, 52, 62});
    auto tile26 = Property(1, "steppe", 26, 230, "vert", 0, std::array<int, 6>{16, 26, 36, 46, 56, 66});
    auto tile27 = Property(1, "gorge", 27, 140, "jaune", 0, std::array<int, 6>{8, 18, 28, 38, 48, 58});
    auto tile28 = Property(1, "cove", 28, 290, "rouge", 0, std::array<int, 6>{24, 34, 44, 54, 64, 74});
    auto tile29 = Property(1, "mesa", 29, 170, "bleu", 0, std::array<int, 6>{13, 23, 33, 43, 53, 63});
    auto tile30 = Property(1, "prairie", 30, 240, "vert", 0, std::array<int, 6>{17, 27, 37, 47, 57, 67});
    auto tile31 = Property(2, "go to jail", 31, 0, "", false, std::array<int, 6>{});
    auto tile32 = Property(3, "tax", 32, 150, "", false, std::array<int, 6>{});
    auto tile33 = Property(4, "card", 33, 0, "", false, std::array<int, 6>{});
    auto tile34 = Property(3, "tax", 34, 150, "", false, std::array<int, 6>{});
    auto tile35 = Property(5, "community chest", 35, 0, "", false, std::array<int, 6>{});
    auto tile36 = Property(3, "tax", 36, 150, "", false, std::array<int, 6>{});
    auto tile37 = Property(4, "card", 37, 0, "", false, std::array<int, 6>{});
    auto tile38 = Property(4, "card", 38, 0, "", false, std::array<int, 6>{});
    auto tile39 = Property(3, "tax", 39, 150, "", false, std::array<int, 6>{});
    auto tile40 = Property(4, "card", 40, 0, "", false, std::array<int, 6>{});

    std::array<Property,40> tiles = {tile0, tile1, tile2, tile3, tile4, tile5, tile6, tile7, tile8, tile9,
        tile10, tile11, tile12, tile13, tile14, tile15, tile16, tile17, tile18, tile19,
        tile20, tile21, tile22, tile23, tile24, tile25, tile26, tile27, tile28, tile29, tile30,
        tile31, tile32, tile33, tile34, tile35, tile36, tile37, tile38, tile39};


    auto card1 = Card(1, "You won 100$", 100);
    auto card2 = Card(2, "You lost 100$", 100);
    auto card3 = Card(3, "You move 3 tiles", 3);
    auto card4 = Card(4, "You go to jail", 0);
    auto card5 = Card(5, "You get out of jail", 0);
    auto card6 = Card(6, "You go to the start", 0);
    auto card7 = Card(1, "You won 200$", 200);
    auto card8 = Card(2, "You lost 200$", 200);
    auto card9 = Card(3, "You move 2 tiles", 2);
    auto card10 = Card(4, "You go to jail", 0);
    auto card11 = Card(5, "You get out of jail", 0);
    auto card12 = Card(6, "You go to the start", 0);
    auto card13 = Card(1, "You won 150$", 150);
    auto card14 = Card(2, "You lost 150$", 150);
    auto card15 = Card(3, "You move 4 tiles", 4);
    auto card16 = Card(4, "You pay a fine of 50$", 50);
    auto card17 = Card(5, "You receive a gift of 50$", 50);
    auto card18 = Card(6, "You go to the park", 0);
    auto card19 = Card(1, "You won 300$", 300);
    auto card20 = Card(2, "You lost 300$", 300);
    auto card21 = Card(3, "You move 5 tiles", 5);
    auto card22 = Card(4, "You pay a fine of 100$", 100);
    auto card23 = Card(5, "You receive a gift of 100$", 100);
    auto card24 = Card(6, "You go to the beach", 0);
    auto card25 = Card(1, "You won 50$", 50);
    auto card26 = Card(2, "You lost 50$", 50);
    auto card27 = Card(3, "You move 1 tile", 1);
    auto card28 = Card(4, "You go to jail", 0);
    auto card29 = Card(5, "You get out of jail", 0);
    auto card30 = Card(6, "You go to the mountains", 0);
    auto card31 = Card(1, "You won 400$", 400);
    auto card32 = Card(2, "You lost 400$", 400);
    auto card33 = Card(3, "You move 6 tiles", 6);
    auto card34 = Card(4, "You pay a fine of 200$", 200);
    auto card35 = Card(5, "You receive a gift of 200$", 200);
    auto card36 = Card(6, "You go to the city center", 0);
    auto card37 = Card(1, "You won 500$", 500);
    auto card38 = Card(2, "You lost 500$", 500);
    auto card39 = Card(3, "You move 7 tiles", 7);
    auto card40 = Card(4, "You go to jail", 0);


    auto cards = std::array<Card,40>{card1,card2,card3,card4,card5,card6,
        card7,card8,card9,card10,card11,card12,card13,
        card14,card15,card16,card17,card18,card19,card20,
        card21,card22,card23,card24,card25,card26,card27,
        card28,card29,card30,card31,card32,card33,card34,
        card35,card36,card37,card38,card39,card40} ;

    Board board = Board(cards,tiles);
    //
    auto players = std::array<Player,4>{player1, player2};
    _players = players;
    _board = board;
}

void Game::play() {
    for (int i = 0; i < _nbTurns; i++) {
        std::cout << "" << std::endl;
        std::cout << "Turn number :  " << i+1 << std::endl;
        for (int j = 0; j < _players.size(); j++) {
            std::cout << "" << std::endl;
            std::cout << "It's "<< _players[j].getPlayerName() << " turn" << std::endl;
            // this->nextTurn(_players[j]);
            if (_players[j].isBankrupt()) {
                return;
            }
        }
    }
}

void end() {
    //end the game
}

void Game::nextTurn() {
    _currentPlayer++;
    if (_currentPlayer == _players.size() + 1) {
        _currentPlayer = 1;
    }

    Player player = _players[_currentPlayer-1];
    //if in jail we check if you can get out of it
    if (player.isInJail() == 3) {
        player.getOutOfJail();
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
        std::cout << "You landed on a property" << std::endl;
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