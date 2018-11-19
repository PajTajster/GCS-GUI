#include "choosefightermenu.h"
#include "ui_choosefightermenu.h"

ChooseFighterMenu::ChooseFighterMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseFighterMenu)
{
    ui->setupUi(this);
}

ChooseFighterMenu::~ChooseFighterMenu()
{
    delete ui;
}
