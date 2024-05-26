//
// Created by lise babé on 22/05/2024.
//

#ifndef PROPERTY_H
#define PROPERTY_H
#include "Tile.h"
#include <string>
#include <array>

class Property : protected Tile {
protected:
    int price;
    std::string group;
    int owned;
    std::array<int,6> rents;
};



#endif //PROPERTY_H
