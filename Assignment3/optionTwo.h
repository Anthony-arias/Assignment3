#include "input.h"
#include "Tower.h"

// Precondition: intput the original tower and destination tower and names of them
// Postcondition: move the disk from the original tower to the destination tower
void movedDicks(Tower &source, Tower &destination, char s, char d)
{
	int topSource, topDestination;
	if (source.isEmpty())
	{
		cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-" << s << endl;
		cout << "\t       Please chooser again." << endl;
	}
	else
	{
		if (destination.isEmpty())
		{
			source.pop(topSource);
			destination.push(topSource);
			cout << "\n\tTop disk from peg-" << s << " has moved to peg-" << d << endl;
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
					<< ", is larger than top disk(" << topDestination << ") of peg-" << d << endl;
				cout << "\t       Please chooser again." << endl;
			}
			else
			{
				destination.push(topDestination);
				destination.push(topSource);
				cout << "\n\tTop disk from peg-" << s << " has moved to peg-" << d << endl;
			}
		}
	}

}

// Precondition: intput number of rings, three towers and names of the original tower and destination tower
// Postcondition: move the disk from the original tower to the destination tower
void towerOfHanoi(int numberOfRings, Tower &A, Tower &B, Tower &C, char source, char destination)
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
				movedDicks(A, B, source, destination);
			else
				movedDicks(A, C, source, destination);
		}
		else
		{
			if (source == 'B')
			{
				if (destination == 'A')
					movedDicks(B, A, source, destination);
				else
					movedDicks(B, C, source, destination);
			}
			else
			{
				if (destination == 'A')
					movedDicks(C, A, source, destination);
				else
					movedDicks(C, B, source, destination);
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

