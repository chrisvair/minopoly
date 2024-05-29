//
// Created by lise babé on 22/05/2024.
//

#include "Game.h"
#include <iostream>

void start() {
    //initialize the game


}

void Game::Play() {
    //play the game
    for (int i = 0; i < _nbTurns; i++) {
    std::cout << "Turn number :  " << i << std::endl;
        for (int j = 0; j < _players.size(); j++) {
            nextTurn(_players[j]);
        }
    }
}

void end() {
    //end the game
}

void Game::nextTurn(Player player) {
    std::cout << "It's " << player.getPlayerName() << " turn" << std::endl;
    if (player.isInJail() == 3) {
        std::cout << "You were in jail for 3 turn, you can get out of jail" << std::endl;
        return;
    }
    else if (player.isInJail() != 0) {
        std::cout << "You are in jail, you have " << 3-player.isInJail() << " turns left" << std::endl;
        //check if the player can get out of jail with a card
    }

    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;

    std::cout << "You rolled a " << dice1 << " and a " << dice2 << std::endl;

    bool doubleDice = (dice1 == dice2);

    if (player.isInJail() != 0){ //if in jail
        if (doubleDice){ // free if double
            std::cout << "You are in jail but you are freed by your double" << std::endl;
            player.setJail(0);
            player.move(dice1 + dice2); //must check that after moving is not in jail again TO DO
            return;
        }
        else {
            return;
        }
    }
    else {
        if (doubleDice){
            player.move(dice1 + dice2);
            if (player.isInJail() != 0){
                return this->nextTurn(player);
            }
            else {
                return;
            }
        }
    }
}

void endTurn(){
    //end the turn
}