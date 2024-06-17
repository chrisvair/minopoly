#include "menudialog.h"
#include "ui_menudialog.h"

MenuDialog::MenuDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenuDialog)
{
    ui->setupUi(this);

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
