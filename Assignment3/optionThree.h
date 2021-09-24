// optionThree.h
#ifndef OPTION_THREE_LOCK
#define OPTION_THREE_LOCK

#include <iostream>
#include "input.h"


using namespace std;

char displayGameOptions(char& option);
void displayBoard(vector< vector <char>> v);
bool checkQueenCondition(vector< vector <char>>& v, int row, int col, int size);
bool checkEmptyBoard(vector< vector <char>>& v, int size);
bool checkWinningCondition(vector<vector <char>>& v, int size);
void inputQueen(vector< vector <char>>& v, int size, int &count);
void removeQueen(vector< vector <char>>& v, int size, int &count);


// Precondition: valid char option
// Postcondition: return the option from menu
char displayGameOptions(char& option)
{
	cout << "\n\tGame Options";
	cout << "\n\t" + string(60, char(205));
	cout << "\n\tA> Place a queen";
	cout << "\n\tB> Remove an existing queen";
	cout << "\n\t" + string(60, char(196));
	cout << "\n\t0> return";
	cout << "\n\t" + string(60, char(205));
	option = inputChar("\n\tOption: ");

	return toupper(option);
}

// Precondition: valid nested char vector to display board game and the board's size
// Postcondition: input a queen from indicated position
void inputQueen(vector< vector <char>>& v, int size, int &count)
{
	int inputRow = inputInteger("\n\tPosition a queen in the row (1.." + to_string(size) + "): ", 1, size);
	int inputColumn = inputInteger("\n\tPosition a queen in the column (1.." + to_string(size) + "): ", 1, size);

	if (checkQueenCondition(v, inputRow - 1, inputColumn - 1, size))
	{
		v[inputRow - 1][inputColumn - 1] = 'Q';
		displayBoard(v);
		count++;
	}
}

// Precondition: valid nested char vector to display board game and the board's size
// Postcondition: remove a queen from indicated position
void removeQueen(vector< vector <char>>& v, int size, int &count)
{
	if (checkEmptyBoard(v, size))
		cout << "\n\tERROR: The board is empty. There is no queen to remove.\n";
	else
	{		
		int inputRow = inputInteger("\n\tEnter an existing queen from the row (1.." + to_string(size) + "): ", 1, size);
		int inputColumn = inputInteger("\n\tEnter an existing queen from the column (1.." + to_string(size) + "): ", 1, size);

		if (v[inputRow - 1][inputColumn - 1] == 'Q')
		{
			v[inputRow - 1][inputColumn - 1] = '_';
			displayBoard(v);
			count++;
		}
		else
			cout << "\n\tERROR: No such queen existed.\n";
	}
}

// Precondition: valid nested char vector to display board game, valid row, valid column, the board's size
// Postcondition: return true if queens in table is not conflicted with each other, and false if it is not
bool checkQueenCondition(vector< vector <char>>& v, int row, int col, int size)
{
	// Check columns if there are queens on the same row
	for (int i = 0; i < size; i++)
	{
		if (v[row][i] == 'Q')
		{
			displayBoard(v);
			cout << "\n\tERROR: Conflict with queens in existing row. Try again.\n";
			return false;
		}
	}
	// Check rows if there are queens on the same column
	for (int i = 0; i < size; i++)
	{
		if (v[i][col] == 'Q')
		{
			displayBoard(v);
			cout << "\n\tERROR: Conflict with queens in existing column. Try again.\n";
			return false;
		}
	}

	// Check diagonal lines if there are queens on the same line
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (v[i][j] == 'Q')
		{
			displayBoard(v);
			cout << "\n\tERROR: Conflict with queens in diagonal line. Try again.\n";
			return false;
		}
	}

	for (int i = row, j = col; i >= 0 && j < size; i--, j++)
	{
		if (v[i][j] == 'Q')
		{
			displayBoard(v);
			cout << "\n\tERROR: Conflict with queens in diagonal line. Try again.\n";
			return false;
		}
	}

	for (int i = row, j = col; i < size && j >= 0; i++, j--)
	{
		if (v[i][j] == 'Q')
		{
			displayBoard(v);
			cout << "\n\tERROR: Conflict with queens in diagonal line. Try again.\n";
			return false;
		}
	}

	for (int i = row, j = col; i < size && j < size; i++, j++)
	{
		if (v[i][j] == 'Q')
		{
			displayBoard(v);
			cout << "\n\tERROR: Conflict with queens in diagonal line. Try again.\n";
			return false;
		}
	}

	return true;
}

// Precondition: valid nested char vector to display board game and the board's size
// Postcondition: return true if winning condition is valid and false if it is not
bool checkWinningCondition(vector<vector <char>>& v, int size)
{
	int findQueen = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (v[i][j] == 'Q')
				findQueen++;

	if (findQueen == size)
		return true;
	return false;
}

// Precondition: valid nested char vector to display board game and the board's size
// Postcondition: return true if the board is empty and false if it is not
bool checkEmptyBoard(vector< vector <char>>& v, int size)
{
	int countQueen = 0;
	for (int i = 0; i < size; i++)
	{
		cout << "\t";
		for (int j = 0; j < size; j++)
		{
			if (v[i][j] != '_')
				countQueen++;
			else
				continue;
		}
	}

	if (countQueen == 0)
		return true;
	else
		return false;
	return false;
}

// Precondition: valid nested char vector to display board game
// Postcondition: display the content in board game
void displayBoard(vector< vector <char>> v)
{
	cout << endl;
	int shapeSize = v.capacity() + 2;
	for (int row = 0; row < shapeSize; ++row)
	{
		cout << "\t";
		if (row == 0 || row == shapeSize - 1)
		{
			for (int column = 0; column < shapeSize; ++column)
			{
				if (row == 0)
				{
					if (column == 0)
						cout << char(201);
					else
					{
						if (column == shapeSize - 1)
							cout << char(205) << char(187);
						else
							cout << string(2, char(205));
					}
				}
				else
				{
					if (column == 0)
						cout << char(200);
					else
					{
						if (column == shapeSize - 1)
							cout << char(205)<< char(188);
						else
							cout << string(2,char(205));
					}
				}
			}
		}

		else
		{
			for (int column = 0; column < shapeSize; ++column)
				if (column == 0)
					cout << char(186)<<" ";
				else
				{
					if(column == shapeSize - 1)
						cout << " " << char(186);
					else
					{
						int i = row - 1;
						int j = column - 1;
						if (v[i][j] == '_' || v[i][j] == 'Q')
						{
							if (i == v.capacity() - 1 && v[i][j] == '_')
							{
								if (j < v.capacity() - 1)
									cout << ' ' << char(179);
								else
									cout << ' '; 
							}
							else
							{
								if (j < v.capacity() - 1)
									cout << v[i][j] << char(179);
								else
									cout << v[i][j];
							}
						}
					}
				}		
		}
		cout << endl;
	}
		

}



#endif