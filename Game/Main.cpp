#include"TicTacToe.h"
#include <iostream>

bool getBool(std::string);
void optionOne();

int main() 
{
	optionOne();
}

bool getBool(std::string prompt)
{
	while (true)
	{
		char userInput = inputChar(prompt);
		switch (userInput)
		{
		case 'y': case 'Y': return true;
		case 'n': case 'N': return false;
		default:
			cout << "That's not possible!! Try again." << endl;
		}
	}
}

void optionOne()
{
	std::cout << std::endl;
	std::cout << "\tTic - tac - toe(also known as Noughts and crosses or Xs and Os) is a game for two" << std::endl;
	std::cout << "\tplayers, Xand O, who take turns marking the spaces in a 3╫3 grid.The player who" << std::endl;
	std::cout << "\tsucceeds in placing three of their marks in a horizontal, vertical, or diagonal" << std::endl;
	std::cout << "\trow wins the game." << std::endl;
	std::cout << "\tThis tic - tac - toe program plays against the computer.Human player, X, will always" << std::endl;
	std::cout << "\tfirst.Time will be recorded for the fastestand the slowest game.Average time will" << std::endl;
	std::cout << "\tthen be calculatedand displayed." << std::endl;
	std::cout << std::endl;
	std::cout << "\tGame begins..." << std::endl;
	std::cout << std::endl;


	TicTacToe game;
	do
	{
		game.playGame();

	} while (getBool("\n\tWould you like to play again? (Y-Yes or N-No)"));

	std::cout << "\n\tGame Statistics:" << std::endl;
	std::cout << std::endl;
	std::cout << "\t" << game.getGamesPlayed() << " game using of Tic-Tac-Toe were played." << std::endl;
	std::cout << "\t\tFastest Time: " << game.getQuickestTime() << "(s) in " << game.getLeastMoves() << " move(s)." << std::endl;
	std::cout << "\t\tSlowest Time: " << game.getSlowestTime() << "(s) in " << game.getMostMoves() << " move(s)." << std::endl;
	std::cout << "\t\tAverage Time: " << game.getAverageTime() << "(s)" << std::endl;

}