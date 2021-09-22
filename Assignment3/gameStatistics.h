//Struct of game statistics
struct gameStatistics
{
	int numberOfRings = 0;
	int usedTime = 0;
	int moved = 0;
};

bool compare(gameStatistics tmp1, gameStatistics tmp2) {
	return (tmp1.numberOfRings < tmp2.numberOfRings);
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
		int disks = log[i].numberOfRings;
		int maxMoved = log[i].moved;
		int minMoved = log[i].moved;
		int total = 1;
		while (j < size && i != j)
		{
			if (log[j].numberOfRings == disks)
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
		}
		i = j;
		int averagedTime = totalTime / total;
		cout << "\n\t " << total << " game using " << disks << " disk was played" << endl;
		cout << "\n\t\t The fastest time was " << minTime << " seconds in " << minMoved << " moves" << endl;
		cout << "\n\t\t The slowest time was " << maxTime << " seconds in " << maxMoved << " moves" << endl;
		cout << "\n\t\t The average time was " << averagedTime << " seconds." << endl;
	}
}