//
// Created by Aymeri Germain on 29/05/2024.
//

#include "JsonSerializer.h"
#include <fstream>
#include <iostream>


using json = nlohmann::json;


void JsonSerializer::serialize(const Board& board, const std::string& filename, int gameNumber) {
    json data;
    // Sérialiser les cases

    std::cout << "Serializing properties" << std::endl;
    for (const auto& property : board._tiles) {
        json property_json;
        property.to_json(property_json, property);
        data["properties"].push_back(property_json);
    }

    // Sérialiser les cartes
    std::cout << "Serializing cards" << std::endl;
    for (const auto& card : board._cards) {
        json card_json;
        card.to_json(card_json, card);
        data["cards"].push_back(card_json);
    }


    // Sérialiser les joueurs
    std::cout << "Serializing players" << std::endl;
    for (const auto& player : board.players) {
        json player_json;
        std::cout << player.getId() << std::endl;
        std::cout << player._money << std::endl;
        player.to_json(player_json, player);
        std::cout << player_json << std::endl;
        data["players"].push_back(player_json);
    }

    // Ajouter la date et le numéro de la partie
    // Obtenir la date courante
    std::time_t t = std::time(nullptr);
    char date_str[100];
    if (std::strftime(date_str, sizeof(date_str), "%Y-%m-%d %H:%M:%S", std::localtime(&t))) {
        data["date"] = date_str;
    }
    data["gameNumber"] = gameNumber;

    // Écrire le fichier
    std::cout << filename << std::endl;
    std::ofstream file(filename);
    file << data.dump(4);
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

void JsonSerializer::loadBots(Board& board, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier " << filename << std::endl;
        return;
    }
    json data = json::parse(file);
    // Désérialiser les joueurs
    int i = 0;
    for (const auto& player_json : data["players"]) {
        Player player;
        player.from_json(player_json, player);
        board.players[i] = player;
        i++;
    }
}