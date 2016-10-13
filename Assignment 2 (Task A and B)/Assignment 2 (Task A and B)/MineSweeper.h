// Minesweeper header File

#pragma once
#include "Grid.h"

class MineSweeper
{
public:

	//Constructor
	MineSweeper();

	//Deconstructor
	~MineSweeper();

	//Public functions go here
	void mainMenu();

private:

	// Variables
	int columns;
	int rows;
	int mineCount;
	int flagCount;
	int gameVictory;
	bool userChoice;
	bool validCheck;
	bool mineCheck;
	// Variables used to store player guess
	int userInputX;
	int userInputY;

	Grid* mineGrid;
	Grid* playerGrid;

	// Functions
	void settingsMenu();
	void gamePlayMenu();
	void userGridSize();
	void userMineCount();
	void defaultGame();
	void customGame();
	void userGameInputGuess();
	void userGameInputGuessValidCheck();
	void endGameGridGenerate();
	void fillGridWithGuess(int userInputX, int userInputY);
	void placeFlag();
	void removeFlag();
	void userPreviousGuessCheck();
	void userGuessMineCheck();
};
