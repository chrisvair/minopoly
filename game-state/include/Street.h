//
// Created by lise babé on 22/05/2024.
//

#ifndef STREET_H
#define STREET_H
#include "Property.h"


class Street : protected Property {
protected:
    int housePrice;
    int nbHouses;
    int hotelPrice;
    bool hotel;
};



#endif //STREET_H
