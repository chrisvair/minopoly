#include "Card.h"

void Card::from_json(const json& j, Card& card) {
    j.at("id").get_to(card._id);
    j.at("type").get_to(card._type);
    j.at("description").get_to(card._action);
    j.at("value").get_to(card._value);
}