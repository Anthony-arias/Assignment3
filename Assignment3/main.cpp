// main.cpp

// Team: Anthony, An, Van, Vincent, Nhan
// Chapter 3: 
// 

#include <iostream>
#include <string>
#include <vector>
#include "input.h"
#include "optionTwo.h"
#include "Tower.h"
#include "time.h"
#include "gameStatistics.h"
#include "optionThree.h"

void mainMenu(void);
void programOne(void);
void programTwo(void);
void programThree(void);
void displayMainMenu(void);

using namespace std;

int main(void)
{
    mainMenu();
    return EXIT_SUCCESS;
}

//PreCondition: NA
//PostCondition: redirects user to different menus based on their choice
void mainMenu(void)
{
    do
    {
        clearScreen();

        displayMainMenu();

        int userInput = inputInteger("\t\tOption: ");
        switch (userInput)
        {
        case 0: clearScreen(); return;
        case 1: clearScreen(); programOne(); pause("\n\t\tPress enter to continue..."); break;
        case 2: clearScreen(); programTwo(); pause("\n\t\tPress enter to continue..."); break;
        case 3: clearScreen(); programThree(); pause("\n\t\tPress enter to continue..."); break;
        default: cout << "\t\tERROR-3A: Invalid input. Must be from 0..2." << endl;
            pause("\n\t\tPress enter to continue...");
        }
    } while (true);
}

//PreCondition: 
//PostCondition:
void programOne(void)
{

    do
    {
        clearScreen();
        /*display here*/

        int option = inputInteger("\t\tOption: ");
        switch (option)
        {
        case '0': return;
        /*stuff here*/
        default: cout << "\t\tERROR-1A: Invalid input. Must be" << endl;
            pause("\n\t\tPress enter to continue...");
        }
        
    } while (true);
}

