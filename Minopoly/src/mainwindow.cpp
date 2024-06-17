#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "game-state/GameState.h"
#include "Property.h"

#include "menudialog.h"
#include "ui_menudialog.h"

#include <QStyle>
#include <utility>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::string s = ""; //ex of calling backend
    Property p(1, s, 1, 1, s, 5, {1, 1, 1, 1, 1, 1}); //ex of calling backend

    // Transition with the menu window
    menu.setModal(true);// Makes the menu modal, meaning it blocks interaction with other windows until it's closed.
    connect(menu.ui->startPlay,SIGNAL(released()), this, SLOT(initializePlay()));
    menu.ui->nbPlayers->currentText().toInt();
    //int numberOfPlayers = menu.ui->nbPlayers->currentIndex();
    //std::cout << numberOfPlayers;
    menu.setWindowTitle("Minopoly Menu");
    setWindowTitle("Minopoly");
    menu.exec();

    // By default the buttons for the card display are hidden
    ui->BuyButton->hide();
    ui->PassButton->hide();
    ui->gridLayoutWidget_2->hide();
    ui->gridLayoutWidget_3->hide();
    ui->gridLayoutWidget_4->hide();
    ui->gridLayoutWidget_5->hide();

    // Initially, we disable the roll button until the player has entered the players' names
    ui->Roll->setDisabled(true);

    // Connect the roll button to the rollDie function
    connect(ui->Roll, &QPushButton::released, this, [&]() {
        rollDice();
        // Disable until the next move
        ui->Roll->setDisabled(true);
    });

    // Collect player names in list
    connect(ui->NameEnterEdit, &QLineEdit::returnPressed, this, [&]() {
        QString player_name = ui->NameEnterEdit->text();
        // Backend only supports std::string, not QString
        // TODO(backend): Call addPlayer(player_name.toStdString())

        // Create new list item for player and add it so new player is displayed in UI
        int current_player_number = ui->PlayerList->count();
        QString player_icon_path = QString("Minopoly/Assets/Player%1.png").arg(current_player_number + 1);
        // TODO(UI): Show balance next to name, or show it somewhere else?
        QListWidgetItem* new_player_item = new QListWidgetItem(QIcon(QPixmap(player_icon_path)), player_name);
        ui->PlayerList->addItem(new_player_item);

        // Mark whose player's turn it is
        if (ui->PlayerList->count() == 1) {
            paintActivePlayer(0);
        }

        // For simplicitly, clear the input field
        ui->NameEnterEdit->clear();

        // Disable input field (and enable dice rolling) once all players are added
        if (menu.ui->nbPlayers->currentText().toInt() == ui->PlayerList->count()) {
            ui->NameEnterEdit->setDisabled(true);
            ui->Roll->setDisabled(false);
            // // Hide the name entry related UI elements: hiding also the cards, but why?
            // ui->NameEnterEdit->hide();
            // ui->NameEnterQuestion->hide();
        }
    });

    // Buying action
    connect(ui->BuyButton, &QPushButton::clicked, this, [&]() {
        // TODO(backend): Reduce player money

        // TODO(UI): Somehow mark field as bought on the map (?)

        nextMove();
    });

    connect(ui->PassButton, &QPushButton::clicked, this, [&](){


        nextMove();
    });

}

void MainWindow::initializePlay()
{
    menu.hide(); // Hide the menu to go to the main window.

    // Load the Monopoly board image
    ui->Map->setPixmap(QPixmap("Minopoly/Assets/game_board.png"));
    ui->Map->setScaledContents(true);

    // Set the background
    ui->Background->setPixmap(QPixmap("Minopoly/Assets/menu_background.png"));
    setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    // Initialize player widgets
    int playerCount = menu.ui->nbPlayers->currentText().toInt(); // Get the number of players from the menu
    for (int i = 0; i < playerCount; ++i) {
        lbArr[i] = new QLabel(this);
        QPixmap playerPixmap(QString("Minopoly/Assets/Player%1.png").arg(i+1));
        lbArr[i]->setPixmap(playerPixmap.scaled(35, 35, Qt::KeepAspectRatio));
        lbArr[i]->setFixedSize(35, 35);
        // Initialize all players at position 0
        paintPlayer(i, 0);
    }
    paintDice(6, 6);
}

