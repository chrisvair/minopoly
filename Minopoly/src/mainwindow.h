#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QRandomGenerator>
#include "menudialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void initializePlay();
    void rollDie(int die1, int die2);

private:
    Ui::MainWindow *ui;
    MenuDialog menu;
    QLabel* lbArr[6]; // Adjust the size according to the maximum number of players

    std::pair<int, int> getPlayerPosition(int position);
};

#endif // MAINWINDOW_H
