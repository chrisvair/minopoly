#include "mainwindow.h"
#include "Game.h"
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    auto game = Game();

    game.start();

    game.play();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
