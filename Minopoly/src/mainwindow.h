#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menudialog.h"
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void InitialisePlay();

private:
    Ui::MainWindow *ui;
    MenuDialog menu;
    QLabel* lbArr[4];  // hold QLabel pointers for player icons
    std::pair<int, int> getPlayerPosition(int position);
};
#endif // MAINWINDOW_H
