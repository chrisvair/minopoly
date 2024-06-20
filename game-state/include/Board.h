#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <nlohmann/json.hpp>
#include "Card.h"
#include "Player.h"
#include "Property.h"

/**
    * This class represents the board of the game.
    * It contains the cards, the tiles, the players, the game number, the turn and the number of players.
**/

class Board {
protected:
    std::array<Card,40> _cards; //the board has 40 cards
    std::array<Property,40> _tiles; //the board has 40 tiles
    int gameNumber;
    int turn;
    int nbPlayers;

public:
    Board(){
        this->gameNumber = findFirstGameNumberAvailable();
    }
    Board(const std::array<Card, 40> &cards, const std::array<Property, 40> &tiles, int gameNumber)
            : _cards(cards),
              _tiles(tiles) {
    }

    void loadBoard(const std::string& filename);

    void saveBoard(const std::string& filename) const;

    void saveBoard() const;

    void genBots(const std::string& filename);

    Property& getTile(int id);

    Card drawCard(int id);

    void doAction(Card& card, Player& player);

    int findFirstGameNumberAvailable();

    int getNumberOfSavedGames();

    std::array<Card,40> & cards() {
        return _cards;
    }

    std::array<Player,4> players;

    int getGameNumber(){
        return gameNumber;
    }

    int getTurn(){
        return turn;
    }

    void setTurn(int turn){
        this->turn = turn;
    }

    int getNbPlayers(){
        return nbPlayers;
    }

    void setNbPlayers(int nbPlayers){
        this->nbPlayers = nbPlayers;
    };

    void savePlayers();

private:
    std::vector<Property> properties;  // Exemple

    void loadFromFile(const std::string& filename);

    void saveToFile(const std::string& filename, int gameNumber, int turn) const;

    std::array<Card,40> gameCards;

    std::array<Card,15> chanceCards;

    std::array<Card,16> communityChestCards;

    friend class JsonSerializer;
};

#endif //BOARD_H