#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);


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

void MainWindow::on_prepareCharacterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pCCancelButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
