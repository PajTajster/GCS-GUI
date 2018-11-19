#ifndef BATTLESIZEMENU_H
#define BATTLESIZEMENU_H

#include <QDialog>

namespace Ui {
class BattleSizeMenu;
}

class BattleSizeMenu : public QDialog
{
    Q_OBJECT

public:
    explicit BattleSizeMenu(QWidget *parent = nullptr);
    ~BattleSizeMenu();

private:
    Ui::BattleSizeMenu *ui;
};

#endif // BATTLESIZEMENU_H
