// MineSweeper Class inplementation goes here

#include <iostream>
#include <fstream>
#include "MineSweeper.h"
#include "Grid.h"

//Constructor
MineSweeper::MineSweeper()
{
	columns = 0;
	rows = 0;
	mineCount = 0;
}

//Deconstructor
MineSweeper::~MineSweeper()
{
	delete mineGrid;
	mineGrid = nullptr;
	delete playerGrid;
	mineGrid = nullptr;
}

void MineSweeper::mainMenu()
{
	char userMenuSelection;
	bool gameExit = false;

	while (gameExit != true)
	{
		std::cout << std::endl;
		std::cout << " ---MINESWEEPER MAIN MENU---" << std::endl;
		std::cout << std::endl;
		std::cout << " What would you like to do?" << std::endl;
		std::cout << std::endl;
		std::cout << " 1) Default game" << std::endl;
		std::cout << std::endl;
		std::cout << "    (Default game settings 10 x 10 grid with 10 mines)" << std::endl;
		std::cout << std::endl;
		std::cout << " 2) Custom Game " << std::endl;
		std::cout << std::endl;
		std::cout << "    (if no changes have been made, will use a 5 x 5 grid with 4 mines)" << std::endl;
		std::cout << std::endl;
		std::cout << " 3) Settings" << std::endl;
		std::cout << std::endl;
		std::cout << " 4) Quit Game" << std::endl;
		std::cout << std::endl;
		std::cout << " *) ";

		std::cin >> userMenuSelection;

		switch (userMenuSelection)
		{
		case '1':
		{
			defaultGame();
			break;
		}

		case '2':
		{
			customGame();
			break;
		}

		case '3':
		{
			settingsMenu();
			break;
		}

		case '4':
		{
			//Quit the Game
			gameExit = true;
			break;
		}

		default:
		{
			std::cout << std::endl;
			std::cout << " Invalid input, please choose an option from the menu" << std::endl;
		}
		} // End of Switch
	} // End of While loop
}

void MineSweeper::settingsMenu()
{
	// Local Variables
	char settingsMenuChoice;
	bool exitSettingsMenu = false;
	bool changeMineCount = false;

	while (exitSettingsMenu != true)
	{
		std::cout << std::endl;
		std::cout << " ---SETTINGS MENU---" << std::endl;
		std::cout << std::endl;
		std::cout << " Current Grid Size (X Y): " << columns << " By " << rows << std::endl;
		std::cout << std::endl;
		std::cout << " Total number of Tiles: " << (columns * rows) << std::endl;
		std::cout << std::endl;
		std::cout << " Minecount: " << mineCount << std::endl;
		std::cout << std::endl;
		std::cout << " Please choose from one of the options listed below" << std::endl;
		std::cout << std::endl;
		std::cout << " 1) Change default Grid Size" << std::endl;
		std::cout << std::endl;
		std::cout << " 2) Change Mine Count" << std::endl;
		std::cout << std::endl;
		std::cout << " 3) Return to Main Menu" << std::endl;
		std::cout << std::endl;
		std::cout << " *) ";
		std::cin >> settingsMenuChoice;

		switch (settingsMenuChoice)
		{

		case '1':
		{
			userGridSize();
			std::cout << std::endl;
			std::cout << " Grid Size CHANGE confirmed" << std::endl;
			changeMineCount = true;
			break;
		}
		case '2':
		{
			if (changeMineCount != false)
			{
				userMineCount();
				std::cout << std::endl;
				std::cout << " Mine count CHANGE confirmed" << std::endl;
				break;
			}
			if ((changeMineCount != true))
			{
				std::cout << std::endl;
				std::cout << " You cannot change the mine count until you have set a grid size! #Schoolboy" << std::endl;
				std::cout << std::endl;
				std::cout << " Please choose option one from the menu first" << std::endl;
				break;
			}
		}
		case '3':
		{
			if (mineCount == 0 && columns == 0 && rows == 0)
			{
				exitSettingsMenu = true;
				break;
			}
			if (columns > 1 && rows > 1)
			{
				if (mineCount == 0)
				{
					std::cout << std::endl;
					std::cout << " MINECOUNT HAS NOT BEEN SET, PLEASE INPUT AN APROPRIATE VALUE" << std::endl;
					break;
				}
			}

			if (mineCount >= (columns*rows))
			{
				std::cout << std::endl;
				std::cout << " MINECOUNT MUST BE LESS THAN GRID SIZE, PLEASE INPUT AN APPROPRIATE VALUE" << std::endl;
				break;
			}
			exitSettingsMenu = true;
			break;
		}
		default:
		{
			std::cout << std::endl;
			std::cout << " Invalid input, please enter A choice from the menu" << std::endl;
		}
		} // End of Switch
	} // End of While Loop
}

