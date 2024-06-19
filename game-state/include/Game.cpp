#include "Game.h"

void Game::nextTurn() {
    _currentPlayer++;
    if (_currentPlayer == _nbPlayers + 1) {
        _currentPlayer = 1;
        _nbTurns--;
    }
    if (_nbTurns == 0) {
        _currentPlayer = -1;
        return;
    }
    if (playersBankrupt() == _nbPlayers - 1) {
        _currentPlayer = -2;
        return;
    }
    Player& player = _players[_currentPlayer-1];
    //if in jail we check if you can get out of it
    if (player.isBankrupt()) {
        nextTurn();
    }
    if (player.isInJail() == 3) {
        player.getOutOfJail();
        nextTurn();
    } else if(player.isInJail()!=0) {
        player.oneMoreTurnInJail();
        nextTurn();
    }
}

void Game::selectNumberOfPlayers() {
    int nbPlayers;
    int nbBots;
    // if players have been loaded
    if (_players[0].getPlayerName() != "") {
        std::cout << "4 Players have been loaded" << std::endl;
        return;
    }

    // if not, we ask the user to enter the number of real players
    std::cout << "With how many real players do you want to play with ? (2-4)" << std::endl;
    std::cin >> nbPlayers;
    nbBots = 4 - nbPlayers;
    std::cout << "You will play with " << nbPlayers << " players and " << nbBots << " bots" << std::endl;

    //Add the real players to the players array
    for (int i = 0; i < nbPlayers; i++) {
        std::string name;
        std::cout << "Player " << i+1 << " name : ";
        std::cin >> name;
        auto player = Player(1,i+1, name, 1500, 0, false);
        _players[i] = player;
    }
    //Create a board of bots to import bots from a file
    Board boardBots = Board();
    boardBots.genBots("game-state/assets/bots.json");

    //Add the bots to the players array
    for (int i = nbPlayers; i < 4; i++) {
        _players[i] = boardBots.players[i-nbPlayers];
    }

    std:: cout << "The 4 players are : " << std::endl;
    for (int i = 0; i < 4; i++) {
        // Si c'est un bot, on lui donne un id
        if (_players[i].type() == 0){
            _players[i].setId(i+1);
        }
        std::cout << _players[i].getPlayerName() << std::endl;
    }
}

int Game::playersBankrupt(){
    int nbPlayerBanrkurpt = 0;
    for (int i = 0; i < _players.size(); i++) {
        if (_players[i].isBankrupt()) {
            nbPlayerBanrkurpt++;
        }
    }
    return nbPlayerBanrkurpt;
}


void Game::chooseGame() {
    if (_board.getNumberOfSavedGames() != 0) {
        std::cout << "Do you want to load a saved game ? (y/n)" << std::endl;
        std::string answer;
        std::cin >> answer;
        if (answer == "y") { // load a saved game
            std::cout << "They are " << _board.getNumberOfSavedGames() << " saved games :" << std::endl;
            for (int i = 1; i <= _board.getNumberOfSavedGames(); i++) {
                std::cout << "Game number " << i << std::endl;
            }
            std::cout << "Which one do you want to load ?" << std::endl;
            int gameNumber;
            while (true) {
                std::cin >> gameNumber;
                if (gameNumber > _board.getNumberOfSavedGames()) {
                    std::cout << "This game doesn't exist, please enter a valid number" << std::endl;
                } else {
                    break;
                }
            }
            _board.loadBoard("game-state/assets/partie" + std::to_string(gameNumber) + ".json");
            _players = _board.players;
            _turn = _board.getTurn();
            std::cout << "You are starting the game number " << _board.getGameNumber() << std::endl;
        } else if (answer == "n") {// start a new game
            std::cout << "You will start a new game" << std::endl;
            _board.loadBoard("game-state/assets/monopoly.json");
            std::cout << "You are starting the game number " << _board.getGameNumber() << std::endl;
            selectNumberOfPlayers();
        }
    } else {
        std::cout << "There is no saved games. Let's start a new game" << std::endl;
        _board.loadBoard("game-state/assets/monopoly.json");
        std::cout << "You are starting the game number " << _board.getGameNumber() << std::endl;
        selectNumberOfPlayers();
    }
}

std::string Game::getWinner() {
    for (int i = 0; i < _players.size(); i++) {
        if (!_players[i].isBankrupt()) {
            return _players[i].getPlayerName();
        }
    }
    return "Personne n'";
}

std::array<int,2> Game::rollDice() {
    srand(time(0));
    return {rand() % 6 + 1, rand() % 6 + 1};
}

void Game::addPlayer(std::string playerName) {
    Player player = Player(1,_nbPlayers+1,playerName,1500,0,0);
    _players[_nbPlayers] = player;
    _nbPlayers++;
}

int Game::movePlayer(int amount) {
    _players[_currentPlayer-1].move(amount);
    return _players[_currentPlayer-1].getPosition();
}

void Game::build() {
    int position = _players[_currentPlayer-1].getPosition();
    if (_board.getTile(position).house() == 4) {
        _players[_currentPlayer-1].buyHostel(_board.getTile(position));
    }
    else {
        _players[_currentPlayer-1].buyHouse(_board.getTile(position));
    }
}

void Game::payRent(){
    int position = _players[_currentPlayer-1].getPosition();
    _players[_currentPlayer-1].payRent(_players[_board.getTile(position).owned()-1],_board.getTile(position));
}

void Game::payTax() {
    _players[_currentPlayer-1].payTax(_board.getTile(_players[_currentPlayer-1].getPosition()).price());
    _communityBank += _board.getTile(_players[_currentPlayer-1].getPosition()).price();
}

void Game::winCommunityChest() {
    _players[_currentPlayer-1].giveMoney(_communityBank);
    emptyCommunityBank();
}

std::string Game::doActionCard() {
    Card newCard = _board.drawCard(rand() % 40);
    _board.doAction(newCard, _players[_currentPlayer-1]);
    return newCard.action();
}