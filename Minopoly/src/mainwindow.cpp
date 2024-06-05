#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "game-state/GameState.h"

#include "menudialog.h"
#include "ui_menudialog.h"

#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load the Monopoly board image
    QString path = QString("Assets/game_board.png");
    QIcon icon = style()->standardIcon(QStyle::SP_DialogOkButton);
    icon = QIcon(path);

    QPixmap pixmap = icon.pixmap(QSize(400, 400));

    //QPixmap pixmap("game_board.png");

    // Set the pixmap for the QLabel of the board
    if (pixmap.isNull()) {
        qDebug() << "Error loading image file.";
    } else {
        // Scale the image to fit the initial QLabel size while keeping aspect ratio
        ui->Map->setPixmap(pixmap.scaled(ui->Map->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->Map->setAlignment(Qt::AlignCenter); // Ensure QLabel is centered

        //ui->Map->setPixmap(pixmap);
    }

    menu.setModal(true);// Makes the menu modal, meaning it blocks interaction with other windows until it's closed.
    connect(menu.ui->startPlay,SIGNAL(released()), this, SLOT(InitialisePlay()));
    menu.ui->nbPlayers->currentText().toInt();
    menu.setWindowTitle("Minopoly Menu");
    setWindowTitle("Minopoly");
    menu.exec();

}

void MainWindow::InitialisePlay()
{
    menu.hide(); // Go to mainwindow.
}

MainWindow::~MainWindow()
{
    delete ui;
}
