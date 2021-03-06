// aGameOf21.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "Die.h"
using namespace std;

void playGame(const int ds1, const int ds2);
void selectWinner(int p1, int pC);

int main()
{
	const int DIE1_SIDES = 6;
	const int DIE2_SIDES = 12;

	char enterGame;

	cout << "Would you like to play a game of 21 ? (Y/N)" << endl;
	cin >> enterGame;

	if (enterGame == 'y' || enterGame == 'Y')
	{
		playGame(DIE1_SIDES, DIE2_SIDES);
	}

	else
	{
		cout << "Goodbye" << endl;
	}

	return 0;
}


void playGame(const int ds1, const int ds2)
{
	int player1Score = 0;
	int playerCScore = 0;

	char userChoice;

	do
	{
		cout << "Rolling..." << endl;

		Die d1(ds1);
		Die d2(ds2);
		d1.roll();
		d2.roll();

		player1Score += d1.getValue() + d2.getValue();

		cout << "Your rolls: " << d1.getValue() << " " << d2.getValue() << endl;
		cout << "Your score: " << player1Score << "\n" << endl;
		
		d1.roll();
		d2.roll();

		playerCScore += d1.getValue() + d2.getValue();

		userChoice = 'N';
		
		//Decisions 

		if (player1Score < 21 && playerCScore < 21)
		{
			cout << "No one has won..." << endl;
			cout << "Would you like to roll again? (Y/N) " << endl;
			cin >> userChoice;

			if (userChoice == 'n' || userChoice == 'N')
			{
				selectWinner(player1Score, playerCScore);
			}

			else
			{
				cout << "Rolling again" << endl;
			}
		}

		else
		{
			selectWinner(player1Score, playerCScore);	
		}

	} while (userChoice == 'y' || userChoice == 'Y');

}

void selectWinner(int p1, int pC)
{
	// Draws

	cout << "Your score: " << p1 << endl;
	cout << "Computer score: " << pC << endl;

	if (p1 > 21 && pC > 21 && p1 == pC)
	{
		cout << "It's a draw..." << endl;
	}

	else if (p1 < 21 && pC < 21 && p1 == pC)
	{
		cout << "It's a draw..." << endl;
	}

	// P1 Winners

	else if (p1 == 21 && pC != 21)
	{
		cout << "Player 1 (you) wins!" << endl;
	}

	else if (p1 < 21 && pC < p1)
	{
		cout << "Player 1 (you) wins!" << endl;
	}

	else if (p1 < 21 && pC > 21)
	{
		cout << "Player 1 (you) wins!" << endl;
	}

	//PC Winners

	else if (pC == 21 && p1 != 21)
	{
		cout << "The computer wins!" << endl;
	}

	else if (pC < 21 && p1 < pC)
	{
		cout << "The computer wins!" << endl;
	}

	else if (pC < 21 && p1 > 21)
	{
		cout << "The computer wins!" << endl;
	}
}
