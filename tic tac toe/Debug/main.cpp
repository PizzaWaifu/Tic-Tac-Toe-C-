#include <iostream>
#include <windows.h>
using namespace std;

char square[9] = { '0','1','2','3','4','5','6','7','8' };
int cock = 0;
int i;
void grid()													//prints the 3x3 grid
{
	for (i = 0; i <= square[8]; i++)						//repeats eight times, once for each square
	{
		if (i == 3)											//once the third cycle has been reached, a new line is drawn
		{
			cout << "\n";
		}
		if (i == 6)											//once the sixth cycle has been reached, a new line is drawn
		{
			cout << "\n";
		}
		if (i == 9)
			break;
		else if (square[i] == 20)							//20 stands for every number that shall be printed as X, 20 is merely an arbitrairy number in this case
			cout << "X ";
		else if (square[i] == 21)
			cout << "O ";
		else
			cout << square[i] << " ";						//if it is neither an X nor a Y field, the number corresponding for the field shall be printed with a space attachted to it
	}
}

void gam()
{
lamel:
	cout << endl << "\nP1 input a square and press enter" << "\n" << "\n";
	cin >> cock;
	if (square[cock] == 20)									//checks if the inout square is already taken by P1
	{
		cout << "\nselect a square that is not taken" << "\n" << "\n";
		goto lamel;
		grid();
	}
	else if (square[cock] == 21)							//checks if the inout square is already taken by P2
	{
		cout << "\nselect a square that is not taken" << "\n" << "\n";
		grid();
		goto lamel;
	}
	else if (!cin)											//if an inout is given in the wrong format, an eroor will be thrown
	{
		cout << "\nwrong input" << "\n" << "\n";
		cin.clear();
		cin.ignore();
		grid();
		goto lamel;
	}
	else if (cock > 8)										//checks if input is above the available sqaure number
	{
		cout << "\nselect a valid square" << "\n" << "\n";
		grid();
		goto lamel;
	}
	else if (cock < 0)										//checks if input is below the available sqaure number
	{
		cout << "\nwrong input" << "\n" << "\n";
		cin.clear();
		cin.ignore();
		grid();
		goto lamel;
	}
	else													//if there are no errors the sqaure will be allocated to player 1
	{
		square[cock] = 20;
		cout << "\n";
		grid();
	}
}

void game()													//same thing but for player 2
{
lecock:
	cout << endl << "\nP2 input a square and press enter" << "\n" << "\n";
	cin >> cock;
	if (square[cock] == 20)
	{
		cout << "\nselect a square that is not taken" << "\n" << "\n";
		grid();
		goto lecock;
	}
	else if (square[cock] == 21)
	{
		cout << "\nselect a square that is not taken" << "\n" << "\n";
		grid();
		goto lecock;
	}
	else if (!cin)
	{
		cout << "\nwrong input" << "\n" << "\n";
		cin.clear();
		cin.ignore();
		grid();
		goto lecock;
	}
	else if (cock > 8)
	{
		cout << "\nselect a valid square" << "\n" << "\n";
		grid();
		goto lecock;
	}
	else if (cock < 0)
	{
		cout << "\nwrong input" << "\n" << "\n";
		cin.clear();
		cin.ignore();
		grid();
		goto lecock;
	}
	else
	{
		square[cock] = 21;
		cout << "\n";
		grid();
	}
}

int winflag()																			//checks if game shall be ended
{
	if (square[0] == square[1] && square[1] == square[2])								//should three consequetive(:() squares allign the game shall be ended
	{
		cout << "\n\ncockgratulations\n\n";
		return 0;
	}
	else if (square[3] == square[4] && square[4] == square[5])
	{
		cout << "\n\ncockgratulations\n\n";
		return 0;
	}
	else if (square[6] == square[7] && square[7] == square[8])
	{
		cout << "\n\ncockgratulations\n\n";
		return 0;
	}
	else if (square[0] == square[3] && square[3] == square[6])
	{
		cout << "\n\ncockgratulations\n\n";
		return 0;
	}
	else if (square[1] == square[4] && square[4] == square[7])
	{
		cout << "\n\ncockgratulations\n\n";
		return 0;
	}
	else if (square[2] == square[5] && square[5] == square[8])
	{
		cout << "\n\ncockgratulations\n\n";
		return 0;
	}
	else if (square[0] == square[4] && square[4] == square[8])
	{
		cout << "\n\ncockgratulations\n\n";
		return 0;
	}
	else if (square[2] == square[4] && square[4] == square[6])
	{
		cout << "\n\ncockgratulations\n\n";
		return 0;
	}
	else if (square[0] == square[3] && square[3] == square[6])
	{
		cout << "\n\ncockgratulations\n\n";
		return 0;
	}					
	else
	{
		return 1;
	}
}

int main()								//ask both players to complate for plays plus an extra one for P1, should the game not end before hand
{	
start:
	grid();
	for (int g = 0; g < 4; g++)
	{	
	gam();
	if (winflag() == 0)
	{
		goto lamar;
	}
	game();
	if (winflag() == 0)
	{
		goto lamar;
	}
	}
	gam();
	if (winflag() == 0)
	{
		goto lamar;
	}
	else
	{
		cout << "\nmagendarmentzuendung";
	}
lamar:
	string malock;
	cout << "play again? [y/n]:\n\n";
	cin >> malock;
	if (malock == "y")
	{
		int cock = 0;
		square[0] = '0';
		square[1] = '1';
		square[2] = '2';
		square[3] = '3';
		square[4] = '4';
		square[5] = '5';
		square[6] = '6';
		square[7] = '7';
		square[8] = '8';
		int g = 0;
		cout << "\n";
		goto start;
	}
	else if (malock == "n")
	{
		exit;
	}
	else
	{
		cout << "\noh okay screw you then";
		Sleep(2000);
		exit;
	}

}