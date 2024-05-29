#include "mainwindow.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    std::string name1;
    std::string name2;

    std::cout << "Player 1 name : ";
    std::cin >> name1;
    auto player1 = Player(1, name1, 1500, 0, false);

    std::cout << "Player 2 name : ";
    std::cin >> name2;
    auto player2 = Player(1, name2, 1500, 0, false);

    //Board board = Board();
    //
    auto players = std::array<Player,2>{player1, player2};
    auto game = Game(players, 5, 100000, 100000);
    //
    game.Play();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
