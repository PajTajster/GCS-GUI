#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    gm(new GameMaster)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    if(!gm->InitializeGameMaster())
    {

    }
    player = gm->InitBasePlayer();

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exitApp()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gm;
    delete player;
}

void MainWindow::exitApp()
{
    this->close();
}

void MainWindow::on_prepareCharacterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pCCancelButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
