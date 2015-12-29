// treasureGameB.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

int rows, columns, rowGuess, columnGuess, treasureRow, treasureColumn, guessAttempts;
static vector<vector<char> > vecGrid;

void initializeGrid() 
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			vecGrid[r][c] = '*';
		}
	}
}
void drawGrid()
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			cout << vecGrid[r][c] << ' ';
		}
		cout << endl;
	}
}

void findTreasure()
{
	cout << endl << "Please input your guess" << endl;
	cin >> rowGuess >> columnGuess;
	guessAttempts++;
	cout << "You guessed " << rowGuess << "," << columnGuess << endl;
	if (rowGuess == treasureRow && columnGuess == treasureColumn)
	{
		vecGrid[--rowGuess][--columnGuess] = '!';
		drawGrid();
		cout << "you guessed correctly. The treasure was located at " << treasureRow << ", " << treasureColumn << endl;
	}
	else if (rowGuess > rows || columnGuess > columns)
	{
		cout << "You entered a guess larger then the amount of rows or columns in the grid. Please try again with a smaller guess.";
		drawGrid();
	}
	else
	{
		vecGrid[--rowGuess][--columnGuess] = 'o';
		cout << "incorrect guess" << endl;
		drawGrid();
		findTreasure();
	}
}

int main()
{
	srand(time(NULL));
	cout << "Welcome to treasure hunt. Your job is to find the treasure hidden in the grid." << endl << "Please input the number of columns and rows in your grid seperated by a space " << endl << "(i.e. 4 3 for a 4x3 grid)" << endl;
	cin >> columns >> rows;
	if (columns == 0 || rows == 0) {
		cout << "Sorry. You can't have zero rows or columns, or use a comma when inputting the row and column values. Either that or there was another error. Please try again." << endl;
	}
	if (columns > 315)
	{
		columns = 315;
		drawGrid();
		cout << "Too large a value was entered. The columns have been set to 315 by default.";
	}
	else {
		treasureColumn = rand() % columns;
		treasureRow = rand() % rows;
		vecGrid.resize(rows);
		for (int i = 0; i < rows; i++)
		{
			vecGrid[i].resize(columns);
		}
		initializeGrid();
		drawGrid();
		cout << endl;
		findTreasure();
	}
	cout << "Thank you for playing" << endl;
    return 0;
}

