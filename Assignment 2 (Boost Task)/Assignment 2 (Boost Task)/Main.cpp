// MineSweeper Game (Assingment2) - Samuel Harden

#include <iostream>
#include <ctime>
#include "MineSweeper.h"

int main()
{
	//Set the RNG at the start of the program
	srand((unsigned int)time(NULL));

	// so in main its a case of calling the MineSweeper main menu and thats it
	MineSweeper newInstance;
	newInstance.mainMenu();

	return 0;
}