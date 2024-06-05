//
// Created by lise babé on 22/05/2024.
//

#include "Board.h"

Card Board::drawCard(int id) {
    return _cards[id];
}

Property* Board::getTile(int id) {
    return &_tiles[id];
}
