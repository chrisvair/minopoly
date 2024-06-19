#include "Property.h"

int Property::rent() {
    if (_hostel == 1) {
        return _rents[4];
    }
    return _rents[_house];
}

void Property::isSell() {
    _owned = 0;
    _house = 0;
    _hostel = 0;
}

void Property::from_json(const nlohmann::json& j, Property& property) {
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

void Property::to_json(nlohmann::json& j, const Property& property) const {
    j = nlohmann::json{{"type", property._type},
                       {"name", property._name},
                       {"position", property._position},
                       {"price", property._price},
                       {"group", property._group},
                       {"owned", property._owned},
                       {"rents", property._rents},
                       {"houseCost", property._houseCost},
                       {"hotelCost", property._hotelCost},
                       {"house", property._house},
                       {"hotel", property._hostel}};
}