//
// Created by lise babé on 22/05/2024.
//

#ifndef PROPERTY_H
#define PROPERTY_H
#include "Tile.h"
#include <string>
#include <array>

class Property : public Tile {
protected:
    int _price;
    std::string _group;
    int _owned;
    std::array<int,6> _rents;

public:
    Property(int id, std::string name, int price, std::string group, std::array<int,6> rents, int owned)
        : Tile(id, name),
          _price(price),
          _group(group),
          _rents(rents),
          _owned(owned) {
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
