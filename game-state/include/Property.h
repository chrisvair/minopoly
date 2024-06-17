//
// Created by lise babé on 22/05/2024.
//

#ifndef PROPERTY_H
#define PROPERTY_H
#include "Tile.h"
#include <string>
#include <array>
#include <utility>
#include <iostream>
#include <nlohmann/json.hpp>





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


    int getId() const {
        return _id;
    }
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

    void from_json(const nlohmann::json& j, Property& property) {
        j.at("type").get_to(property._type);
        j.at("name").get_to(property._name);
        j.at("position").get_to(property._position);
        j.at("price").get_to(property._price);
        j.at("group").get_to(property._group);
        j.at("owned").get_to(property._owned);
        j.at("rents").get_to(property._rents);
        j.at("houseCost").get_to(property._houseCost);
        j.at("hotelCost").get_to(property._hotelCost);
        j.at("house").get_to(property._house);
        j.at("hotel").get_to(property._hostel);
    }
    int rent();

    void isSell();
};




#endif //PROPERTY_H