//PreCondition: 
//PostCondition:
void programTwo(void)
{
	clearScreen();
	cout << "2> Tower of Hanoi" << endl;
	cout << string(100, char(196)) << endl;
	cout << "The Tower of Hanoi also called the Tower of Brahma or Lucas' Tower is a mathematical game." << endl;
	cout << "It consists of three pegs and a number of rings of different sizes, which can slide onto" << endl;
	cout << "any peg.The game starts with the rings in a neat stack in ascending order of size on one" << endl;
	cout << "peg, the smallest at the top, thus making a conical shape." << endl;
	cout << "\nThe objective of the game is to move the entire stack from the starting peg - A to ending peg - B," << endl;
	cout << "obeying the following simple rules :" << endl;
	cout << "\n\t1. Only one disk can be moved at a time." << endl;
	cout << "\t2. Each move consists of taking the upper disk from one of the stacks and" << endl;
	cout << "\t   placing it on top of another stack or on an empty peg." << endl;
	cout << "\t3. No larger disk may be placed on top of a smaller disk." << endl;
	clock_t start, end;
	int usedTime;
	vector<gameStatistics>userLog;
	do
	{
		int numberOfRings = inputInteger("\n\t Enter the number of rings (1..64) to begin: ", 1, 64);
		start = clock();
		if (numberOfRings >= 10)
			cout << "\n\tNote: The rings will be represented with numbers (1 is the smallest size and " << numberOfRings << " is the largest size)." << endl;
		int count = 0;
		Tower pegA, pegB, pegC;
		for (int i = numberOfRings; i >= 1; i--)
			pegA.push(i);
		display(pegA, pegB, pegC, numberOfRings);
		do
		{
			char source, destination;

			while (true)
			{
				source = inputChar("\tSelect the top disk from the start peg (A, B, C, or Q - quit) : ");
				if (source == 'A' || source == 'B' || source == 'C')
					break;
				else
				{
					if (source == 'Q')
						return;
					else
						cout << "\t\tERROR-1A: Invalid input. Must be 'A','B','C', or 'Q'" << endl;
				}
			}

			while (true)
			{
				destination = inputChar("\tSelect the end peg (A, B, C or Q-quit) to move the selected disk: ");
				if (destination == 'A' || destination == 'B' || destination == 'C')
					break;
				else
				{
					if (destination == 'Q')
						return;
					else
						cout << "\t\tERROR-1A: Invalid input. Must be 'A','B','C', or 'Q'" << endl;
				}
			}
			towerOfHanoi(numberOfRings, pegA, pegB, pegC, source, destination,count);
			display(pegA, pegB, pegC, numberOfRings);
		} while (!pegA.isEmpty() || !pegB.isEmpty());
		if (count == 1)
			cout << "\n\tCongratulation! You have solved the game in " << count << " move." << endl;
		else
			cout << "\n\tCongratulation! You have solved the game in " << count << " moves." << endl;
		end = clock();
		usedTime = (int)(end - start) / CLOCKS_PER_SEC;
		gameStatistics currentPlayer;
		currentPlayer.gameOption = 2;
		currentPlayer.number = numberOfRings;
		currentPlayer.usedTime = usedTime;
		currentPlayer.moved = count;
		userLog.push_back(currentPlayer);
	} while (isRepeat("\tPlay again? (Y-yes or N-no)? "));
	cout << "\n\tGame statistics:" << endl;
	showStatistics(userLog, 2);
}
//PreCondition: 
//PostCondition:
void programThree(void)
{
	clearScreen();
	cout << "3> n-Queens" << endl;
	cout << string(100, char(196)) << endl;
	cout << "\n\tThe n-queens puzzle is the problem of placing n chess queens on a nxn chessboard";
	cout << "\n\tso that no two queens threaten each other; thus, a solution requires that no two";
	cout << "\n\tqueens share the same row, column, or diagonal. Solutions exist for all natural";
	cout << "\n\tnumbers n with the exception of n = 2 and n = 3.";

	clock_t start, end;
	int usedTime;
	vector<gameStatistics> userLog;

	do
	{
		int count = 0;
		char option = ' ';
		int n = inputInteger("\n\n\tEnter the board dimension nxn (1..64): ", 1, 64);
		start = clock();
		cout << "\n\n\t" << n << "-Queens\n";
		vector<vector<char>> board(n, vector<char>(n, '_'));
		displayBoard(board);

		do
		{
			switch (displayGameOptions(option))
			{
			case '0': return; break;
			case 'A':
				//Function to proceed step A: Place the queen
				inputQueen(board, n, count);
				break;
			case 'B':
				//Function to proceed step B: Remove an existing queen
				removeQueen(board, n, count);
				break;
			default: cout << "\n\tERROR-1A: Invalid input. Must be 'A','B', or '0'\n";
				break;
			}
		} while (!checkWinningCondition(board, n) && option != '0');
		if (count == 1)
			cout << "\n\tCongratulation, you solved the " << n << "-Queens in " << count << " move." << endl;
		else
			cout << "\n\tCongratulation, you solved the " << n << "-Queens in " << count << " moves." << endl;
		end = clock();
		usedTime = (int)(end - start) / CLOCKS_PER_SEC;
		gameStatistics currentPlayer;
		currentPlayer.gameOption = 3;
		currentPlayer.number = n;
		currentPlayer.usedTime = usedTime;
		currentPlayer.moved = count;
		userLog.push_back(currentPlayer);

	} while (isRepeat("\tPlay again? (Y-yes or N-no)? "));

	cout << "\n\tGame statistics:" << endl;
	showStatistics(userLog, 3);
}

//PreCondition: NA
//PostCondition: displays main menu options
void displayMainMenu(void)
{
    cout << "\n\tCMPR131 Chapter 3 - Games Applications using Container by Anthony, An, Van, Vincent, Nhan" << endl;
    cout << "\t" + string(85, char(205)) << endl;
    cout << "\t\t1> Tic-Tac-Toe" << endl;
    cout << "\t\t2> Tower of Hanoi" << endl;
    cout << "\t\t3> n-Queens" << endl;
    cout << "\t" + string(85, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(85, char(205)) << endl;
}