void MainWindow::rollDice() {
    // Call backend to get current player (TODO?)
    static int player_number = 0;

    int die1 = QRandomGenerator::global()->bounded(1, 7);
    int die2 = QRandomGenerator::global()->bounded(1, 7);

    qInfo() << die1;
    qInfo() << die2;

    paintDice(die1, die2);

    // Update player position according to dice
    // 1. Get player position from backend
    int position = 0;

    // 2. New position due to dice
    position += die1 + die2;

    // 3. Paint player at new position
    paintPlayer(player_number, position);

    // 4. Send updated position to backend (TODO?)

    // Show card in display area
    paintCard(position);

    // Show buttons
    ui->BuyButton->show();
    ui->PassButton->show();

    // Print card value in text field
    int card_value = 100;// TODO: Get from backend
    ui->BuyButton->setText(QString("Buy $%1").arg(card_value));

    player_number += 1;
    player_number %= 2;
}

void MainWindow::paintDice(int die1, int die2) {
    // Display the dice images on the labels
    QString die1Path = QString("Minopoly/Assets/die%1.png").arg(die1);
    QString die2Path = QString("Minopoly/Assets/die%1.png").arg(die2);

    QPixmap die1Pixmap(die1Path);
    QPixmap die2Pixmap(die2Path);

    ui->Die1->setPixmap(die1Pixmap.scaled(50, 50, Qt::KeepAspectRatio));
    ui->Die2->setPixmap(die2Pixmap.scaled(50, 50, Qt::KeepAspectRatio));
}

void MainWindow::paintPlayer(int i, int position) {
    auto [x, y] = getPlayerPosition(position);
    lbArr[i]->move(x, y);
    lbArr[i]->show();
}

void MainWindow::paintCard(int position) {
    int card_type = 2;
    if(card_type == 1){
        paintProperty(position);
    }else if (card_type == 2){
        paintStation(position);
    }
}

void MainWindow::paintProperty(int position) { // Get the colour and all the details of the card through position
    auto card_pixmap = QPixmap(QString("Minopoly/Assets/card_background.png"));
    ui->CardBackground->setPixmap(card_pixmap);
    ui->CardBackground->setScaledContents(true);

    int colour = 1; // TODO(backend): choode colour
    auto colour_pixmap = QPixmap(QString("Minopoly/Assets/colour%1.png").arg(colour));
    ui->Colour->setPixmap(colour_pixmap);
    ui->Colour->setScaledContents(true);


    auto info_card_pixmap = QPixmap(QString("Minopoly/Assets/card_background.png"));
    ui->InfoBackground->setPixmap(info_card_pixmap);
    ui->InfoBackground->setScaledContents(true);

    //Set card
    QString name = "LE GARDEN"; // TODO(backend)
    QString hotelPrice = "$200"; // TODO(backend)
    QString housePrice = "$100"; // TODO(backend)
    QString price = "$2000"; // TODO(backend)
    QString rent0H = "10"; // TODO(backend)
    QString rent1H = "100"; // TODO(backend)
    QString rent2H = "1000"; // TODO(backend)
    QString rent3H = "10000"; // TODO(backend)
    QString rent4H = "100000"; // TODO(backend)
    QString rentHotel = "10000000"; // TODO(backend)
    ui->NameLabel->setText(name);
    ui->PriceHotelLabel->setText(hotelPrice);
    ui->PriceHouseLabel->setText(housePrice);
    ui->PriceLabel->setText(price);
    ui->Rent0HLabel->setText(rent0H);
    ui->Rent1HLabel->setText(rent1H);
    ui->Rent2HLabel->setText(rent2H);
    ui->Rent3HLabel->setText(rent3H);
    ui->Rent4HLabel->setText(rent4H);
    ui->RentHotelLabel->setText(rentHotel);


    // Set card details based on position (replace with actual game logic)
    QString owner = "Player 1"; // TODO(backend)
    QString rent = "$200"; // TODO(backend)
    QString houses = "2"; // TODO(backend)
    QString hotels = "1"; // TODO(backend)
    ui->OwnerLabel->setText(owner);
    ui->RentLabel->setText(rent);
    ui->HousesLabel->setText(houses);
    ui->HotelsLabel->setText(hotels);

    // Show the vertical layout widget with the card details
    ui->gridLayoutWidget_2->show();
    ui->gridLayoutWidget_3->show();
}