void MineSweeper::userGridSize()
{
	// Local Variables
	bool menuRepeat = false;
	bool check = false;
	char userMenuSelection;
	char inputAttempsUserInput;
	int inputAttempts = 0;

	while (menuRepeat != true)
	{
		std::cout << std::endl;
		std::cout << " Please choose the game size from one of the options listed below" << std::endl;
		std::cout << std::endl;
		std::cout << " 1)  Small game    4 x 4   ( 16 Tiles)" << std::endl;
		std::cout << std::endl;
		std::cout << " 2)  Medium game   6 x 6   ( 36 Tiles)" << std::endl;
		std::cout << std::endl;
		std::cout << " 3)  Large game   10 x 10  (100 Tiles)" << std::endl;
		std::cout << std::endl;
		std::cout << " 4)  Huge game    20 x 20  (200 Tiles)" << std::endl;
		std::cout << std::endl;
		std::cout << " 5)  Choose your own game size" << std::endl;
		std::cout << std::endl;
		std::cout << " *)  ";

		std::cin >> userMenuSelection;

		switch (userMenuSelection)
		{
		case '1':
		{
			rows = 4;
			columns = 4;
			menuRepeat = true;
			break;
		}

		case '2':
		{
			rows = 6;
			columns = 6;
			menuRepeat = true;
			break;
		}

		case '3':
		{
			rows = 10;
			columns = 10;
			menuRepeat = true;
			break;
		}

		case '4':
		{
			rows = 20;
			columns = 20;
			menuRepeat = true;
			break;
		}

		case '5':
		{
			while (check != true)
			{
				std::cout << std::endl;
				std::cout << " How many columns and rows would you like (X Y): ";
				std::cin >> columns >> rows;

				//checks to see if the grid size is valid first
				if (((columns < 20) && (columns > 1)) && ((rows < 20) && (rows > 1)))
				{
					std::cout << std::endl;
					std::cout << " Grid Size confirmed" << std::endl;
					//if the user input size is valid both while loops are set to true
					menuRepeat = true;
					check = true;
				}

				else
				{
					std::cout << std::endl;
					std::cout << " Invalid input, game Size must be Min. 2 x 2 Max. 20 x 20" << std::endl;

					inputAttempts++;

					if (inputAttempts == 3)
					{
						std::cout << std::endl;
						std::cout << " You have entered multiple invalid inputs, if you would" << std::endl <<
							" like to choose a pre determined game size hit the y key else, " << std::endl <<
							" any other key to try again" << std::endl;

						std::cout << std::endl;
						std::cout << " *) ";

						std::cin >> inputAttempsUserInput;

						if ((inputAttempsUserInput == 'y') || (inputAttempsUserInput == 'Y'))
						{
							//break
							break;
						}

						else
						{
							inputAttempts = 0;
						}
					}
				}
			}
			break;
		}
		default:
			std::cout << std::endl;
			std::cout << " Invalid user input selected" << std::endl;
			std::cout << std::endl;
			std::cout << " Please select a valid option" << std::endl;

		}// end of switch userMenuSelection
	}// end of while loop menuRepeat

	menuRepeat = false;
}

