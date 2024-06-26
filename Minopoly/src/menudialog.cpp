#include "menudialog.h"
#include "ui_menudialog.h"
#include "../src/Game.h"


MenuDialog::MenuDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenuDialog)
{
    ui->setupUi(this);


    ui->gameSelection->addItem("Nouvelle Partie");
    Game game = Game();
    int numberOfSavedGames = game.getNumberOfSavedGames();
    for(int i = 1; i <= numberOfSavedGames; i++)
    {
        QString a = QString::number(i);
        ui->gameSelection->addItem("Partie " + a);
    }

    for(int i = 2; i <= 4; i++)
    {
        QString a = QString::number(i);
        ui->nbPlayers->addItem(a);
    }

    QString path = QString("Minopoly/Assets/menu_background.png");
    QPixmap image(path);
    QIcon icon = style()->standardIcon(QStyle::SP_DialogOkButton);
    icon = QIcon(path);
    QPixmap pixmap = icon.pixmap(QSize(1000, 1000));
    ui->back->setPixmap(pixmap);
    setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
}

MenuDialog::~MenuDialog()
{
    delete ui;
}