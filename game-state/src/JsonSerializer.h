#ifndef MINOPOLY_JSONSERIALIZER_H
#define MINOPOLY_JSONSERIALIZER_H

#include <string>
#include <nlohmann/json.hpp>
#include "Game.h"
#include "Property.h"

/**
     * This class is used to serialize and deserialize the game state.
     * It can be used to save the game state to a file and load it back.
 **/

class JsonSerializer {
public:
    static void serialize(Board board, const std::string& filename, int gameNumber, int turn);
    static void deserialize(Board& board, const std::string& filename);
    static void loadBots(Board& board, const std::string& filename);

private:
    static void from_json(const nlohmann::json& j, Board& board);
    static void to_json(nlohmann::json& j, const Board& board);
};

#endif
