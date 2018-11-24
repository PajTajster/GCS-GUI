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
	player = gm->InitBasePlayer();

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

	std::vector<Weapon> weapons = gm->GetWeapons();
	std::vector<Armour> armours = gm->GetArmours();
	std::vector<Shield> shields = gm->GetShields();
	for (auto& it : weapons)
	{
		ui->weaponComboBox->addItem(it.name.c_str());
	}
	for (auto &it : armours)
	{
		ui->armourComboBox->addItem(it.name.c_str());
	}
	for (auto &it : shields)
	{
		ui->shieldComboBox->addItem(it.name.c_str());
	}
	

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


void MainWindow::on_pCDoneButton_clicked()
{
	isPlayerInit = true;
	ui->prepareBattleButton->setEnabled(true);
	ui->prepareBattleButton->setText("Prepare the battle");
	ui->prepareBattleButton->adjustSize();

	player->CalculateExtraAttributes();
	player->CalculateSkillsDefaults();

	ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pCCancelButton_clicked()
{
	playerST = 10;
	ui->STSpinBox->setValue(10);
	playerHT = 10;
	ui->HTSpinBox->setValue(10);
	playerDX = 10;
	ui->DXSpinBox->setValue(10);
	playerVet = 0;
	ui->VetSpinBox->setValue(0);

	delete player;
	player = gm->InitBasePlayer();
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

void MainWindow::on_weaponComboBox_currentIndexChanged(const QString &text)
{
	std::string nameToSearch = text.toLocal8Bit().constData();
	std::vector<Weapon> items = gm->GetWeapons();
	auto searchedItem = std::find_if(items.cbegin(), items.cend(),
		[nameToSearch](const Weapon& s) -> bool {return s.name == nameToSearch; });

	player->currentWeapon = *searchedItem;

	if (searchedItem->isTwoHanded)
	{
		ui->shieldComboBox->setEnabled(false);
		ui->shieldLabel->setText("Both hands busy!");
		ui->shieldLabel->adjustSize();
		ui->shieldLabel->setAlignment(Qt::AlignHCenter);
		ui->shieldLabel->setStyleSheet("background-color:red;");
	}
	else
	{
		ui->shieldComboBox->setEnabled(true);
		ui->shieldLabel->setText("Shield");
		ui->shieldLabel->adjustSize();
		ui->shieldLabel->setAlignment(Qt::AlignHCenter);
		ui->shieldLabel->setStyleSheet("background-color:white;");
	}
}
void MainWindow::on_armourComboBox_currentIndexChanged(const QString &text)
{
	std::string nameToSearch = text.toLocal8Bit().constData();
	std::vector<Armour> items = gm->GetArmours();
	auto searchedItem = std::find_if(items.cbegin(), items.cend(),
		[nameToSearch](const Armour& s) -> bool {return s.name == nameToSearch; });

	player->currentArmour = *searchedItem;
}
void MainWindow::on_shieldComboBox_currentIndexChanged(const QString &text)
{
	std::string nameToSearch = text.toLocal8Bit().constData();
	std::vector<Shield> items = gm->GetShields();
	auto searchedItem = std::find_if(items.cbegin(), items.cend(),
		[nameToSearch](const Shield& s) -> bool {return s.name == nameToSearch; });

	player->currentShield = *searchedItem;
}

