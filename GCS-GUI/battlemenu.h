#ifndef BATTLEMENU_H
#define BATTLEMENU_H

#include <QDialog>

namespace Ui {
class BattleMenu;
}

class BattleMenu : public QDialog
{
    Q_OBJECT

public:
    explicit BattleMenu(QWidget *parent = nullptr);
    ~BattleMenu();

private:
    Ui::BattleMenu *ui;
};

#endif // BATTLEMENU_H
