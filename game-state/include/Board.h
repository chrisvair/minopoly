//
// Created by lise babé on 22/05/2024.
//

#ifndef BOARD_H
#define BOARD_H
#include <array>
#include <nlohmann/json.hpp>
#include "Card.h"
#include "Player.h"
#include "Property.h"
#include "Player.h"


class Board {
protected:
    std::array<Card,40> _cards; //the board has 40 cards
    std::array<Property,40> _tiles; //the board has 40 tiles

public:
    Board(){}
    Board(const std::array<Card, 40> &cards, const std::array<Property, 40> &tiles)
            : _cards(cards),
              _tiles(tiles) {
    }

    std::array<Card,40> & cards() {
        return _cards;
    }
    /*
    std::array<Property,40> & tiles() {
        return _tiles;
    }
     */
    void loadBoard(const std::string& filename);
    void saveBoard(const std::string& filename) const;

    Property& getTile(int id);
    Card drawCard(int id);

    void doAction(Card& card, Player& player);

private:
    std::vector<Player> players;  // Exemple
    std::vector<Property> properties;  // Exemple
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
    std::array<Card,40> gameCards;
    std::array<Card,15> chanceCards;
    std::array<Card,16> communityChestCards;


    friend class JsonSerializer;

};



#endif //BOARD_H
