#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "input.h"

#ifndef GAME_LOCK
#define GAME_LOCK

class TicTacToe
{
private:
    struct Move
    {
        int row;
        int column;
        int score;
    };

    char player;
    char computer;
    char table[3][3];
    const int WIN_STATES[8][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6} };

    vector<double> elapsedTime;
    chrono::steady_clock::time_point start;
    chrono::steady_clock::time_point end;

    int gamesPlayed;
    int playerMoves;
    int leastMoves;
    int mostMoves;

    double latestTime;
    double quickestAndLowest[2];

    // Precondition: time must be greater than 0
    // Postcondition: time is pushed into the vector
    void setElapsedTime(double time, int moves)
    {

        checkMoves(time, moves);

        elapsedTime.push_back(time);

        if (elapsedTime.size() > 1)
            sort(elapsedTime.begin(), elapsedTime.end());

    }

    // Precondition: time must be greater than 0
    // Postcondition: moves assigned for fastest and slowest game
    void checkMoves(double time, int moves)
    {
        if (elapsedTime.size() == 0)
        {
            leastMoves = moves;
            mostMoves = moves;
        }

        if (elapsedTime.size() > 0)
        {
            if (elapsedTime.size() == 1)
            {
                if (time < elapsedTime.at(0))
                    leastMoves = moves;
                else if (time > elapsedTime.at(0))
                    mostMoves = moves;
            }

            if (time < elapsedTime.at(0))
                leastMoves = moves;

            if (time > elapsedTime.at(elapsedTime.size() - 1))
                mostMoves = moves;
        }
    }

    // Precondition: time must be greater than 0
    // Postcondition: latestTime is set to time
    void setLatestElapsedTime(double time)
    {
        if (time < 0)
            latestTime = 0;
        else
            latestTime = time;
    }

