#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "simlogic.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void exitApp();

    void on_prepareCharacterButton_clicked();

    void on_pCCancelButton_clicked();

private:
    Ui::MainWindow *ui;
    GameMaster *gm;
    Character *player;
};

#endif // MAINWINDOW_H
