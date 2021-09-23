//Struct of game statistics
struct gameStatistics
{
	int gameOption = 0; //1: Tic-Tac-Toe; 2: Tower of Hanoi; 3: n-Queens
	int number = 0;
	int usedTime = 0;
	int moved = 0;
};

bool compare(gameStatistics tmp1, gameStatistics tmp2) {
	return (tmp1.number < tmp2.number);
}
void textStatistics(int gameOption, int total, int disks, int minTime, int maxTime, int minMoved, int maxMoved, int averagedTime)
{
	string totalLabel = to_string(total);
	string fastestLabel = "The fastest time was " + to_string(minTime);
	string slowestLabel = "The slowest time was " + to_string(maxTime);
	string averagedLabel = "The average time was " + to_string(averagedTime);

	if (minTime > 1)
		fastestLabel = fastestLabel + " seconds in " + to_string(minMoved);
	else
		fastestLabel = fastestLabel + " second in " + to_string(minMoved);
	if (minMoved > 1)
		fastestLabel = fastestLabel + " moves.";
	else
		fastestLabel = fastestLabel + " move.";

	if (maxTime > 1)
		slowestLabel = slowestLabel + " seconds in " + to_string(maxMoved);
	else
		slowestLabel = slowestLabel + " second in " + to_string(maxMoved);
	if (maxMoved > 1)
		slowestLabel = slowestLabel + " moves.";
	else
		slowestLabel = slowestLabel + " move.";

	if (averagedTime > 1)
		averagedLabel = averagedLabel + " seconds.";
	else
		averagedLabel = averagedLabel + " second.";

	if (total > 1)
		totalLabel = totalLabel + " games using " + to_string(disks);
	else
		totalLabel = totalLabel + " game using " + to_string(disks);

	if (gameOption == 2)
	{

		if (disks > 1)
			totalLabel = totalLabel + " disks was played.";
		else
			totalLabel = totalLabel + " disk was played.";		
	}
	else if (gameOption == 3)
	{
		if (disks > 1)
			totalLabel = totalLabel + " queens was played.";
		else
			totalLabel = totalLabel + " queen was played.";
	}
	cout << "\n\t " << totalLabel << endl;
	cout << "\n\t\t " << fastestLabel << endl;
	cout << "\n\t\t " << slowestLabel << endl;
	cout << "\n\t\t " << averagedLabel << endl;
}
void showStatistics(vector<gameStatistics> log, int gameOption)
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
		textStatistics(gameOption, total, disks, minTime, maxTime, minMoved, maxMoved, averagedTime);
	}
}
