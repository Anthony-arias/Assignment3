// optionTwo.h

#ifndef OPTION_TWO_LOCK
#define OPTION_TWO_LOCK

#include <string>
#include <iostream>
#include <ctime>
#include "input.h"
#include "Peg.h"
#include "Statistics.h"

void displayRules(void);
void displayPegs(Peg pegOne, Peg pegTwo, Peg pegThree, int maxRingNumb);
char getPeg(string prompt);
char getYesNo(string prompt);
void moveDisk(Peg* startingPeg, Peg* endingPeg);

using namespace std;

void playProgramTwo(vector<Statistics>& allGames)
{
	clearScreen();
	displayRules();

	int maxNumbOfRings = inputInteger("\tEnter the number of rings (1..64) to begin: ", 1, 64);

	Peg pegOne = Peg(1, 'A', maxNumbOfRings);
	Peg pegTwo = Peg(2, 'B');
	Peg pegThree = Peg(3, 'C', true);

	clock_t start = clock();
	int duration = 0;

	int moveCount = 0;

	do
	{
		clearScreen();
		displayRules();
		displayPegs(pegOne, pegTwo, pegThree, maxNumbOfRings);

		if (pegThree.getListOfDisks().size() == maxNumbOfRings)
		{
			cout << "\n\tCongratulation! You have solved the game in " + to_string(moveCount + 1) + " moves." << endl;
			char input
		}
		
		char startPeg = getPeg("\tSelect the top disk from the start peg (A, B, C, or Q-quit): ");
		char endPeg = getPeg("\tSelect the end peg (A, B, C or Q-quit) to move the selected disk: ");

		if (startPeg == 'Q' || endPeg == 'Q') return;
		if (startPeg == endPeg)
		{
			cout << "\n\tERROR: Cannot make the move. The selected end peg cannot be the same as the selected start peg.\n";
			pause("\t       Please choose again.");
			continue;
		}
		
		Peg* startingPeg = NULL;
		Peg* endingPeg = NULL;
		if (startPeg == 'A') startingPeg = &pegOne;
		if (startPeg == 'B') startingPeg = &pegTwo;
		if (startPeg == 'C') startingPeg = &pegThree;

		if (endPeg == 'A') endingPeg = &pegOne;
		if (endPeg == 'B') endingPeg = &pegTwo;
		if (endPeg == 'C') endingPeg = &pegThree;

		moveCount++;
		moveDisk(startingPeg, endingPeg);
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;

	} while (true);

	for (int i = 0; i < allGames.size(); i++)
	{
		if (allGames[i].getNumberOfDisks() == maxNumbOfRings)
		{
			allGames[i].addGameData(duration, moveCount);
			return;
		}
	}
	Statistics games = Statistics(maxNumbOfRings);
	games.addGameData(duration, moveCount);
	allGames.push_back(games);

}

void displayRules(void)
{
	cout << "\tThe Tower of Hanoi also called the Tower of Brahma or Lucas' Tower is a mathematical game." << endl;
	cout << "\tIt consists of three pegs and a number of rings of different sizes, which can slide onto" << endl;
	cout << "\tany peg. The game starts with the rings in a neat stack in ascending order of size on one" << endl;
	cout << "\tpeg, the smallest at the top, thus making a conical shape." << endl << endl;
	cout << "\tThe objective of the game is to move the entire stack from the starting peg-A to ending peg-B," << endl;
	cout << "\tobeying the following simple rules:" << endl << endl;
	cout << "\t\t1. Only one disk can be moved at a time." << endl;
	cout << "\t\t2. Each move consists of taking the upper disk from one of the stacks and" << endl;
	cout << "\t\t   placing it on top of another stack or on an empty peg." << endl;
	cout << "\t\t3. No larger disk may be placed on top of a smaller disk." << endl << endl;
}

