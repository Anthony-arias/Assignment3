//Struct of game statistics
struct gameStatistics
{
	int number = 0;
	int usedTime = 0;
	int moved = 0;
};

bool compare(gameStatistics tmp1, gameStatistics tmp2) {
	return (tmp1.number < tmp2.number);
}
void textStatistics(int total, int disks, int minTime, int maxTime, int minMoved, int maxMoved, int averagedTime)
{
	string totalLabel = to_string(total);
	if (total > 1)
		totalLabel = totalLabel + " games using " + to_string(disks);
	else
		totalLabel = totalLabel + " game using " + to_string(disks);
	if (disks > 1)
		totalLabel = totalLabel + " disks was played.";
	else
		totalLabel = totalLabel + " disk was played.";
	cout << "\n\t " << totalLabel << endl;

	string fastestLabel = "The fastest time was " + to_string(minTime);
	if (minTime > 1)
		fastestLabel = fastestLabel + " seconds in " + to_string(minMoved);
	else
		fastestLabel = fastestLabel + " second in " + to_string(minMoved);
	if (minMoved > 1)
		fastestLabel = fastestLabel + " moves.";
	else
		fastestLabel = fastestLabel + " move.";
	cout << "\n\t\t " << fastestLabel << endl;

	string slowestLabel = "The slowest time was " + to_string(maxTime);
	if (maxTime > 1)
		slowestLabel = slowestLabel + " seconds in " + to_string(maxMoved);
	else
		slowestLabel = slowestLabel + " second in " + to_string(maxMoved);
	if (maxMoved > 1)
		slowestLabel = slowestLabel + " moves.";
	else
		slowestLabel = slowestLabel + " move.";
	cout << "\n\t\t " << slowestLabel << endl;

	string averagedLabel = "The average time was " + to_string(averagedTime);
	if (averagedTime > 1)
		averagedLabel = averagedLabel + " seconds.";
	else
		averagedLabel = averagedLabel + " second.";
	cout << "\n\t\t " << averagedLabel << endl;
}
void showStatistics(vector<gameStatistics> log)
{
	sort(log.begin(), log.end(), compare);
	int size = log.size();
	int i = 0;
	while (i < size)
	{
		int j = i + 1;
		int minTime = log[i].usedTime;
		int maxTime = log[i].usedTime;
		int totalTime = log[i].usedTime;
		int disks = log[i].number;
		int maxMoved = log[i].moved;
		int minMoved = log[i].moved;
		int total = 1;
		while (j < size && i != j)
		{
			if (log[j].number == disks)
			{
				total++;
				totalTime = totalTime + log[j].usedTime;
				if (log[j].usedTime < minTime)
				{
					minTime = log[j].usedTime;
					minMoved = log[j].moved;
				}
				if (log[j].usedTime > maxTime)
				{
					maxTime = log[j].usedTime;
					maxMoved = log[j].moved;
				}
				j++;
			}
			else
				break;
		}
		i = j;
		int averagedTime = totalTime / total;
		textStatistics(total,disks,minTime,maxTime,minMoved,maxMoved,averagedTime);
	}
}

// Precondition: valid vector of struct
// Postcondition: display game statistics
void showQueenStatistics(vector<gameStatistics> log)
{
	sort(log.begin(), log.end(), compare);
	int size = log.size();
	int i = 0;
	while (i < size)
	{
		int j = i + 1;
		int minTime = log[i].usedTime;
		int maxTime = log[i].usedTime;
		int totalTime = log[i].usedTime;
		int queens = log[i].number;
		int maxMoved = log[i].moved;
		int minMoved = log[i].moved;
		int total = 1;
		while (j < size && i != j)
		{
			if (log[j].number == queens)
			{
				total++;
				totalTime = totalTime + log[j].usedTime;
				if (log[j].usedTime < minTime)
				{
					minTime = log[j].usedTime;
					minMoved = log[j].moved;
				}
				if (log[j].usedTime > maxTime)
				{
					maxTime = log[j].usedTime;
					maxMoved = log[j].moved;
				}
				j++;
			}
			else
				break;
		}
		i = j;
		int averagedTime = totalTime / total;

		if (total == 1)
		{
			cout << "\n\t " << total << " game using " << queens << " queen(s) was played." << endl;
			cout << "\n\t\t The fastest time was " << minTime << " seconds in " << minMoved << " moves." << endl;
			cout << "\n\t\t The slowest time was " << maxTime << " seconds in " << maxMoved << " moves." << endl;
			cout << "\n\t\t The average time was " << averagedTime << " seconds." << endl;
		}
		else
		{
			cout << "\n\t " << total << " games using " << queens << " queen(s) were played." << endl;
			cout << "\n\t\t The fastest time was " << minTime << " seconds in " << minMoved << " moves." << endl;
			cout << "\n\t\t The slowest time was " << maxTime << " seconds in " << maxMoved << " moves." << endl;
			cout << "\n\t\t The average time was " << averagedTime << " seconds." << endl;
		}

	}
}
