#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "simlogic.h"
#include "playercreationmenu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    GameMaster* gamemaster;

    ~MainWindow();

private slots:
    void prepareCharacterMenu();
    void exitApp();

private:
    Ui::MainWindow *ui;
    PlayerCreationMenu *playerCreationMenu;

    bool isPlayerInit;
};

#endif // MAINWINDOW_H
