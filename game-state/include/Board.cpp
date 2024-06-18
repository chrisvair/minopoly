//
// Created by lise babé on 22/05/2024.
//

#include "Board.h"
#include "JsonSerializer.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;


void Board::loadBoard(const std::string& filename) {
    loadFromFile(filename);
}

void Board::saveBoard(const std::string& filename) const {
    saveToFile(filename);
}


void Board::loadFromFile(const std::string& filename) {
    JsonSerializer::deserialize(*this, filename);
}

void Board::saveToFile(const std::string& filename) const {
    JsonSerializer::serialize(*this, filename);
}

void Board::genBots(const std::string& filename) {
    JsonSerializer::loadBots(*this, filename);
}

Card Board::drawCard(int id) {
    return _cards[id];
}

Property& Board::getTile(int id) {
    return _tiles[id];
}

void Board::doAction(Card& card, Player& player) {
    if (card.getType() == 1 ) {
        player.giveMoney(card.value());
    }
    else if (card.getType() == 2) {
        player.takeMoney(card.value());
    }
    else if (card.getType() == 3) {
        player.goToStart();
        player.move(card.value());
    }
    else if (card.getType() == 4) {
        player.goToJail();
    }
    else if (card.getType() == 5) {
        player.getOutOfJailCard();
    }
    else if (card.getType() == 6) {
        player.move(card.value());
    }
}