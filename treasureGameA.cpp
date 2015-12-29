// treasureGameA.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
using namespace std;

int rows = 0, columns = 0, rowGuess, columnGuess, randRow, randColumn;
bool isRunning;

void drawGrid() 
{
	for (int r = 0; r < rows; r++)
	{
		cout << endl;
		for (int c = 0; c < columns; c++)
		{
			cout << "*";
		}
	}
}

void findTreasure()
{
	cout << "Please input your current guess" << endl;
	cin >> columnGuess >> rowGuess;
	cout << "You guessed " << columnGuess  << "," << rowGuess << endl;
	if (rowGuess == randRow && columnGuess == randColumn)
	{
		cout << "you guessed correctly. The treasure was located at " << randColumn << "," << randRow << endl;
		isRunning = false;
	}
	else
	{
		cout << "incorrect guess";
		findTreasure();
	}
}

int main()
{
	cout << "Welcome to treasure hunt. Your job is to find the treasure hidden in the grid.";
	cout << "Please input the number of columns and rows in your grid seperated by a space (i.e. 4 3 for a 4x3 grid)" << endl;
	cin >> columns >> rows;
	if (columns == 0 || rows == 0) {
		cout << "Sorry. You can't have zero rows or columns, or use a comma when inputting the row and column values. Please try again." << endl;
	}
	else {
		drawGrid();
		cout << endl;
		randColumn = rand() % columns;
		randRow = rand() % rows;
		findTreasure();
	}
	cout << "Thank you for playing" << endl;
	return 0;
}