#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    gm(new GameMaster),
	isPlayerInit(false)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    if(!gm->InitializeGameMaster())
    {
		this->close();
    }

	if (!isPlayerInit)
	{
		ui->prepareBattleButton->setEnabled(false);
		ui->prepareBattleButton->setText("Your character isn't ready!");
		ui->prepareBattleButton->adjustSize();
	}
	else
	{
		ui->prepareBattleButton->setEnabled(true);
		ui->prepareBattleButton->setText("Prepare the battle");
		ui->prepareBattleButton->adjustSize();
	}
    player = gm->InitBasePlayer();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete gm;
    delete player;
}

void MainWindow::on_prepareCharacterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pCCancelButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_exitButton_clicked()
{
	this->close();

}