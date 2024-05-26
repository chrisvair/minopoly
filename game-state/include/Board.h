//
// Created by lise babé on 22/05/2024.
//

#ifndef BOARD_H
#define BOARD_H
#include <array>
#include "Card.h"
#include "Tile.h"

class Board {
protected:
    std::array<Card,40> _cards;
    std::array<Tile,40> _tiles;

public:
    Card getCard(int id);
    Tile getTile(int id);
};



#endif //BOARD_H
