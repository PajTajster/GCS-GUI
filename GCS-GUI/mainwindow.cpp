#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    gm(new GameMaster),
	isPlayerInit(false),
	playerST(10),
	playerDX(10),
	playerHT(10),
	playerVet(0),
	isPlayerOutOfPoints(false)
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

void MainWindow::on_exitButton_clicked()
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
void MainWindow::on_characterNameTextEdit_textChanged()
{
	player->name = ui->characterNameTextEdit->toPlainText().toLocal8Bit().constData();
}
void MainWindow::on_STSpinBox_valueChanged(int i)
{
	if (isPlayerOutOfPoints)
		return;
	bool playerStillHasPoints = false;
	if (playerST > i)
	{
		playerStillHasPoints = player->ModifyAttribute(-1, 'S');
	}
	else if (playerST < i)
	{
		playerStillHasPoints = player->ModifyAttribute(1, 'S');
	}
	if (!playerStillHasPoints)
		isPlayerOutOfPoints = true;
	else
		isPlayerOutOfPoints = false;
	playerST = i;
	ui->pointsLeftLabel->setText(QString::number(player->characterPoints));
}
void MainWindow::on_DXSpinBox_valueChanged(int i)
{
	if (isPlayerOutOfPoints)
		return;
	bool playerStillHasPoints = false;
	if (playerDX > i)
	{
		playerStillHasPoints = player->ModifyAttribute(-1, 'D');
	}
	else if (playerDX < i)
	{
		playerStillHasPoints = player->ModifyAttribute(1, 'D');
	}
	if (!playerStillHasPoints)
		isPlayerOutOfPoints = true;
	else
		isPlayerOutOfPoints = false;
	playerDX = i;
	ui->pointsLeftLabel->setText(QString::number(player->characterPoints));
}
void MainWindow::on_HTSpinBox_valueChanged(int i)
{
	if (isPlayerOutOfPoints)
		return;
	bool playerStillHasPoints = false;
	if (playerHT > i)
	{
		playerStillHasPoints = player->ModifyAttribute(-1, 'H');
	}
	else if (playerHT < i)
	{
		playerStillHasPoints = player->ModifyAttribute(1, 'H');
	}
	if (!playerStillHasPoints)
		isPlayerOutOfPoints = true;
	else
		isPlayerOutOfPoints = false;
	playerHT = i;
	ui->pointsLeftLabel->setText(QString::number(player->characterPoints));
}
void MainWindow::on_VetSpinBox_valueChanged(int i)
{
	if (isPlayerOutOfPoints)
		return;
	bool playerStillHasPoints = false;
	if (playerVet > i)
	{
		playerStillHasPoints = player->ModifyAttribute(-1, 'V');
	}
	else if (playerVet < i)
	{
		playerStillHasPoints = player->ModifyAttribute(1, 'V');
	}
	if (!playerStillHasPoints)
		isPlayerOutOfPoints = true;
	else
		isPlayerOutOfPoints = false;
	playerVet = i;
	ui->pointsLeftLabel->setText(QString::number(player->characterPoints));
}