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


Card Board::drawCard(int id) {
    return _cards[id];
}

Property* Board::getTile(int id) {
    return &_tiles[id];
}