void MineSweeper::userMineCount()
{
	bool menuRepeat = false;
	bool check = false;
	char userMenuSelection;
	char inputAttempsUserInput;
	char confirmMineCount;
	int inputAttempts = 0;

	while (menuRepeat != true)
	{
		std::cout << std::endl;
		std::cout << " Please choose how densely you want the grid mined" << std::endl;
		std::cout << std::endl;
		std::cout << " 1)  (Beginner)     10% of the grid will be mined" << std::endl;
		std::cout << std::endl;
		std::cout << " 2)  (Novice)       20% of the grid will be mined" << std::endl;
		std::cout << std::endl;
		std::cout << " 3)  (Intermediate) 30% of the grid will be mined" << std::endl;
		std::cout << std::endl;
		std::cout << " 4)  (Advanced)     40% of the grid will be mined" << std::endl;
		std::cout << std::endl;
		std::cout << " 5)  Input your own number of Mines" << std::endl;
		std::cout << std::endl;
		std::cout << " *)  ";

		std::cin >> userMenuSelection;

		switch (userMenuSelection)
		{
		case '1':
		{
			mineCount = ((rows * columns) / 10);

			if (mineCount < 2)
			{
				mineCount = 2;
			}

			menuRepeat = true;
			break;
		}

		case '2':
		{
			mineCount = ((rows * columns) / 5);
			menuRepeat = true;
			break;
		}

		case '3':
		{
			mineCount = (((rows * columns) / 10) * 3);
			menuRepeat = true;
			break;
		}

		case '4':
		{
			mineCount = (((rows * columns) / 10) * 4);
			menuRepeat = true;
			break;
		}

		case '5':
		{
			while (check != true)
			{
				std::cout << std::endl;
				std::cout << " *)  How many Mines would you like?" << std::endl;
				std::cout << std::endl;
				std::cout << " *)  ";

				std::cin >> mineCount;

				//checks to see if the number of mines is valid
				if ((mineCount > 1) && (mineCount < (rows * columns)))
				{
					if (mineCount < ((rows * columns) / 10))
					{
						std::cout << std::endl;
						std::cout << " You have chosen less than 10% (" << ((rows * columns) / 10) << ") of the grid to be mined," <<
							" press 'y' if you" << std::endl <<
							" are happy with the amount or any other key to choose again" << std::endl;

						std::cout << std::endl;
						std::cout << " *) ";
						std::cin >> confirmMineCount;
						if ((confirmMineCount == 'y') || (confirmMineCount == 'Y'))
						{
							//if the user input size is valid both while loops are set to true
							menuRepeat = true;
							check = true;
						}
						else
						{
							std::cout << std::endl;
							break;
						}
					}
					//if the user input size is valid both while loops are set to true
					menuRepeat = true;
					check = true;
				}

				else if (inputAttempts == 2)
				{
					std::cout << std::endl;
					std::cout << " You have entered multiple invalid inputs, if you would" << std::endl <<
						" like to choose a pre determined percentage of mines hit the y key else, " << std::endl <<
						" any other key to try again" << std::endl;

					inputAttempts = 0;

					std::cout << std::endl;
					std::cout << " *) ";

					std::cin >> inputAttempsUserInput;

					if ((inputAttempsUserInput == 'y') || (inputAttempsUserInput == 'Y'))
					{
						// break
						break;
					}
				}

				else if ((mineCount > (rows * columns)))
				{
					std::cout << std::endl;
					std::cout << " invalid input, total mines cannot exceed total grid tiles" << std::endl;
					std::cout << std::endl;
					std::cout << " It is not recommended to have more than 40% (" << (((rows * columns) / 10) * 4) << ") tiles mined" << std::endl;
					std::cout << std::endl;
					std::cout << " Please enter a valid input" << std::endl;

					inputAttempts++;
				}

				else if (mineCount < 2)
				{
					std::cout << std::endl;
					std::cout << " Invalid Input, minimum number of mines required to play is 2" << std::endl;

					inputAttempts++;
				}

				else if (mineCount == (columns * rows))
				{
					std::cout << std::endl;
					std::cout << " You cant play a game FULL of mines! #Schoolboy" << std::endl;

					inputAttempts++;
				}

				else
				{
					std::cout << std::endl;
					std::cout << " Invalid input" << std::endl;
					std::cout << std::endl;
					std::cout << " Please enter a valid input" << std::endl;

					inputAttempts++;
				}
			}
			break;
		}

		default:
			std::cout << std::endl;
			std::cout << " Invalid user input selected" << std::endl;
			std::cout << std::endl;
			std::cout << " Please select a valid option" << std::endl;

		}//end of switch userMenuSelection

	}//end of while loop MenuRepeat

	menuRepeat = false;
	inputAttempts = 0;
}

