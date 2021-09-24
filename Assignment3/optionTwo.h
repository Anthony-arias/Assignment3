#include "input.h"
#include "Tower.h"

// Precondition: intput the original tower and destination tower and names of them
// Postcondition: move the disk from the original tower to the destination tower
void movedDisks(Tower &source, Tower &destination, char s, char d,int &count)
{
	int topSource, topDestination;
	if (source.isEmpty())
	{
		cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-" << s << "." << endl;
		cout << "\t       Please chooser again." << endl;
	}
	else
	{
		if (destination.isEmpty())
		{
			source.pop(topSource);
			destination.push(topSource);
			cout << "\n\tTop disk from peg-" << s << " has moved to peg-" << d << "." << endl;
			count++;
		}
		else
		{
			source.pop(topSource);
			destination.pop(topDestination);
			if (topSource > topDestination)
			{
				source.push(topSource);
				destination.push(topDestination);
				cout << "\n\tERROR: Cannot make the move. Top disk(" << topSource << ") of peg-" << s
					<< ", is larger than top disk(" << topDestination << ") of peg-" << d << "." << endl;
				cout << "\t       Please chooser again." << endl;
			}
			else
			{
				destination.push(topDestination);
				destination.push(topSource);
				cout << "\n\tTop disk from peg-" << s << " has moved to peg-" << d << "." << endl;
				count++;
			}
		}
	}

}

// Precondition: intput number of rings, three towers and names of the original tower and destination tower
// Postcondition: move the disk from the original tower to the destination tower
void towerOfHanoi(int numberOfRings, Tower &A, Tower &B, Tower &C, char source, char destination, int &count)
{

	
	if (source == destination)
	{
		cout << "\n\tERROR: Cannot make the move. The selected end peg cannot be the same as the selected start peg." << endl;
		cout << "\t       Please chooser again." << endl;
	}
	else
	{

		if (source == 'A')
		{
			if(destination =='B')
				movedDisks(A, B, source, destination, count);
			else
				movedDisks(A, C, source, destination, count);
		}
		else
		{
			if (source == 'B')
			{
				if (destination == 'A')
					movedDisks(B, A, source, destination, count);
				else
					movedDisks(B, C, source, destination, count);
			}
			else
			{
				if (destination == 'A')
					movedDisks(C, A, source, destination, count);
				else
					movedDisks(C, B, source, destination, count);
			}
		}
	}
}

// Precondition: intput tree towers and number of rings
// Postcondition: display the content of three towers
void display(Tower A, Tower B, Tower C, int numberOfRings)
{
	vector<int>dataA;
	vector<int>dataB;
	vector<int>dataC;
	dataA = A.getAllValues(numberOfRings);
	dataB = B.getAllValues(numberOfRings);
	dataC = C.getAllValues(numberOfRings);
	sort(dataA.begin(), dataA.end());
	sort(dataB.begin(), dataB.end());
	sort(dataC.begin(), dataC.end());

	string* graphic = new string[numberOfRings + 1];
	for (int i = 0; i <= numberOfRings; i++)
	{
		if (i == 0)
			graphic[0] = string(numberOfRings, char(32)) + string(1, char(186)) + string(numberOfRings, char(32));
		else
			graphic[i] = string(numberOfRings - i, char(32)) + string(i, char(254)) + to_string(i) + string(i, char(254)) + string(numberOfRings - i, char(32));
	}
	string * noGraphic = new string[numberOfRings + 1];
	noGraphic[0] = string(5, char(32)) + string(1, char(186)) + string(5, char(32));
	for (int index = 1; index <= numberOfRings; index++)
		noGraphic[index]= string(5, char(32)) + to_string(index) + string(5, char(32));
		
	if (numberOfRings > 9)
	{
		
		cout << "\n\tTower of Hanoi\n" << endl;
		cout << "\t\t" << noGraphic[0] << "\t" << noGraphic[0] << "\t" << noGraphic[0] << endl;
		for (int i = 0; i < numberOfRings; i++)
			cout << "\t\t" << noGraphic[dataA[i]] << "\t" << noGraphic[dataB[i]] << "\t" << noGraphic[dataC[i]] << endl;
		cout << "\t\t" << string(5, char(205)) + string(1, char(202)) + string(5, char(205)) << "\t" 
			<< string(5, char(205)) + string(1, char(202)) + string(5, char(205)) << "\t" << string(5, char(205)) + string(1, char(202)) + string(5, char(205)) << endl;
		cout << "\t\t" << string(5, char(32)) + "A" + string(5, char(32)) << "\t" << string(5, char(32)) + "B" + string(5, char(32))
			<< "\t" << string(5, char(32)) + "C" + string(5, char(32)) << endl;

	}
	else
	{
		cout << "\n\tTower of Hanoi\n" << endl;
		cout << "\t\t" << graphic[0] << "\t" << graphic[0] <<"\t" << graphic[0] << endl;
		for (int i = 0; i < numberOfRings; i++)
			cout << "\t\t" << graphic[dataA[i]] << "\t" << graphic[dataB[i]] << "\t" << graphic[dataC[i]] << endl;
		cout << "\t\t" << string(numberOfRings, char(205)) + string(1, char(202)) + string(numberOfRings, char(205)) << "\t"
			<< string(numberOfRings, char(205)) + string(1, char(202)) + string(numberOfRings, char(205)) << "\t" << string(numberOfRings, char(205)) + string(1, char(202)) + string(numberOfRings, char(205)) << endl;
		cout << "\t\t" << string(numberOfRings, char(32)) + "A" + string(numberOfRings, char(32)) << "\t" << string(numberOfRings, char(32)) + "B" + string(numberOfRings, char(32))
			<< "\t" << string(numberOfRings, char(32)) + "C" + string(numberOfRings, char(32)) << endl;
	}
	// Free the memory.
	delete[] graphic;
	graphic = nullptr;
	delete[] noGraphic;
	noGraphic = nullptr;

}

Van

#include <string>
#include <iostream>
#include <ctime>
#include "input.h"
#include "Peg.h"

void displayRules(void);
void displayPegs(Peg pegOne, Peg pegTwo, Peg pegThree, int maxRingNumb);
char getPeg(string prompt);
void moveDisk(Peg* startingPeg, Peg* endingPeg);

using namespace std;

void playProgramTwo(void)
{
	clearScreen();
	displayRules();

	int maxNumbOfRings = inputInteger("\tEnter the number of rings (1..64) to begin: ", 1, 64);

	Peg pegOne = Peg(1, 'A', maxNumbOfRings);
	Peg pegTwo = Peg(2, 'B');
	Peg pegThree = Peg(3, 'C', true);

	clock_t start = clock();
	int duration;

	int moveCount = 0;

	do
	{
		clearScreen();
		displayRules();
		displayPegs(pegOne, pegTwo, pegThree, maxNumbOfRings);

		if (pegThree.getListOfDisks().size() == maxNumbOfRings)
		{
			duration = (clock() - start) / (int)CLOCKS_PER_SEC;
			cout << "\tCongratulation! You have solved the game in " + to_string(moveCount) + " moves." << endl;
			cout << "\t\tThe fastest time was " + to_string(duration) + " seconds in " + to_string(moveCount) + " moves." << endl;
			break;
		}
		
		char startPeg = getPeg("\tSelect the top disk from the start peg (A, B, C, or Q-quit): ");
		char endPeg = getPeg("\tSelect the end peg (A, B, C or Q-quit) to move the selected disk: ");

		if (startPeg == 'Q' || endPeg == 'Q') break;
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

	} while (true);
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
 master
