#ifndef MENUDIALOG_H
#define MENUDIALOG_H

#include <QDialog>
#include "ui_menudialog.h"

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