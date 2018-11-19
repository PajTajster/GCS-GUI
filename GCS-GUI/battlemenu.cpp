#include "battlemenu.h"
#include "ui_battlemenu.h"

BattleMenu::BattleMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BattleMenu)
{
    ui->setupUi(this);
}

BattleMenu::~BattleMenu()
{
    delete ui;
}
