// Class for player grid and the mine grid

#pragma once

class Grid
{

public:

	Grid();
	//Constructor
	Grid(int x, int y);

	//Deconstructor
	~Grid();

	void fillGridWithMines(int m);
	void printGrid();
	char getChar(int x, int y);
	void setChar(int x, int y, char z);

private:

	int rows;
	int columns;
	int mineCount;
	char* charArray;

}; // end of Grid Class

