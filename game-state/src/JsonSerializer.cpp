//
// Created by Aymeri Germain on 29/05/2024.
//

#include "JsonSerializer.h"
#include <fstream>
#include <iostream>


using json = nlohmann::json;


void JsonSerializer::serialize(const Board& board, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier " << filename << std::endl;
        return;
    }
    nlohmann::json jsonData;
    to_json(jsonData, board);
    file << jsonData.dump(4);
    file.close();
}

void JsonSerializer::deserialize(Board& board, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier " << filename << std::endl;
        return;
    }
    json data = json::parse(file);
    // Désérialiser les cases
    std::vector<Property> properties;
    for (const auto& property_json : data["properties"]) {
        Property property;
        property.from_json(property_json, property);
        properties.push_back(property);
        board._tiles[property.id()] = property;
    }
    // Désérialiser les cartes
    std::vector<Card> cards;
    for (const auto& card_json : data["cards"]) {
        Card card;
        card.from_json(card_json, card);
        cards.push_back(card);
        board._cards[card.getId()] = card;
    }

    // Désérialiser les joueurs
    for (const auto& player_json : data["players"]) {
        Player player;
        player.from_json(player_json, player);
        board.players[player.getId()] = player;
    }

    // Afficher les noms des propriétés
    /*std::cout << "\nNoms des propriétés :" << std::endl;
    for (auto& property : properties) {
        std::cout << "Property: " << property.name() << std::endl;
    }*/
}

void JsonSerializer::to_json(json& j, const Board& board) {
    //j["properties"] = board.properties;
    //j["players"] = board.players;
}