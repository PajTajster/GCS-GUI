#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exitApp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exitApp()
{
    this->close();
}
