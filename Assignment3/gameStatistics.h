//Struct of game statistics
struct gameStatistics
{
	int gameOption = 0; //1: Tic-Tac-Toe; 2: Tower of Hanoi; 3: n-Queens
	int number = 0;
	int usedTime = 0;
	int moved = 0;
};

// Precondition: intput two items(type: ameStatistics) need to compare 
// Postcondition: return true if item one less than item true, and false otherwise
bool compare(gameStatistics tmp1, gameStatistics tmp2) {
	return (tmp1.number < tmp2.number);
}

// Precondition: intput int gameOption, int total, int disks, int minTime, int maxTime, int minMoved, int maxMoved, int averagedTime 
// Postcondition: display text
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
		totalLabel = totalLabel + " games using ";
	else
		totalLabel = totalLabel + " game using ";

	if (gameOption == 1)
	{
		if (disks > 1)
			totalLabel = totalLabel + "of Tic-Tac-Toe were played.";
		else
			totalLabel = totalLabel + "of Tic-Tac-Toe were played.";
	}
	else
	{
		if (gameOption == 2)
		{

			if (disks > 1)
				totalLabel = totalLabel + to_string(disks) + " disks was played.";
			else
				totalLabel = totalLabel + to_string(disks) + " disk was played.";
		}
		else 
		{
			if (disks > 1)
				totalLabel = totalLabel + to_string(disks) + " queens was played.";
			else
				totalLabel = totalLabel + to_string(disks) + " queen was played.";
		}
	}
	cout << "\n\t " << totalLabel << endl;
	cout << "\n\t\t " << fastestLabel << endl;
	cout << "\n\t\t " << slowestLabel << endl;
	cout << "\n\t\t " << averagedLabel << endl;
}


// Precondition: log:  vector<gameStatistics> and gameOption: int
// Postcondition: display statistics data 
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
