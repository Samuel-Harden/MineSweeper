// Class Grid definitions all go into the .cpp file

#include <iostream>
#include <fstream>
#include "Grid.h"


Grid::Grid()
{
	// no variables do nothing
}

//Constructor
Grid::Grid(int x, int y)
{
	columns = x;
	rows = y;

	//Create the array 
	charArray = new char[columns * rows];

	//Populates the game board with a '*', the double for loop simply cycles through every position in the array
	// and fills them
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			charArray[rows * j + i] = '*';
		}
	}
}

//Deconstructor
Grid::~Grid()
{
	delete[] charArray;
	charArray = nullptr;
}

void Grid::fillGridWithMines(int m)
{
	mineCount = m;

	bool loop = false;

	int perimiterMineCountInt = 0;

	char mineProximintyCount[9] = { '.', '1', '2', '3', '4', '5', '6', '7' , '8' };

	int posX = 0;
	int posY = 0;

	//outer loop runs until all pairs have been set
	for (int i = 0; i < mineCount; i++)
	{

		loop = false;

		//the while loop is so it can find a unused position in the array
		while (loop == false)
		{
			posX = rand() % columns;
			posY = rand() % rows;

			//this is the check to see if the position is free or not
			if (charArray[rows * posX + posY] == '*')
			{
				charArray[rows * posX + posY] = 'm';
				//this cout is used for testing, to see if the loop was filling the array correctly
				//std::cout << playerGrid[posX][posY];
				loop = true;
			}
			else
			{
				//do nothing
			}
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (charArray[rows * j + i] != 'm')
			{
				if ((i - 1) >= 0)
				{
					//Checks the Tile UP of user input
					if (charArray[rows * j + (i - 1)] == 'm')
					{
						perimiterMineCountInt++;
					}
				}

				if ((i + 1) < rows)
				{
					//Checks the Tile DOWN of user input
					if (charArray[rows * j + (i + 1)] == 'm')
					{
						perimiterMineCountInt++;
					}
				}

				if ((j + 1) < columns)
				{
					//Checks the Tile to the RIGHT of user input
					if (charArray[rows * (j + 1) + i] == 'm')
					{
						perimiterMineCountInt++;
					}
				}

				if ((j - 1) >= 0)
				{
					//Checks the Tile to the LEFT of user input
					if (charArray[rows * (j - 1) + i] == 'm')
					{
						perimiterMineCountInt++;
					}
				}

				if (((i + 1) < rows) && ((j + 1) < columns))
				{
					//Checks the Tile DOWN and RIGHT of user input
					if (charArray[rows * (j + 1) + (i + 1)] == 'm')
					{
						perimiterMineCountInt++;
					}
				}

				if (((i - 1) >= 0) && ((j - 1) >= 0))
				{
					//Checks the Tile UP and LEFT of user input
					if (charArray[rows * (j - 1) + (i - 1)] == 'm')
					{
						perimiterMineCountInt++;
					}
				}

				if (((i - 1) >= 0) && ((j + 1) < columns))
				{
					//Checks the Tile UP and RIGHT of user input
					if (charArray[rows * (j + 1) + (i - 1)] == 'm')
					{
						perimiterMineCountInt++;
					}
				}

				if (((i + 1) < rows) && ((j - 1) >= 0))
				{
					//Checks the Tile DOWN and LEFT of user input
					if (charArray[rows * (j - 1) + (i + 1)] == 'm')
					{
						perimiterMineCountInt++;
					}
				}

				if (perimiterMineCountInt == 0)
				{
					charArray[rows * j + i] = mineProximintyCount[0];
				}
				if (perimiterMineCountInt == 1)
				{
					charArray[rows * j + i] = mineProximintyCount[1];
				}
				if (perimiterMineCountInt == 2)
				{
					charArray[rows * j + i] = mineProximintyCount[2];
				}
				if (perimiterMineCountInt == 3)
				{
					charArray[rows * j + i] = mineProximintyCount[3];
				}
				if (perimiterMineCountInt == 4)
				{
					charArray[rows * j + i] = mineProximintyCount[4];
				}
				if (perimiterMineCountInt == 5)
				{
					charArray[rows * j + i] = mineProximintyCount[5];
				}
				if (perimiterMineCountInt == 6)
				{
					charArray[rows * j + i] = mineProximintyCount[6];
				}
				if (perimiterMineCountInt == 7)
				{
					charArray[rows * j + i] = mineProximintyCount[7];
				}
				if (perimiterMineCountInt == 8)
				{
					charArray[rows * j + i] = mineProximintyCount[8];
				}
				perimiterMineCountInt = 0;
			}
		}
	}

	std::cout << std::endl;

	//prints out a message to let the user know the grid has been filled sucessfully
	std::cout << " " << mineCount << " Mines have been placed and armed..." << std::endl;


	std::cout << std::endl;
}

void Grid::printGrid()
{
	int colCount = 0;
	int rowCount = 0;
	int colNumber = 0;
	int colNumberCount = 0;
	int rowNumber = 1;

	// First for loop is to print out column numbers, resets to 0 every tenth number (Keeps it single digit)
	std::cout << "      ";
	for (colNumberCount = 0; colNumberCount < columns; colNumberCount++)
	{
		std::cout << colNumber + 1 << " ";
		colNumber++;

		if (colNumber == 9)
		{
			colNumber = -1;
		}

	}

	std::cout << std::endl;

	// For loop to creat top boarder
	std::cout << "     -";
	for (colCount = 0; colCount < columns; colCount++)
	{
		std::cout << "--";
	}

	std::cout << std::endl;

	// For loop prints the actual Array/Grid with a boarder on either side
	for (int i = 0; i < rows; i++)
	{
		// this iS for numbering the Rows, same as columns, resets to 0 every tenth number
		std::cout << " " << rowNumber++ << "  | "; rowCount++;
		if (rowNumber == 10)
		{
			rowNumber = 0;
		}

		for (int j = 0; j < columns; j++)
		{
			std::cout << charArray[rows * j + i] << " ";
		}
		std::cout << "|";
		std::cout << std::endl;

		// Possibly easier to read with an extra line space here?
		//std::cout << std::endl;
	}

	// This for loop creates the lower boarder of the grid
	std::cout << "     -";
	for (colCount = 0; colCount < columns; colCount++)
	{
		std::cout << "--";
	}

	std::cout << std::endl;
}

char Grid::getChar(int x, int y)
{
	return charArray[rows * x + y];
}

void Grid::setChar(int x, int y, char z)
{
	charArray[rows * x + y] = z;
}