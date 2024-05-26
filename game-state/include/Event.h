//
// Created by lise babé on 22/05/2024.
//

#ifndef EVENT_H
#define EVENT_H
#include "Property.h"
#include <string>

class Event : protected Property{
protected:
    std::string type;
    std::string name;
};



#endif //EVENT_H
