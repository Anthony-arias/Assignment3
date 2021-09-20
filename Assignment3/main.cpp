// main.cpp

// Team: Anthony, An, Van, Vincent, Nhan
// Chapter 3: 
// 

#include <iostream>
#include <string>
#include "input.h"

void mainMenu(void);
void programOne(void);
void programTwo(void);
void programThree(void);
void displayMainMenu(void);

using namespace std;

int main(void)
{
    mainMenu();
    return EXIT_SUCCESS;
}

//PreCondition: NA
//PostCondition: redirects user to different menus based on their choice
void mainMenu(void)
{
    do
    {
        clearScreen();

        displayMainMenu();

        int userInput = inputInteger("\t\tOption: ");
        switch (userInput)
        {
        case 0: clearScreen(); return;
        case 1: clearScreen(); programOne(); pause("\n\t\tPress enter to continue..."); break;
        case 2: clearScreen(); programTwo(); pause("\n\t\tPress enter to continue..."); break;
        case 3: clearScreen(); programThree(); pause("\n\t\tPress enter to continue..."); break;
        default: cout << "\t\tERROR-3A: Invalid input. Must be from 0..2." << endl;
            pause("\n\t\tPress enter to continue...");
        }
    } while (true);
}

//PreCondition: 
//PostCondition:
void programOne(void)
{

    do
    {
        clearScreen();
        /*display here*/

        int option = inputInteger("\t\tOption: ");
        switch (option)
        {
        case '0': return;
        /*stuff here*/
        default: cout << "\t\tERROR-1A: Invalid input. Must be" << endl;
            pause("\n\t\tPress enter to continue...");
        }
        
    } while (true);
}

//PreCondition: 
//PostCondition:
void programTwo(void)
{
    do
    {
        clearScreen();
        /*display here*/

        int option = inputInteger("\t\tOption: ");
        switch (option)
        {
        case '0': return;
            /*stuff here*/
        default: cout << "\t\tERROR-1A: Invalid input. Must be" << endl;
            pause("\n\t\tPress enter to continue...");
        }

    } while (true);
}
//PreCondition: 
//PostCondition:
void programThree(void)
{
    do
    {
        clearScreen();
        /*display here*/

        int option = inputInteger("\t\tOption: ");
        switch (option)
        {
        case '0': return;
            /*stuff here*/
        default: cout << "\t\tERROR-1A: Invalid input. Must be" << endl;
            pause("\n\t\tPress enter to continue...");
        }

    } while (true);
}

//PreCondition: NA
//PostCondition: displays main menu options
void displayMainMenu(void)
{
    cout << "\n\tCMPR131 Chapter 3 - Games Applications using Container by Prof Q" << endl;
    cout << "\t" + string(85, char(205)) << endl;
    cout << "\t\t1> Tic-Tac-Toe" << endl;
    cout << "\t\t2> Tower of Hanoi" << endl;
    cout << "\t\t3> n-Queens" << endl;
    cout << "\t" + string(85, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(85, char(205)) << endl;
}