public:

    TicTacToe()
    {
        player = 'X';
        computer = 'O';
        generateTable();
    }

    // Precondition: none;
    // Postcondition: the table is initialized with blank spaces
    void generateTable()
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                table[i][j] = ' ';
    }

    // Precondition: none
    // Postcondition: returns true if a player has one the game
    bool isGameWon()
    {
        for (int index = 0; index < 8; index++)
        {
            bool win = true;
            int firstRow = WIN_STATES[index][0] / 3;
            int firstColumn = WIN_STATES[index][0] % 3;

            for (int i = 0; i < 3; i++)
            {
                int row = WIN_STATES[index][i] / 3;
                int column = WIN_STATES[index][i] % 3;

                if (table[firstRow][firstColumn] == ' ' || table[firstRow][firstColumn] != table[row][column])
                {
                    win = false;
                }
            }
            if (win)
                return true;
        }
        return false;
    }

    // Precondition: NA
    // Postcondition: returns true if the board is full / game is tied
    bool isTied()
    {
        if (isGameWon())
            return false;
        for (int index = 0; index < 3; index++)
            for (int i = 0; i < 3; i++)
                if (table[index][i] == ' ')
                    return false;

        return true;
    }

    // Precondition: NA
    // Postcondition: The player moves in a slot between 1 - 9
    void playerMove()
    {
        while (true)
        {
            int slot = inputInteger("\t\tEnter an empty slot (1 - 9): ", 1, 9);

            int row = (slot - 1) / 3;
            int column = (slot - 1) % 3;
            if (slot >= 1 && slot <= 9 && table[row][column] == ' ')
            {
                table[row][column] = player;
                break;
            }
        }

        playerMoves++;
    }

    // Precondition: NA
    // Postcondition: AI makes a move
    void AIMove()
    {
        Move move = minimax();
        table[move.row][move.column] = computer;
    }

    // Precondition: NA
    // Precondition: Best move is found for AI and is then returned
    Move minimax(bool maximizing_player = true)
    {
        Move move;
        if (isGameWon()) {
            if (maximizing_player) {
                move.score = -1;
            }
            else {
                move.score = 1;
            }
            return move;
        }
        else if (isTied()) {
            move.score = 0;
            return move;
        }

        move.score = maximizing_player ? -2 : 2;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (table[i][j] == ' ')
                {
                    table[i][j] = maximizing_player ? computer : player;
                    Move currentMove = minimax(!maximizing_player);
                    if (maximizing_player) {
                        if (currentMove.score > move.score)
                        {
                            move.score = currentMove.score;
                            move.row = i;
                            move.column = j;
                        }
                    }
                    else {
                        if (currentMove.score < move.score)
                        {
                            move.score = currentMove.score;
                            move.row = i;
                            move.column = j;
                        }
                    }
                    table[i][j] = ' ';
                }
            }
        }
        return move;
    }

    // Precondition: NA
    // Postcondition: returns amount of games played
    int getGamesPlayed()
    {
        return gamesPlayed;
    }

    // Precondition: NA
    // Postcondition: Returns number of player moves during game
    int getNumberOfMoves()
    {
        return playerMoves;
    }

    // Precondition: NA
    // Postcondition: Returns the least amount of moves a player made during a game
    int getLeastMoves()
    {
        return leastMoves;
    }

    // Precondition: NA
    // Postcondition: Returns the most amount of moves a player made during a game.
    int getMostMoves()
    {
        return mostMoves;
    }

    // Precondition: Must have played at least one game
    // Postcondition: Return the amount of seconds played in the last game
    double getLatestTime()
    {
        if (getGamesPlayed() == 0)
            return 0;
        return latestTime;
    }

    // Precondition: Must have played at least one game
    // Postcondition: Return the time in seconds of the fastest game played
    double getQuickestTime()
    {
        if (elapsedTime.size() == 0)
            return 0;

        return elapsedTime.at(0);
    }

    // Precondition: Must have played at least one game
    // Postcondition: Return the time in seconds of the slowest game played
    double getSlowestTime()
    {
        if (elapsedTime.size() == 0)
            return 0;

        return elapsedTime.at(elapsedTime.size() - 1);
    }

    // Precondition: Must have played at least one game to get the true average
    // Postcondition: the average amount of time taken in seconds is returned 
    double getAverageTime()
    {
        if (elapsedTime.size() == 0)
            return 0;

        double average = 0;
        for (int index = 0; index < elapsedTime.size(); index++)
            average += elapsedTime.at(index);

        return average / elapsedTime.size();
    }

    // Precondition: NA
    // Postcondition: TicTacToe game is played with an unbeatable AI
    void playGame()
    {
        generateTable();
        playerMoves = 0;

        start = chrono::steady_clock::now();
        double temp;
        displayTable();

        while (true)
        {
            cout << "\tHUMAN moves...\n" << endl;
            playerMove();
            displayTable();
            if (isGameWon())
            {
                cout << "\tPlayer wins!... The code is broken!" << endl;
                end = chrono::steady_clock::now();

                temp = double(chrono::duration_cast <chrono::seconds> (end - start).count());
                setLatestElapsedTime(temp);
                setElapsedTime(temp, playerMoves);
                gamesPlayed++;
                return;
            }
            else if (isTied())
            {
                cout << "\tIt's a Tie!" << endl;
                end = chrono::steady_clock::now();
                temp = double(chrono::duration_cast <chrono::seconds> (end - start).count());
                setLatestElapsedTime(temp);
                setElapsedTime(temp, playerMoves);
                gamesPlayed++;
                return;
            }

            cout << endl;
            cout << "\tAI Moves..." << endl;
            AIMove();
            displayTable();

            if (isGameWon())
            {
                cout << "\tComputer wins!... The code is broken!" << endl;
                end = chrono::steady_clock::now();
                temp = double(chrono::duration_cast <chrono::seconds> (end - start).count());
                setLatestElapsedTime(temp);
                setElapsedTime(temp, playerMoves);
                gamesPlayed++;
                return;
            }
            else if (isTied()) {
                cout << "\tIt's a Tie!" << endl;
                end = chrono::steady_clock::now();
                temp = double(chrono::duration_cast <chrono::seconds> (end - start).count());
                setLatestElapsedTime(temp);
                setElapsedTime(temp, playerMoves);
                gamesPlayed++;
                return;
            }
        }
    }

    // Precondition: NA
    // Postcondition: The Tic-Tac-Toe table is displayed
    void displayTable()
    {
        cout << endl;
        cout << "\t\tTic-Tac-Toe" << endl;
        for (int index = 0; index < 3; index++)
        {

            if (index)
            {
                cout << "\t\t-----------\n";
            }

            cout << "\t\t";

            for (int i = 0; i < 3; i++)
            {

                if (i)
                {
                    cout << "|";
                }
                cout << ' ';
                if (table[index][i] == ' ')
                {
                    cout << 3 * index + i + 1;
                }
                else
                {
                    cout << table[index][i];
                }
                cout << ' ';

            }
            cout << '\n';
        }
        cout << '\n';
    }
};

#endif