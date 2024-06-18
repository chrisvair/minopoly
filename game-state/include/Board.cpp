//
// Created by lise babé on 22/05/2024.
//

#include "Board.h"
#include "JsonSerializer.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;


void Board::loadBoard(const std::string& filename) {
    loadFromFile(filename);
}

void Board::saveBoard() const {
    // Le nom du fichier est partieK.json avec k le numéro de la partie
    std::string path = "game-state/assets/";
    std::cout << "Saving game number " << gameNumber << std::endl;
    std::string filename = path + "partie" + std::to_string(gameNumber) + ".json";
    saveToFile(filename, gameNumber, turn);
}


void Board::loadFromFile(const std::string& filename) {
    JsonSerializer::deserialize(*this, filename);
}

void Board::saveToFile(const std::string& filename,int gameNumber, int turn) const {
    JsonSerializer::serialize(*this, filename, gameNumber, turn);
}

void Board::genBots(const std::string& filename) {
    JsonSerializer::loadBots(*this, filename);
}

Card Board::drawCard(int id) {
    return _cards[id];
}

Property& Board::getTile(int id) {
    return _tiles[id];
}

void Board::doAction(Card& card, Player& player) {
    if (card.getType() == 1 ) {
        std::cout << card.action() << std::endl;
        player.giveMoney(card.value());
    }
    else if (card.getType() == 2) {
        std::cout << card.action() << std::endl;
        player.takeMoney(card.value());
    }
    else if (card.getType() == 3) {
        std::cout << card.action() << std::endl;
        player.goToStart();
        player.move(card.value());
    }
    else if (card.getType() == 4) {
        std::cout << card.action() << std::endl;
        player.goToJail();
    }
    else if (card.getType() == 5) {
        std::cout << card.action() << std::endl;
        player.getOutOfJailCard();
    }
    else if (card.getType() == 6) {
        std::cout << card.action() << std::endl;
        player.goToStart();
    }
    else if (card.getType() == 7) {
        std::cout << card.action() << std::endl;
    }
}

int Board::findFirstGameNumberAvailable() {
    std::string path = "game-state/assets/";
    int i = 1;
    // Tant que partiek.json existe, on incrémente i
    while (std::filesystem::exists(path + "partie" + std::to_string(i) + ".json")) {
        i++;
    }

    return i;
}

int Board::getNumberOfSavedGames() {
    std::string path = "game-state/assets/";
    int i = 1;
    // Tant que partiek.json existe, on incrémente i
    while (std::filesystem::exists(path + "partie" + std::to_string(i) + ".json")) {
        i++;
    }

    return i-1;
}
