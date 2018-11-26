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
	void on_prepareCharacterButton_clicked();
	void on_prepareBattleButton_clicked();

	// PLAYER CREATION MENU
	void on_pCCharacterDoneButton_clicked();
    void on_pCCancelButton_clicked();
	void on_characterNameTextEdit_textChanged();
	void on_STSpinBox_valueChanged(int i);
	void on_DXSpinBox_valueChanged(int i);
	void on_HTSpinBox_valueChanged(int i);
	void on_VetSpinBox_valueChanged(int i);
	void on_weaponComboBox_currentIndexChanged(const QString &text);
	void on_armourComboBox_currentIndexChanged(const QString &text);
	void on_shieldComboBox_currentIndexChanged(const QString &text);

	// BATTLE SIZE MENU
	void on_bSgoBackButton_clicked();
	void on_bSteamButton_clicked();
	void on_bSteamButton_2_clicked();

	// PREPARE TEAM MENU
	void on_goBackButton_2_clicked();
	void on_doneButton_2_clicked();
	void on_resetButton_clicked();
	void on_selectButton_clicked();
	void on_team1RadioButton_toggled(bool checked);
	void on_comboBox_currentIndexChanged(int index);

	// BATTLE SCREEN
	void on_nextTurnButton_clicked();
	void on_skipTurnButton_clicked();
	void on_surrenderButton_clicked();
	void on_attackTargetButton_clicked();
	void on_comboBox_2_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    GameMaster *gm;
    Character *player;


	// Player related stuff
	bool isPlayerInit;
	int playerST;
	int playerDX;
	int playerHT;
	int playerVet;
	bool isPlayerOutOfPoints;
	bool isPlayerAlive;

	bool allEnemiesDead;

	int teamSize;

	// Fighter Choosing menu vars

	int team1Size;
	int team2Size;
	int currentTeam; // 1 or 2

	// Battle Menu vars
	bool isGameFinished;
	int currentTurn;
	int currentCharacterTurn;
	int baddiesID[2];
	bool baddiesDead[2];

	std::vector<Character> team1Chars;
	std::vector<Character> team2Chars;
	Character currentCharacterSelected;
	int currentTargetID;

	std::vector<Character> allCharacters;

	void checkForDead();
	void updatedInfoLabel();
	void playTurn(int characterIndex);

	// Called on battle end
	void ReInit();
};

#endif // MAINWINDOW_H
