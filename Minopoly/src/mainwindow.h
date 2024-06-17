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
    void rollDice();
    void paintDice(int die1, int die2);
    void paintPlayer(int player_number, int position);
    void paintCard(int position);
    void paintActivePlayer(int player_number);
    void paintInactivePlayer(int player_number);
    void nextMove();
    void paintProperty(int position);
    void paintStation(int position);
    void paintChance();
    void paintTreasure();
    void paintCardByPosition(int position);

private:
    Ui::MainWindow *ui;
    MenuDialog menu;
    QLabel* lbArr[6]; // Adjust the size according to the maximum number of players

    std::pair<int, int> getPlayerPosition(int position);
};

#endif // MAINWINDOW_H
