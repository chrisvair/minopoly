#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include <array>
#include <utility>
#include <iostream>
#include <nlohmann/json.hpp>


/**
     * This class is used to represent a property in the game.
     * A property represent a tile on the board.
     * It can either be a property or an event, it is given by the type.
 */
class Property {
protected:
    int _type;
    std::string _name;
    int _position;
    int _id;
    int _price;
    std::string _group;
    int _owned;
    std::array<int,6> _rents;
    int _house = 0;
    int _hostel = 0;
    int _houseCost;
    int _hotelCost;

public:
    Property()= default;
    Property(int type, std::string name, int position, int price, std::string group, int owned,
        const std::array<int, 6> &rents)
        : _price(price),
          _group(group),
          _owned(owned),
          _rents(rents),
          _type(type),
          _name(name),
          _position(position),
          _id(position){};

    void from_json(const nlohmann::json& j, Property& property);

    int rent();

    void isSell();

    void to_json(nlohmann::json& j, const Property& property) const ;

    int price() const {
        return _price;
    }

    int house() const {
        return _house;
    }

    void buyHouse() {
        _house++;
    }

    int hostel() const {
        return _hostel;
    }

    void buyHostel() {
        _hostel++;
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

    void setOwned(int owned) {
        _owned = owned;
    }

    int type() {
        return _type;
    }

    int id() {
        return _position;
    }

    std::string name() {
        return _name;
    }

    int costHouse() {
        return _houseCost;
    }

    int costHostel() {
        return _hotelCost;
    }

    int getType() {
        return _type;
    }

    int getPosition() {
        return _position;
    }
};

#endif //PROPERTY_H