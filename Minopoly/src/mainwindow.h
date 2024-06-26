#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QRandomGenerator>
#include <array>
#include <utility>
#include "menudialog.h"
#include "ui_menudialog.h"
#include "endgamedialog.h"
#include "../src/Game.h"
#include "./ui_mainwindow.h"

/**
    * This class is the main window of the game.
    * It allows the user to play the game.
    * The class is responsible for the display of the game, and the interactions with the backend.
 **/

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void initializePlay();
    void rollDice();
    void nextMove();
    void paintDice(int die1, int die2);
    void paintPlayer(int player_number, int position);
    void paintCard(int position);
    void paintActivePlayer(int player_number);
    void paintInactivePlayer(int player_number);
    void paintProperty(int position);
    void paintStation(int position);
    void paintChance();
    void paintTreasure();
    void paintCardByPosition(int position);
    void setPlayerList();
    void setPlayerListFromALoadedGame();
    void updateDisplay();
    void checkEndGame();
    void updatePlayersPosition();
    void saveAndClose();
    void onLand();

private:
    Ui::MainWindow *ui;
    MenuDialog menu;
    QLabel* lbArr[6]; // Adjust the size according to the maximum number of players
    Game _game{0,std::array<Player,4>(), 20, 10000, 0, Board()};
    std::pair<int, int> getPlayerPosition(int position);
    std::map<std::string, int> dictionnaire = {{"marron", 1}, {"bleu clair", 2}, {"violet", 3},{"orange", 4}, {"rouge", 5}, {"jaune", 6},{"vert", 7}, {"bleu foncé", 8}};

};

#endif // MAINWINDOW_H
