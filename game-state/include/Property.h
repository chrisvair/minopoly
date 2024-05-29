//
// Created by lise babé on 22/05/2024.
//

#ifndef PROPERTY_H
#define PROPERTY_H
#include "Tile.h"
#include <string>
#include <array>
#include <utility>

class Property : public Tile {
protected:
    int _id;
    int _price;
    std::string _group;
    int _owned;
    std::array<int,6> _rents;

public:

    Property(int type, std::string &name, int position, int price, std::string &group, int owned,
        const std::array<int, 6> &rents)
        : Tile(type, name, position),
          _price(price),
          _group(group),
          _owned(owned),
          _rents(rents),
          _id(position){}

    int getId() const {
        return _id;
    }
    int price() const {
        return _price;
    }

    std::string group() const {
        return _group;
    }

    int owned() const {
        return _owned;
    }

    std::array<int,6> rents() const {
        return _rents;
    }

    void setPrice(int price) {
        _price = price;
    }

    void setGroup(std::string group) {
        _group = group;
    }

    void setOwned(int owned) {
        _owned = owned;
    }

    void setRents(std::array<int,6> rents) {
        _rents = rents;
    }
};




#endif //PROPERTY_H
