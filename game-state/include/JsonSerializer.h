//
// Created by Aymeri Germain on 29/05/2024.
//

#ifndef MINOPOLY_JSONSERIALIZER_H
#define MINOPOLY_JSONSERIALIZER_H


#include <string>
#include <nlohmann/json.hpp>
#include "Game.h"

class JsonSerializer {
public:
    static void serialize(const Game& game, const std::string& filename);
    static void deserialize(Game& game, const std::string& filename);

private:
    static void from_json(const nlohmann::json& j, Game& game);
    static void to_json(nlohmann::json& j, const Game& game);
};

#endif //MINOPOLY_JSONSERIALIZER_H
