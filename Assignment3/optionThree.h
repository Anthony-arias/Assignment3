// optionThree.h
#ifndef OPTION_THREE_LOCK
#define OPTION_THREE_LOCK

#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <map>
#include <numeric>
#include <list>
#include <forward_list>
#include <algorithm>
#include "input.h"


using namespace std;

void n_Queens();
char displayGameOptions(char& option);
void displayBoard(vector< vector <char>> v);
bool checkQueenCondition(vector< vector <char>>& v, int row, int col, int size);
bool checkEmptyBoard(vector< vector <char>>& v, int size);
bool checkWinningCondition(vector<vector <char>>& v, int size);
void inputQueen(vector< vector <char>>& v, int size);
void removeQueen(vector< vector <char>>& v, int size);


// Precondition: NA
// Postcondition: NA
void n_Queens()
{
	clearScreen();
	cout << "\n\tThe n-queens puzzle is the problem of placing n chess queens on a nxn chessboard";
	cout << "\n\tso that no two queens threaten each other; thus, a solution requires that no two";
	cout << "\n\tqueens share the same row, column, or diagonal. Solutions exist for all natural";
	cout << "\n\tnumbers n with the exception of n = 2 and n = 3.";

	clock_t start, end;
	int usedTime;
	int minTime = -1, maxTime = -1, averagedTime;
	vector<gameStatistics> userLog;

	do
	{
		int count = 0;
		char option = ' ';
		int n = inputInteger("\n\n\tEnter the board dimension nxn (1..64): ", 1, 64);
		start = clock();
		cout << "\n\n\t" << n << "-Queens\n";
		vector<vector<char>> board(n, vector<char>(n, '-'));
		displayBoard(board);

		do
		{
			switch (displayGameOptions(option))
			{
			case '0': return; break;
			case 'A':
				//Function to proceed step A: Place the queen
				inputQueen(board, n);
				count++;
				break;
			case 'B':
				//Function to proceed step B: Remove an existing queen
				removeQueen(board, n);
				count++;
				break;
			default: cout << "\n\tERROR-1A: Invalid input. Must be 'A','B', or '0'\n";
				break;
			}
		} while (!checkWinningCondition(board, n) && option != '0');

		cout << "\n\tCongratulation, you solved the " << n << "-Queens in " << count << " move(s).\n";
		end = clock();
		usedTime = (int)(end - start) / CLOCKS_PER_SEC;
		gameStatistics currentPlayer;
		currentPlayer.number = n;
		currentPlayer.usedTime = usedTime;
		currentPlayer.moved = count;
		userLog.push_back(currentPlayer);

	} while (isRepeat("\tPlay again? (Y-yes or N-no)? "));

	cout << "\n\tGame statistics:" << endl;
	showQueenStatistics(userLog);
}

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
void inputQueen(vector< vector <char>>& v, int size)
{
	int inputRow = inputInteger("\n\tPosition a queen in the row (1.." + to_string(size) + "): ", 1, size);
	int inputColumn = inputInteger("\n\tPosition a queen in the column (1.." + to_string(size) + "): ", 1, size);

	if (checkQueenCondition(v, inputRow - 1, inputColumn - 1, size))
	{
		v[inputRow - 1][inputColumn - 1] = 'Q';
		displayBoard(v);
	}
}

// Precondition: valid nested char vector to display board game and the board's size
// Postcondition: remove a queen from indicated position
void removeQueen(vector< vector <char>>& v, int size)
{
	if (checkEmptyBoard(v, size))
		cout << "\n\tERROR: The board is empty. There is no queen to remove.\n";
	else
	{		
		int inputRow = inputInteger("\n\tEnter an existing queen from the row (1.." + to_string(size) + "): ", 1, size);
		int inputColumn = inputInteger("\n\tEnter an existing queen from the column (1.." + to_string(size) + "): ", 1, size);

		if (v[inputRow - 1][inputColumn - 1] == 'Q')
		{
			v[inputRow - 1][inputColumn - 1] = '-';
			displayBoard(v);
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
			cout << "\n\tERROR: Conflict with queens in diagonal line. Try again\n";
			return false;
		}
	}

	for (int i = row, j = col; i >= 0 && j < size; i--, j++)
	{
		if (v[i][j] == 'Q')
		{
			displayBoard(v);
			cout << "\n\tERROR: Conflict with queens in diagonal line. Try again\n";
			return false;
		}
	}

	for (int i = row, j = col; i < size && j >= 0; i++, j--)
	{
		if (v[i][j] == 'Q')
		{
			displayBoard(v);
			cout << "\n\tERROR: Conflict with queens in diagonal line. Try again\n";
			return false;
		}
	}

	for (int i = row, j = col; i < size && j < size; i++, j++)
	{
		if (v[i][j] == 'Q')
		{
			displayBoard(v);
			cout << "\n\tERROR: Conflict with queens in diagonal line. Try again\n";
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
			if (v[i][j] != '-')
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
	cout << "\n";
	for (int i = 0; i < v.capacity(); i++)
	{
		cout << "\t";
		for (int j = 0; j < v.capacity(); j++)
			if (v[i][j] == '-' || v[i][j] == 'Q')
				cout << v[i][j] << " ";

		cout << "\n";
	}
}

#endif