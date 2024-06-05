//
// Created by Aymeri Germain on 29/05/2024.
//

#include "JsonSerializer.h"
#include <fstream>
#include <iostream>

void JsonSerializer::serialize(const Game& game, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier " << filename << std::endl;
        return;
    }
    nlohmann::json jsonData;
    to_json(jsonData, game);
    file << jsonData.dump(4);
    file.close();
}

void JsonSerializer::deserialize(Game& game, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier " << filename << std::endl;
        return;
    }
    nlohmann::json jsonData;
    file >> jsonData; // On lit le fichier JSON dans jsonData
    file.close();
    from_json(jsonData, game);
}

void JsonSerializer::from_json(const nlohmann::json& j, Game& game) {
    // Implémentez la logique de désérialisation de Game à partir de JSON
}

void JsonSerializer::to_json(nlohmann::json& j, const Game& game) {
    // Implémentez la logique de sérialisation de Game vers JSON
}
