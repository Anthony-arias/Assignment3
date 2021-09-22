// Statistics.h

#ifndef STATISTICS_LOCK
#define STATISTICS_LOCK

#include <vector>

class Statistics
{
private:
	//int timeComple;
	//int stepsTaken;
	int numberOfDisks;
	int size;
	std::vector <std::vector<int>> Games;

public:
	Statistics()
	{
		numberOfDisks = 0;
		size = 0;
	}

	Statistics(int inputNumberOfDisks)
	{
		numberOfDisks = 0;
		size = 0;
		numberOfDisks = inputNumberOfDisks;
	}

	int getNumberOfDisks(void)
	{
		return numberOfDisks;
	}

	int getSize(void)
	{
		return size;
	}

	int getTimeComplet(int index)
	{
		return Games[index][0];
	}

	int getStepsTaken(int index)
	{
		return Games[index][1];
	}

	void addGameData(int inputTimeComple, int inputStepsTaken)
	{
		Games.push_back({ inputTimeComple, inputStepsTaken });
		size++;
	}

	int getFastestGame(void)
	{
		int fastestTime = Games[0][0];
		int index = 0;
		for (int i = 0; i < Games.size(); i++)
		{
			if (fastestTime > Games[i][0])
			{
				fastestTime = Games[i][0];
				index = i;
			}
		}
		return index;
	}

	int getSlowestGame(void)
	{
		int slowestTime = Games[0][0];
		int index = 0;
		for (int i = 0; i < Games.size(); i++)
		{
			if (slowestTime < Games[i][0])
			{
				slowestTime = Games[i][0];
				index = i;
			}
		}
		return index;
	}

	int getAverageTime(void)
	{
		int total = 0;
		for (int i = 0; i < Games.size(); i++)
		{
			total += Games[i][0];
		}
		return total / Games.size();
	}

};

#endif