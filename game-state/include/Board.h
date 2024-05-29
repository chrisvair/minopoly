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
    std::array<Card,40> _cards; //the board has 40 cards
    std::array<Tile,40> _tiles; //the board has 40 tiles

public:
    Card getCard(int id);
    Tile getTile(int id);

    Board(const std::array<Card, 40> &cards, const std::array<Tile, 40> &tiles)
        : _cards(cards),
          _tiles(tiles) {
    }

    std::array<Card, 40> & cards() {
        return _cards;
    }

    std::array<Tile, 40> & tiles() {
        return _tiles;
    }

};



#endif //BOARD_H
