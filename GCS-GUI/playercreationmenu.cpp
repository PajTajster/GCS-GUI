#include "playercreationmenu.h"
#include "ui_playercreationmenu.h"

PlayerCreationMenu::PlayerCreationMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerCreationMenu)
{
    ui->setupUi(this);
}

PlayerCreationMenu::~PlayerCreationMenu()
{
    delete ui;
}