void displayPegs(Peg pegOne, Peg pegTwo, Peg pegThree, int maxRingNumb)
{
	cout << "\tTower of Hanoi" << endl << endl;
	cout << "\t" + string(maxRingNumb, ' ') + char(186) + string(maxRingNumb, ' ') + " " 
		+ string(maxRingNumb, ' ') + char(186) + string(maxRingNumb, ' ') + " "
		+ string(maxRingNumb, ' ') + char(186) << endl;

	for (int i = maxRingNumb-1; i >= 0; i--)
	{
		if (pegOne.getListOfDisks().size() < i + 1)
		{
			cout << "\t" + string(maxRingNumb, ' ') + char(186)
				+ string(maxRingNumb, ' ');
		}
		else
		{
			int diskSize = pegOne.getListOfDisks()[i];
			cout << "\t" + string(maxRingNumb - diskSize, ' ') + string(diskSize, char(223))
				+ to_string(diskSize) + string(diskSize, char(223))
				+ string(maxRingNumb - diskSize, ' ');
		}
		

		if (pegTwo.getListOfDisks().size() < i + 1)
		{
			cout << string(maxRingNumb + 1, ' ') + char(186)
				+ string(maxRingNumb, ' ');
		}
		else
		{
			int diskSize = pegTwo.getListOfDisks()[i];
			cout << " " + string(maxRingNumb - diskSize, ' ') + string(diskSize, char(223))
				+ to_string(diskSize) + string(diskSize, char(223))
				+ string(maxRingNumb - diskSize, ' ');
		}

		if (pegThree.getListOfDisks().size() < i + 1)
		{
			cout << string(maxRingNumb + 1, ' ') + char(186)
				+ string(maxRingNumb - i - 1, ' ');
		}
		else
		{
			int diskSize = pegThree.getListOfDisks()[i];
			cout << " " + string(maxRingNumb - diskSize, ' ') + string(diskSize, char(223))
				+ to_string(diskSize) + string(diskSize, char(223))
				+ string(maxRingNumb - diskSize, ' ');
		}

		cout << endl;
	}

	cout << "\t" + string(maxRingNumb, char(205)) + char(202) + string(maxRingNumb, char(205)) + " "
		+ string(maxRingNumb, char(205)) + char(202) + string(maxRingNumb, char(205)) + " "
		+ string(maxRingNumb, char(205)) + char(202) + string(maxRingNumb, char(205)) << endl;

	cout << "\t" + string(maxRingNumb, ' ') + "A" + string(maxRingNumb, ' ') + " "
		+ string(maxRingNumb, ' ') + "B" + string(maxRingNumb, ' ') + " "
		+ string(maxRingNumb, ' ') + "C" << endl << endl;
}

char getPeg(string prompt)
{
	do
	{
		int userInput = inputChar(prompt);
		switch (userInput)
		{
		case 'q': case 'Q': return 'Q';
		case 'a': case 'A': return 'A';
		case 'b': case 'B': return 'B';
		case 'c': case 'C': return 'C';
		default: cout << "\tERROR-1A: Invalid input. Must be 'A','B','C', or 'Q'" << endl;
		}
	} while (true);
}

char getYesNo(string prompt)
{
	do
	{
		int userInput = inputChar(prompt);
		switch (userInput)
		{
		case 'y': case 'Y': return 'Y';
		case 'n': case 'N': return 'N';
		default: cout << "\tERROR-1A: Invalid input. Must be 'Y', or 'N'" << endl;
		}
	} while (true);
}

void moveDisk(Peg* startingPeg, Peg* endingPeg)
{
	if (startingPeg->getListOfDisks().size() == 0)
	{
		cout << "\n\tCannot make the move. There is no disk in the selected peg-" + string(1, startingPeg->getPegChar()) << endl;
		pause("\t       Please choose again.");
		return;
	}

	int temp = startingPeg->getListOfDisks()[startingPeg->getListOfDisks().size() - 1];

	try {endingPeg->addToTop(temp); }
	catch (exception) 
	{ 
		cout << "\n\tERROR: Cannot make the move. Top disk (" + to_string(startingPeg->getTopDisk()) + ") of peg-"+ startingPeg->getPegChar() +","
			+"is larger than top disk(" + to_string(endingPeg->getTopDisk()) + ") of peg-" + endingPeg->getPegChar() + "." << endl;
		pause("\t       Please choose again.");
		return;
	}

	startingPeg->deleteLastElement();
}

#endif