void MineSweeper::gamePlayMenu()
{
	// Game chat array, prints a random line each turn, helps keep the game more interesting
	char gameChat[7][44] = { " Do you even know how to play this game?", " Think you can beat me?",
		" One more tile and BOOM!",
		" I got nothing to say to you fancy pants...", " My my how the tables have turned...",
		" Now was that the red or the blue wire?", " I wouldn't do that if I were you..." };

	// More chat for when the player looses
	char endgameChat[7][52] = { " Do you even know how to play this game?", " A monkey would have known that was a mine!",
		" So close... ah who am I kidding you suck!",
		" I got nothing to say to you fancy pants...", " one day my friend...", " Did you cut the correct wire?",
		" I though you said you were a bomb disposal expert?" };

	flagCount = mineCount;
	gameVictory = mineCount;
	userChoice = false;
	validCheck = false;
	mineCheck = false;

	int flagCountStart = flagCount;
	char userGameInput;

	while (userChoice != true)
	{
		std::cout << std::endl;
		std::cout << " You have " << flagCount << " Flags remaining, " << std::endl;
		std::cout << std::endl;

		// Random Game chat prints out
		int randChoice = rand() % 7;
		std::cout << gameChat[randChoice] << std::endl;

		std::cout << std::endl;
		std::cout << " 1) Clear a Tile " << std::endl;
		std::cout << std::endl;
		std::cout << " 2) Place a Flag " << std::endl;
		std::cout << std::endl;
		std::cout << " 3) Remove a Flag " << std::endl;
		std::cout << std::endl;
		std::cout << " 4) Quit the current game " << std::endl;
		std::cout << std::endl;
		std::cout << " *) ";

		std::cin >> userGameInput;

		switch (userGameInput)
		{

			// If the user chooses to clear a tile
		case '1':
		{
			while (1)
			{
				//choose a position to check
				userGameInputGuess();
				//check the position is valid (in bounds)
				userGameInputGuessValidCheck();

				if (validCheck == false)
				{
					playerGrid->printGrid();
				}

				if (validCheck == true)
				{
					break;
				}
			}

			if ((userInputX >= 0) && (userInputY >= 0) && ((userInputX + 1) <= columns) && ((userInputY + 1) <= rows))
			{
				userPreviousGuessCheck();
			}

			userGuessMineCheck();

			if (mineCheck == true)
			{
				std::cout << std::endl;
				std::cout << "  ---BOOM!---" << std::endl;
				std::cout << std::endl;

				endGameGridGenerate();
				playerGrid->printGrid();

				std::cout << std::endl;
				std::cout << "  -GAME OVER-" << std::endl;
				std::cout << std::endl;

				int randChoice = rand() % 7;
				std::cout << endgameChat[randChoice] << std::endl;

				// Reset game settings
				columns = 0;
				rows = 0;
				mineCount = 0;

				//user choice is the name of the while loop, if the player hits a mine this exits the loop
				userChoice = true;
				break;
			}

			else
			{
				fillGridWithGuess(userInputX, userInputY);
				std::cout << std::endl;
				playerGrid->printGrid();
			}

			break;
		}

		// if the player chooses to place a flag
		case '2':
		{
			userGameInputGuess();
			userGameInputGuessValidCheck();
			//choose a position to flag

			if ((userInputX >= 0) && (userInputY >= 0) && ((userInputX + 1) <= columns) && ((userInputY + 1) <= rows))
			{
				placeFlag();
			}

			if (gameVictory == 0)
			{
				std::cout << " Well Done you have cleared the Minefield!" << std::endl;
				std::cout << std::endl;

				playerGrid->printGrid();
				userChoice = true;

				// Reset game settings
				columns = 0;
				rows = 0;
				mineCount = 0;
			}

			else
			{
				playerGrid->printGrid();
			}

			break;
		}

		// If the user decided to remove a previously placed flag
		case '3':
		{
			if (flagCount == flagCountStart)
			{
				std::cout << std::endl;
				std::cout << " You cant remove a flag if you havn't placed one yet! #Schoolboy" << std::endl;
				std::cout << std::endl;
				playerGrid->printGrid();
				break;
			}

			userGameInputGuess();
			userGameInputGuessValidCheck();

			if ((userInputX >= 0) && (userInputY >= 0) && ((userInputX + 1) <= columns) && ((userInputY + 1) <= rows))
			{
				removeFlag();
			}

			playerGrid->printGrid();
			break;
		}

		case '4':
		{
			// quit the current game

			// Reset game settings
			columns = 0;
			rows = 0;
			mineCount = 0;

			userChoice = true;
			break;
		}

		// if none of the options above are selected
		default:
		{
			std::cout << std::endl;
			std::cout << " Invalid input, please choose an option from the menu" << std::endl;
		}
		} // Switch userGameInput
	} // While userChoice
}

