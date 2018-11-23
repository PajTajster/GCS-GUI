#ifndef PLAYERCREATIONMENU_H
#define PLAYERCREATIONMENU_H

#include <QDialog>
#include <vector>
#include "simlogic.h"

namespace Ui {
class PlayerCreationMenu;
}

class PlayerCreationMenu : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerCreationMenu(QWidget *parent = nullptr);
    ~PlayerCreationMenu();

public slots:
    void acquireGMData(std::vector<Weapon>);

private:
    Ui::PlayerCreationMenu *ui;
};

#endif // PLAYERCREATIONMENU_H
