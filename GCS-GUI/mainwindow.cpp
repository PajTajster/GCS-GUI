#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    isPlayerInit(false)
{
    ui->setupUi(this);
    playerCreationMenu = new PlayerCreationMenu;

    if(isPlayerInit)
        ui->prepareBattleButton->setEnabled(true);
    else
    {
        ui->prepareBattleButton->setEnabled(false);
        ui->prepareBattleButton->setText("Prepare your character first!");
        ui->prepareBattleButton->adjustSize();
    }

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exitApp()));
    connect(ui->prepareCharacterButton, SIGNAL(clicked()),
            this, SLOT(prepareCharacterMenu()));
}

MainWindow::~MainWindow()
{
    delete playerCreationMenu;
    delete ui;
}

void MainWindow::prepareCharacterMenu()
{
    playerCreationMenu->show();
    this->hide();
}

void MainWindow::exitApp()
{
    this->close();
}