void MineSweeper::defaultGame()
{
	columns = 10;
	rows = 10;
	mineCount = 10;

	playerGrid = new Grid(columns, rows);
	mineGrid = new Grid(columns, rows);
	mineGrid->fillGridWithMines(mineCount);
	//For Testing ONLY
	//mineGrid->printGrid();
	playerGrid->printGrid();
	gamePlayMenu();
}

void MineSweeper::customGame()
{
	if (columns < 2 || rows < 2)
	{
		columns = 5;
		rows = 5;
		mineCount = 4;
	}

	if (mineCount < 2)
	{
		mineCount = 4;
	}

	playerGrid = new Grid(columns, rows);
	mineGrid = new Grid(columns, rows);
	mineGrid->fillGridWithMines(mineCount);
	playerGrid->printGrid();
	gamePlayMenu();
}

void MineSweeper::userGameInputGuess()
{
	//ask and receive a guess from the player
	std::cout << std::endl;
	std::cout << " Please Choose a Position (X Y): ";

	std::cin >> userInputX >> userInputY;

	// Inputs are lowered by one as the Array (Grid) starts at 0 not 1
	userInputX -= 1;
	userInputY -= 1;
}

void MineSweeper::userGameInputGuessValidCheck()
{
	// First if statement to check if the user input is within the bounds of the game size
	if ((userInputX < 0) || (userInputY < 0) || ((userInputX + 1) > columns) || ((userInputY + 1) > rows))
	{
		std::cout << std::endl;
		std::cout << " Invalid Coordinates, outside the bounds of the game! #Schoolboy" << std::endl;

		std::cout << std::endl;
		std::cout << " X (Across) cannot be more than " << columns << ", Or less than 1. You entered "
			<< userInputX + 1 << std::endl;

		std::cout << std::endl;
		std::cout << " Y (Down) cannot exceed more than " << rows << ", Or less than 1. You entered "
			<< userInputY + 1 << std::endl;

		std::cout << std::endl;
		std::cout << " Try again Schoolboy" << std::endl;
		std::cout << std::endl;
	}

	// two if statement although, maybe an else would have been an option
	if ((userInputX >= 0) && (userInputY >= 0) && ((userInputX + 1) <= columns) && ((userInputY + 1) <= rows))
	{
		validCheck = true;
	}
}

