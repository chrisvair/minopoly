//
// Created by lise babé on 22/05/2024.
//

#ifndef CHANCE_H
#define CHANCE_H
#include "Card.h"
#include "Event.h"


class Chance : protected Event {
    Card drawCard();
};



#endif //CHANCE_H
