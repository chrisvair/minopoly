# Minopoly

## Authors
- Lise BABÉ
- Aymeri GERMAIN
- Christina VAIRELLES

## The Project

This project is a digital implementation of the classic board game Monopoly personalized with the theme of our school.
It was created as a second-year C++ project at École Nationale des Mines de Nancy.

### General Information

The project is implemented using C++ due to its efficiency, object-oriented features, and suitability for handling the complex logic and data structures required in a Monopoly game. The game data is managed through the integration of the [nlohmann_json](https://github.com/nlohmann/json) library for JSON serialization. The graphical user interface is developed using the Qt framework.

## Project Structure
- **game-state/**: Manages the game state, including players, properties, and game rules.
- **Minopoly/**: Contains the main application code including UI elements.
- **third_party/**: Contains third-party dependencies: nlohmann_json library.

To be more specific, *Minopoly* is used to manage the UI elements and the window displaying the game. To link the main window with the backend, we use the *Game* class. The Game class has access to all the other classes, which allows it to modify the game state. The *nlohmann_json library* is used to read and write JSON files. If you follow the right data structure, you can import your own cards and games.

## How to Use it

### Setup

- **CMake**: version 3.5 or higher
- **C++**: version 20
- **Qt5 or Qt6** (with Widgets module)
- **nlohmann_json** library

#### Steps to Run the Program

1. Clone the repository to your local machine.
  ```bash
    git clone https://github.com/chrisvair/minopoly.git
    cd minopoly
  ```
3. Install the nlohmann_json library
 ```bash
    git submodule update --init --recursive
 ```
4. Open the project in Qt Creator (or any other preferred IDE). 
    - **Note**: Ensure to set the working directory to the root directory of the project ("minopoly") in the IDE's "edit configuration" settings.
5. Build the project.
6. Run the executable to start the game.???

**Note**: The project was developed for iOS; if you are using LINUX, you need to modify the CMake configuration in the Minopoly folder.

### Playing explanation

1. **Starting the Game**:
    - Upon launching the application, a menu dialog will appear, asking the user to either continue a previous game or start a new one.
    - Select the number of physical players who will play the game.
    - After selecting the game options and clicking "Play," the main game window will appear.

2. **Setup the Players**:
    - Enter the names of the players in the provided fields.
    - Each player is assigned a token and starting money balance, and they are placed on the start cell.
    - Players take turns, which is visualized by the selection of their name.

3. **Game Rules**:
    - **Roll Dice**: Players roll the dice to move around the board.
    - **Property Management**: Players can buy, rent, or build on properties they land on.
    - **Chance Cards**: Players may draw Chance cards, which can result in gaining money or changing position on the board.
    - **Community Chest Cards**: Players may draw Community Chest cards, which typically result in gaining money.
    - Other special cells on the board have unique effects explained within the game.

4. **End of the Game**:
    - The game concludes when certain conditions are met, such as a player going bankrupt or a predefined number of turns is reached.
    - An endgame dialog will appear, summarizing the game results and declaring the winner.
