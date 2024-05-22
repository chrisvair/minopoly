#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "game-state/GameState.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GameState::sayHello();
}

MainWindow::~MainWindow()
{
    delete ui;
}
