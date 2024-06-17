//
// Created by Aymeri Germain on 29/05/2024.
//

#ifndef MINOPOLY_JSONSERIALIZER_H
#define MINOPOLY_JSONSERIALIZER_H


#include <string>
#include <nlohmann/json.hpp>
#include "Game.h"
#include "Property.h"

class JsonSerializer {
public:
    static void serialize(const Board& board, const std::string& filename, int gameNumber);
    static void deserialize(Board& board, const std::string& filename);
    static void loadBots(Board& board, const std::string& filename);

private:
    static void from_json(const nlohmann::json& j, Board& board);
    static void to_json(nlohmann::json& j, const Board& board);
};

#endif