void MainWindow::paintStation(int position) { // Get the details of the card through position
    auto card_pixmap = QPixmap(QString("Minopoly/Assets/card_background.png"));
    ui->CardBackground->setPixmap(card_pixmap);
    ui->CardBackground->setScaledContents(true);

    auto info_card_pixmap = QPixmap(QString("Minopoly/Assets/card_background.png"));
    ui->InfoBackground->setPixmap(info_card_pixmap);
    ui->InfoBackground->setScaledContents(true);

    auto logo_pixmap = QPixmap(QString("Minopoly/Assets/stan_logo.png"));
    ui->StationLogo->setPixmap(logo_pixmap);
    ui->StationLogo->setScaledContents(true);

    //Set card
    QString stationName = "ARTEM BLANDAN"; // TODO(backend)
    QString stationPrice = "10"; // TODO(backend)
    QString stationRent1 = "10"; // TODO(backend)
    QString stationRent2 = "100"; // TODO(backend)
    QString stationRent3 = "1000"; // TODO(backend)
    QString stationRent4 = "10000"; // TODO(backend)
    ui->StationNameLabel->setText(stationName);
    ui->StationPriceLabel->setText(stationPrice);
    ui->StationRent1Label->setText(stationRent1);
    ui->StationRent2Label->setText(stationRent2);
    ui->StationRent3Label->setText(stationRent3);
    ui->StationRent4Label->setText(stationRent4);


    // Set Stations Details
    QString owner1 = "Player 1"; // TODO(backend)
    QString owner2 = "Player 1"; // TODO(backend)
    QString owner3 = "Player 2"; // TODO(backend)
    QString owner4 = "Player 1"; // TODO(backend)
    ui->Station1OwnerLabel->setText(owner1);
    ui->Station2OwnerLabel->setText(owner2);
    ui->Station3OwnerLabel->setText(owner3);
    ui->Station4OwnerLabel->setText(owner4);

    // Show the vertical layout widget with the card details
    ui->gridLayoutWidget_4->show();
    ui->gridLayoutWidget_5->show();
}

void MainWindow::paintActivePlayer(int player_number) {
    ui->PlayerList->item(player_number)->setBackground(Qt::lightGray);
}

void MainWindow::paintInactivePlayer(int player_number) {
    ui->PlayerList->item(player_number)->setBackground(Qt::transparent);
}

void MainWindow::nextMove() {
    ui->BuyButton->hide();
    ui->PassButton->hide();
    ui->CardBackground->clear();
    ui->InfoBackground->clear();
    ui->Colour->clear();
    ui->gridLayoutWidget_2->hide();
    ui->gridLayoutWidget_3->hide();
    ui->gridLayoutWidget_4->hide();
    ui->gridLayoutWidget_5->hide();


    ui->Roll->setDisabled(false);

    // TODO(backend): Switch active player
    static int currently_active_player = 0;
    paintInactivePlayer(currently_active_player);
    currently_active_player = (currently_active_player + 1) % 2;
    paintActivePlayer(currently_active_player);

    // Now we wait for a dice roll
}

std::pair<int, int> MainWindow::getPlayerPosition(int position) {
    if (position < 0 || position > 39) {
        throw std::out_of_range("Position must be between 0 and 39");
    }

    int boardSize = 600;
    int startX = 780; // Start from the bottom right
    int startY = 570; // Start from the bottom right
    int cellSize = 49; // Divide the board into 11 parts

    int x = startX;
    int y = startY;

    if (position < 10) {
        // Bottom side, right to left
        x = startX - position * cellSize;
    } else if (position == 10) {
        // Left side, bottom to top
        x = startX - 10 * cellSize - 20;
    } else if (position < 20) {
        // Left side, bottom to top
        x = startX - 10 * cellSize - 20;
        y = startY - (position - 10) * cellSize - 20;
    } else if (position == 20) {
        // Left side, bottom to top
        x = startX - 10 * cellSize - 20;
        y = startY - 10 * cellSize - 40;
    } else if (position < 30) {
        // Top side, left to right
        x = startX - 10 * cellSize + (position - 20) * cellSize;
        y = startY - 10 * cellSize - 40;
    } else if (position == 30) {
        // Top side, left to right
        x = startX - 10 * cellSize + 10 * cellSize + 20;
        y = startY - 10 * cellSize - 40;
    } else {
        // Right side, top to bottom
        x = startX + 10 * cellSize - 10 * cellSize + 20;
        y = startY - 10 * cellSize + (position - 30) * cellSize - 20;
    }

    return std::make_pair(x, y);
}

MainWindow::~MainWindow()
{
    delete ui;
}
