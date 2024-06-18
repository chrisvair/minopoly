//
// Created by lise babé on 22/05/2024.
//

#ifndef TILE_H
#define TILE_H

#include <string>

class Tile {
protected :
    int _type{};
    std::string _name;
    int _position{};

public:
    Tile(){};

    Tile(int type, const std::string &name, int position)
        : _type(type),
          _name(name),
          _position(position) {
    }

    int type() const {
        return _type;
    }

    std::string name() const {
        return _name;
    }

    int getPosition() const {
        return _position;
    }


};



#endif //TILE_H
