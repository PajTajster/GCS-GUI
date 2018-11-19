#include "battlesizemenu.h"
#include "ui_battlesizemenu.h"

BattleSizeMenu::BattleSizeMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BattleSizeMenu)
{
    ui->setupUi(this);
}

BattleSizeMenu::~BattleSizeMenu()
{
    delete ui;
}
