// Peg.h

#ifndef PEG_LOCK
#define PEG_LOCK

#include <vector>

class Peg
{
private:
	int pegNumb;
	char pegChar;
	bool islastPeg;
	std::vector<int> disks;

public:
	Peg()
	{
		pegNumb = 0;
		pegChar = '0';
		islastPeg = false;
	}

	Peg(int inputPegNumb, char inputPegChar, bool inputLastPeg = false)
	{
		pegNumb = inputPegNumb;
		pegChar = inputPegChar;
		islastPeg = inputLastPeg;
	}

	Peg(int inputPegNumb, char inputPegChar, int numbOfRings, bool inputLastPeg = false)
	{
		pegNumb = inputPegNumb;
		pegChar = inputPegChar;
		islastPeg = inputLastPeg;
		for (int i = numbOfRings; i > 0; i--)
		{
			disks.push_back(i);
		}
	}

	void setPegNumb(int inputPegNumb)
	{
		pegNumb = inputPegNumb;
	}

	int getPegNumb(void)
	{
		return pegNumb;
	}

	void setPegChar(char inputPegChar)
	{
		pegChar = inputPegChar;
	}

	char getPegChar(void)
	{
		return pegChar;
	}

	void setIsLastPeg(bool inputLastPeg)
	{
		islastPeg = inputLastPeg;
	}

	bool getIsLastPeg()
	{
		return islastPeg;
	}

	std::vector<int> getListOfDisks()
	{
		return disks;
	}

	void removeFromTop()
	{
		if (disks.size() == 0) throw "ERROR: empty list";
		else
		{
			disks.pop_back();
		}
	}

	void addToTop(int disk)
	{
		if (disks.size() == 0)
		{
			disks.push_back(disk);
			return;
		}
		
		if (disk > disks[disks.size() - 1]) throw runtime_error( "ERROR: disk too big");
		else
		{
			disks.push_back(disk);
		}
	}

	void deleteLastElement(void)
	{
		disks.pop_back();
	}

	int getTopDisk(void)
	{
		return disks[disks.size()-1];
	}
};

#endif