//
// Created by lise babé on 22/05/2024.
//

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