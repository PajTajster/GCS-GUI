#ifndef PLAYERCREATIONMENU_H
#define PLAYERCREATIONMENU_H

#include <QDialog>

namespace Ui {
class PlayerCreationMenu;
}

class PlayerCreationMenu : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerCreationMenu(QWidget *parent = nullptr);
    ~PlayerCreationMenu();

private:
    Ui::PlayerCreationMenu *ui;
};

#endif // PLAYERCREATIONMENU_H
