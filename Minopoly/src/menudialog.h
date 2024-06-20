#ifndef MENUDIALOG_H
#define MENUDIALOG_H

#include <QDialog>
#include "ui_menudialog.h"

/**
     * This class is the dialog that appears when the game is launched.
     * It allows the user to choose the number of players and their names.
     * It also allows the user to load a game or to create a new one.
     * The user can also quit the game.
 **/

namespace Ui {
class MenuDialog;
}

class MenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MenuDialog(QWidget *parent = nullptr);
    Ui::MenuDialog *ui;
    ~MenuDialog();

};

#endif // MENUDIALOG_H