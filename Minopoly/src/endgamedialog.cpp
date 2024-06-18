#include "endgamedialog.h"
#include "ui_endgamedialog.h"

EndGameDialog::EndGameDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EndGameDialog)
{
    ui->setupUi(this);
}

EndGameDialog::~EndGameDialog()
{
    delete ui;
}

void EndGameDialog::setMessage(const QString &message)
{
    QPixmap pixmap("Minopoly/Assets/menu_background.png");
    ui->endBackground->setPixmap(pixmap);
    ui->label->setText(message);
}
