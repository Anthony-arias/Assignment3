#include "input.h"
#include "Tower.h"


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
			cout << "\n\tTop disk from peg-" << s << " has moved to peg -" << d << endl;
		}
		else
		{
			source.pop(topSource);
			destination.pop(topDestination);
			if (topSource > topDestination)
			{
				source.push(topSource);
				destination.push(topDestination);
				cout << "\n\tERROR: Cannot make the move. Top disk (" << topSource << ") of peg - " << s
					<< " , is larger than top disk(" << topDestination << ") of peg - " << d << endl;
				cout << "\t	    Please choose again." << endl;
			}
			else
			{
				destination.push(topDestination);
				destination.push(topSource);
				cout << "\n\tTop disk from peg-" << s << " has moved to peg -" << d << endl;
			}
		}
	}

}

void towerOfHanoi(int numberOfRings, Tower &A, Tower &B, Tower &C, char source, char destination)
{

	
	if (source == destination)
	{
		cout << "\n\tERROR: Cannot make the move. The selected end peg cannot be the same as the selected start peg." << endl;
		cout << "	    Please choose again." << endl;
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
void display(Tower A, Tower B, Tower C, int numberOfRings)
{
	
	if (numberOfRings > 9)
	{
		
		cout << "\n\tTower of Hanoi" << endl;

	}
	else
	{
		cout << "\n\tTower of Hanoi" << endl;
	}
}

