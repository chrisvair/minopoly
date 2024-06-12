//
// Created by lise babé on 22/05/2024.
//

#include "Board.h"

Card Board::drawCard(int id) {
    return _cards[id];
}

Property& Board::getTile(int id) {
    return _tiles[id];
}

void Board::doAction(Card& card, Player& player) {
    if (card.getId() == 1 ) {
        std::cout << card.action() << std::endl;
        player.giveMoney(card.value());
    }
    else if (card.getId() == 2) {
        std::cout << card.action() << std::endl;
        player.takeMoney(card.value());
    }
    else if (card.getId() == 3) {
        std::cout << card.action() << std::endl;
        player.move(card.value());
    }
    else if (card.getId() == 4) {
        std::cout << card.action() << std::endl;
        player.goToJail();
    }
    else if (card.getId() == 5) {
        std::cout << card.action() << std::endl;
        player.getOutOfJailCard();
    }
    else if (card.getId() == 6) {
        std::cout << card.action() << std::endl;
        player.goToStart();
    }
}