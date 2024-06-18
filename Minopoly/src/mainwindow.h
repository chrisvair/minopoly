#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "menudialog.h"
#include "Game.h"

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
    void paintDice(int die1, int die2);
    void paintPlayer(int player_number, int position);
    void paintCard(int position);
    void paintActivePlayer(int player_number);
    void paintInactivePlayer(int player_number);
    void nextMove();
    void paintProperty(int position);
    void paintStation(int position);
    void paintChance();
    void paintTreasure();
    void paintCardByPosition(int position);
    void setPlayerList();
    void setPlayerListFromALoadedGame();
    void updateDisplay();
    void updatePosition();

private:
    Ui::MainWindow *ui;
    MenuDialog menu;
    QLabel* lbArr[6]; // Adjust the size according to the maximum number of players
    Game _game{0,std::array<Player,4>(), 20, 10000, 0, Board()};
    std::pair<int, int> getPlayerPosition(int position);
    std::map<std::string, int> dictionnaire = {{"marron", 1}, {"bleu clair", 2}, {"violet", 3},{"orange", 4}, {"rouge", 5}, {"jaune", 6},{"vert", 7}, {"bleu foncé", 8}};

};

#endif // MAINWINDOW_H
