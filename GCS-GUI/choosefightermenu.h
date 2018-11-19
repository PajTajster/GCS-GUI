#ifndef CHOOSEFIGHTERMENU_H
#define CHOOSEFIGHTERMENU_H

#include <QDialog>

namespace Ui {
class ChooseFighterMenu;
}

class ChooseFighterMenu : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseFighterMenu(QWidget *parent = nullptr);
    ~ChooseFighterMenu();

private:
    Ui::ChooseFighterMenu *ui;
};

#endif // CHOOSEFIGHTERMENU_H
