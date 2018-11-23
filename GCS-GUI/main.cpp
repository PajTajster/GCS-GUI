#include "mainwindow.h"
#include "simlogic.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameMaster* gm = new GameMaster();
    gm->InitializeGameMaster();

    MainWindow w;
    w.gamemaster = gm;
    w.show();

    return a.exec();
}
