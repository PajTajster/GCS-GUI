#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "simlogic.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
	// MAIN MENU
	void on_exitButton_clicked();

	// PLAYER CREATION MENU
    void on_prepareCharacterButton_clicked();
    void on_pCCancelButton_clicked();
	void on_characterNameTextEdit_textChanged();
	void on_STSpinBox_valueChanged(int i);
	void on_DXSpinBox_valueChanged(int i);
	void on_HTSpinBox_valueChanged(int i);
	void on_VetSpinBox_valueChanged(int i);
	void on_weaponComboBox_currentIndexChanged(const QString &text);
	void on_armourComboBox_currentIndexChanged(const QString &text);
	void on_shieldComboBox_currentIndexChanged(const QString &text);


private:
    Ui::MainWindow *ui;
    GameMaster *gm;
    Character *player;

	bool isPlayerInit;
	int playerST;
	int playerDX;
	int playerHT;
	int playerVet;
	bool isPlayerOutOfPoints;

	// Called on battle end.
	void ReInit();
};

#endif // MAINWINDOW_H
