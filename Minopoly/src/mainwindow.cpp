#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "game-state/GameState.h"

#include "menudialog.h"
#include "ui_menudialog.h"

#include <QStyle>
#include <utility>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Transition with the menu window
    menu.setModal(true);// Makes the menu modal, meaning it blocks interaction with other windows until it's closed.
    connect(menu.ui->startPlay,SIGNAL(released()), this, SLOT(InitialisePlay()));
    menu.ui->nbPlayers->currentText().toInt();
    //int numberOfPlayers = menu.ui->nbPlayers->currentIndex();
    //std::cout << numberOfPlayers;
    menu.setWindowTitle("Minopoly Menu");
    setWindowTitle("Minopoly");
    menu.exec();

    // Load the Monopoly board image
    QString path = QString("Assets/game_board.png");
    QIcon icon = style()->standardIcon(QStyle::SP_DialogOkButton);
    icon = QIcon(path);
    QPixmap pixmap = icon.pixmap(QSize(600, 600));
    ui->Map->setPixmap(pixmap);

    // Set the background
    QString back_path = QString("Assets/menu_background.png");
    QPixmap image(back_path);
    QIcon icon_back = style()->standardIcon(QStyle::SP_DialogOkButton);
    icon_back = QIcon(back_path);
    QPixmap pixmap_back = icon_back.pixmap(QSize(1000, 1000));
    ui->Background->setPixmap(pixmap_back);
    setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    // Initialize player widgets
    int playerCount = 1;
    for (int i = 0; i < playerCount; ++i)
    {
        lbArr[i] = new QLabel(this);
        QString playerIconPath = QString("Assets/Player%1.png").arg(i+1);
        QPixmap playerPixmap(playerIconPath);
        lbArr[i]->setPixmap(playerPixmap.scaled(35, 35, Qt::KeepAspectRatio));
        lbArr[i]->setFixedSize(35, 35);
        auto [x, y] = getPlayerPosition(32);
        lbArr[i]->move(x, y);
        lbArr[i]->show();
    }

}

std::pair<int, int> MainWindow::getPlayerPosition(int position) {
    if (position < 0 || position > 39) {
        throw std::out_of_range("Position must be between 0 and 39");
    }

    int boardSize = 600;
    int startX = 285;
    int startY = 40;
    int cellSize = 49; // Divide the board into 11 parts

    int x = startX;
    int y = startY;

    if (position < 10) {
        // Top side, left to right
        x = startX + position * cellSize;
    } else if(position == 10) {
        // Right side, top to bottom
        x = startX + position * cellSize + 20;
    } else if (position < 20) {
        // Right side, top to bottom
        x = startX + 10 * cellSize + 20;
        y = startY + 20 + (position - 10) * cellSize;
    } else if (position == 20) {
        // Right side, top to bottom
        x = startX + 10 * cellSize + 20;
        y = startY + 40 + (position - 10) * cellSize;
    } else if (position < 30) {
        // Bottom side, right to left
        x = startX + (10 - (position - 20)) * cellSize;
        y = startY + 11 * cellSize;
    } else if (position == 30) {
        // Bottom side, right to left
        x = startX + (10 - (position - 20)) * cellSize - 20;
        y = startY + 11 * cellSize;
    } else {
        // Left side, bottom to top
        x = startX - 20;
        y = startY + (10 - (position - 30)) * cellSize + 15;
    }

    return std::make_pair(x, y);
}


void MainWindow::InitialisePlay()
{
    menu.hide(); // Go to mainwindow.
}

MainWindow::~MainWindow()
{
    delete ui;
}
