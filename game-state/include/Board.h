//
// Created by lise babé on 22/05/2024.
//

#ifndef BOARD_H
#define BOARD_H
#include <array>
#include "Card.h"
#include "Player.h"
#include "Property.h"

class Board {
protected:
    std::array<Card,40> _cards; //the board has 40 cards
    std::array<Property,40> _tiles; //the board has 40 tiles

public:
    Board(){}

    Board(const std::array<Card, 40> &cards, const std::array<Property, 40> &tiles)
        : _cards(cards),
          _tiles(tiles) {
    }

    std::array<Card,40> & cards() {
        return _cards;
    }

    std::array<Property,40> & tiles() {
        return _tiles;
    }


    Property& getTile(int id);
    Card drawCard(int id);

    void doAction(Card& card, Player& player);


};



#endif //BOARD_H
