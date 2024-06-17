//
// Created by lise babé on 22/05/2024.
//

#include "Board.h"

Card Board::getCard(int id) {
    return _cards[id];
}

Tile Board::getTile(int id) {
    return _tiles[id];
}