void MineSweeper::endGameGridGenerate()
{
	for (int y = 0; y < columns; y++)
	{
		for (int x = 0; x < rows; x++)
		{
			if (mineGrid->getChar(x, y) == 'm')
			{
				playerGrid->setChar(x, y, 'm');
			}
			if (mineGrid->getChar(x, y) != 'm')
			{
				//do nothing
			}
		}
	}
}

void MineSweeper::fillGridWithGuess(int userInputX, int userInputY)
{
	//First check to see if position is Valid and in bounds
	if (((userInputX) >= 0) && ((userInputX) < columns) && ((userInputY) >= 0) && ((userInputY) < rows))
	{
		if (playerGrid->getChar(userInputX, userInputY) == 'F')
		{
			std::cout << std::endl;
			std::cout << " Position contained a FLAG, flag removed..." << std::endl;
			flagCount++;
		}

		//Next check is to see if tile is a mine
		if (mineGrid->getChar(userInputX, userInputY) != 'm')
		{
			//update initial position, position has already been checked for mines
			playerGrid->setChar(userInputX, userInputY, mineGrid->getChar(userInputX, userInputY));
		}
	}
}

void MineSweeper::placeFlag()
{
	if (playerGrid->getChar(userInputX, userInputY) == 'F')
	{
		std::cout << std::endl;
		std::cout << " You already have a flag at this position! #Schoolboy" << std::endl;
		std::cout << std::endl;
	}

	else if (playerGrid->getChar(userInputX, userInputY) != '*')
	{
		std::cout << std::endl;
		std::cout << " You have already cleared this position! #Schoolboy" << std::endl;
		std::cout << std::endl;
	}

	else
	{
		//update initial position, position has already been checked for mines
		playerGrid->setChar(userInputX, userInputY, 'F');
		flagCount--;

		if (mineGrid->getChar(userInputX, userInputY) == 'm')
		{
			gameVictory--;
		}

		std::cout << std::endl;
		std::cout << " Flag has been placed at " << userInputX + 1 << " " << userInputY + 1 << " ..." << std::endl;
		std::cout << std::endl;
	}
}


void MineSweeper::removeFlag()
{
	// Check there is a Flag at the position first
	if (playerGrid->getChar(userInputX, userInputY) == 'F')
	{
		//update initial position, position has already been checked for mines
		playerGrid->setChar(userInputX, userInputY, '*');
		flagCount++;

		if (mineGrid->getChar(userInputX, userInputY) == 'm')
		{
			gameVictory++;
		}
		std::cout << std::endl;
		std::cout << " Flag has been removed..." << std::endl;
	}

	// If the chosen position does not contain a flag print an error message
	else
	{
		std::cout << std::endl;
		std::cout << " There is no Flag at this location! #Schoolboy" << std::endl;
	}

	std::cout << std::endl;
}


void MineSweeper::userPreviousGuessCheck()
{
	if (playerGrid->getChar(userInputX, userInputY) != '*')
	{
		if (playerGrid->getChar(userInputX, userInputY) == 'F')
		{
			return;
		}

		std::cout << std::endl;
		std::cout << " You have already cleared this tile of mines! (Grid " << userInputX + 1 << " " <<
			userInputY + 1 << ")" << " #SchoolBoy!" << std::endl;
	}

	else
	{
		// Do Nothing
	}
}

void MineSweeper::userGuessMineCheck()
{
	if (mineGrid->getChar(userInputX, userInputY) == 'm')
	{
		mineCheck = true;
	}

	else
	{
		//do nothing
	}
}