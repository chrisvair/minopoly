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
    Property tile0 = Property(0,"start",0,200,"",0,std::array<int,6>{0,0,0,0,0,0});
    Property tile1 = Property(1, "mines", 1, 150, "bleu", 0, std::array<int, 6>{10, 20, 30, 40, 50, 60});
    Property tile2 = Property(1, "forest", 2, 200, "vert", 0, std::array<int, 6>{15, 25, 35, 45, 55, 65});
    Property tile3 = Property(1, "desert", 3, 100, "jaune", 0, std::array<int, 6>{5, 15, 25, 35, 45, 55});
    Property tile4 = Property(2, "mountains", 4, 250, "rouge", 0, std::array<int, 6>{20, 30, 40, 50, 60, 70});
    Property tile5 = Property(2, "river", 5, 180, "bleu", 0, std::array<int, 6>{12, 22, 32, 42, 52, 62});
    Property tile6 = Property(2, "swamp", 6, 130, "vert", 0, std::array<int, 6>{17, 27, 37, 47, 57, 67});
    Property tile7 = Property(1, "plains", 7, 110, "jaune", 0, std::array<int, 6>{7, 17, 27, 37, 47, 57});
    Property tile8 = Property(1, "jungle", 8, 230, "rouge", 0, std::array<int, 6>{18, 28, 38, 48, 58, 68});
    Property tile9 = Property(1, "city", 9, 300, "bleu", 0, std::array<int, 6>{25, 35, 45, 55, 65, 75});
    Property tile10 = Property(1, "village", 10, 170, "vert", 0, std::array<int, 6>{14, 24, 34, 44, 54, 64});
    Property tile11 = Property(1, "canyon", 11, 140, "jaune", 0, std::array<int, 6>{8, 18, 28, 38, 48, 58});
    Property tile12 = Property(1, "lake", 12, 260, "rouge", 0, std::array<int, 6>{21, 31, 41, 51, 61, 71});
    Property tile13 = Property(1, "hill", 13, 190, "bleu", 0, std::array<int, 6>{13, 23, 33, 43, 53, 63});
    Property tile14 = Property(1, "savannah", 14, 220, "vert", 0, std::array<int, 6>{16, 26, 36, 46, 56, 66});
    Property tile15 = Property(1, "valley", 15, 160, "jaune", 0, std::array<int, 6>{6, 16, 26, 36, 46, 56});
    Property tile16 = Property(1, "cliff", 16, 240, "rouge", 0, std::array<int, 6>{19, 29, 39, 49, 59, 69});
    Property tile17 = Property(1, "volcano", 17, 280, "bleu", 0, std::array<int, 6>{11, 21, 31, 41, 51, 61});
    Property tile18 = Property(1, "glacier", 18, 210, "vert", 0, std::array<int, 6>{14, 24, 34, 44, 54, 64});
    Property tile19 = Property(1, "bog", 19, 120, "jaune", 0, std::array<int, 6>{7, 17, 27, 37, 47, 57});
    Property tile20 = Property(1, "tundra", 20, 270, "rouge", 0, std::array<int, 6>{22, 32, 42, 52, 62, 72});
    Property tile21 = Property(1, "cave", 21, 200, "bleu", 0, std::array<int, 6>{15, 25, 35, 45, 55, 65});
    Property tile22 = Property(1, "oasis", 22, 150, "vert", 0, std::array<int, 6>{18, 28, 38, 48, 58, 68});
    Property tile23 = Property(1, "reef", 23, 130, "jaune", 0, std::array<int, 6>{9, 19, 29, 39, 49, 59});
    Property tile24 = Property(1, "delta", 24, 250, "rouge", 0, std::array<int, 6>{23, 33, 43, 53, 63, 73});
    Property tile25 = Property(1, "marsh", 25, 180, "bleu", 0, std::array<int, 6>{12, 22, 32, 42, 52, 62});
    Property tile26 = Property(1, "steppe", 26, 230, "vert", 0, std::array<int, 6>{16, 26, 36, 46, 56, 66});
    Property tile27 = Property(1, "gorge", 27, 140, "jaune", 0, std::array<int, 6>{8, 18, 28, 38, 48, 58});
    Property tile28 = Property(1, "cove", 28, 290, "rouge", 0, std::array<int, 6>{24, 34, 44, 54, 64, 74});
    Property tile29 = Property(1, "mesa", 29, 170, "bleu", 0, std::array<int, 6>{13, 23, 33, 43, 53, 63});
    Property tile30 = Property(1, "prairie", 30, 240, "vert", 0, std::array<int, 6>{17, 27, 37, 47, 57, 67});
    Property tile31 = Property(2, "go to jail", 31, 0, "", false, std::array<int, 6>{});
    Property tile32 = Property(3, "tax", 32, 150, "", false, std::array<int, 6>{});
    Property tile33 = Property(4, "card", 33, 0, "", false, std::array<int, 6>{});
    Property tile34 = Property(3, "tax", 34, 150, "", false, std::array<int, 6>{});
    Property tile35 = Property(5, "community chest", 35, 0, "", false, std::array<int, 6>{});
    Property tile36 = Property(3, "tax", 36, 150, "", false, std::array<int, 6>{});
    Property tile37 = Property(4, "card", 37, 0, "", false, std::array<int, 6>{});
    Property tile38 = Property(4, "card", 38, 0, "", false, std::array<int, 6>{});
    Property tile39 = Property(3, "tax", 39, 150, "", false, std::array<int, 6>{});
    Property tile40 = Property(4, "card", 40, 0, "", false, std::array<int, 6>{});

    std::array<Property,40> _tiles = {tile0, tile1, tile2, tile3, tile4, tile5, tile6, tile7, tile8, tile9,
        tile10, tile11, tile12, tile13, tile14, tile15, tile16, tile17, tile18, tile19,
        tile20, tile21, tile22, tile23, tile24, tile25, tile26, tile27, tile28, tile29, tile30,
        tile31, tile32, tile33, tile34, tile35, tile36, tile37, tile38, tile39};

    std::array<Card,40> _cards; //the board has 40 cards
    // std::array<Property,40> _tiles; //the board has 40 tiles

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
