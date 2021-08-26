/*
* John Durham
* CIS 2207.501
* 08/23/2021
* Design and implement an ADT for a one-person guessing game that chooses n random integers in the range of 1 to m and asks the user to guess them.  The same integer might be chosen more than once.  For example, the game might choose the following four integers that range from 1 to 10: 4, 6, 1, 6.
* The following interactions could occur between the user and the game, after the user has specified the integers m and n:
*   Enter the Number of Integers (n): 4
*   Enter the Number of Each Integers from 1 to (m): 10
*   Enter your guesses for the 4 integers in the range from 1 to 10 that have been selected: 1 2 3 4
*   2 of your guesses are correct.  Guess again.
*   Enter your guesses for the 4 integers in the range from 1 to 10 that have been selected: 2 4 6 8
*   2 of your guesses are correct.  Guess again.
*   Enter your guesses for the 4 integers in the range from 1 to 10 that have been selected: 1 4 6 6
*   You are correct! Play again? No
*/
#include <iostream>
#include <vector>
#include <string>
#include "Game.h"

int main() {
	//vars and decs
	bool play = true;
	Game currentGame;
	int numOfGuesses, rangeOfInts;


	//run
	do {
		bool inGamePlay = true;
		std::string gameGuesses;
		int totalCorrect = 0;
		char playAgain;
		std::cout << "Enter the number of Integers (n): " << std::endl;
		std::cin >> numOfGuesses;
		std::cout << "Enter the range of Integers from 1 to (m): " << std::endl;
		std::cin >> rangeOfInts;

		currentGame.setGuesses(numOfGuesses);
		currentGame.setMaxRange(rangeOfInts);
		currentGame.setUserList();

		while (inGamePlay)
		{
			std::cout << "Enter your guesses for the " <<
				currentGame.getNumOfInts() <<
				" integers in the range from 1 to " <<
				currentGame.getMaxRange() <<
				" that have been selected: " << std::endl;
			std::getline(std::cin, gameGuesses);
			currentGame.parseInput(gameGuesses);
			totalCorrect = currentGame.compareGeussesToList();

			if (totalCorrect == currentGame.getNumOfInts())
			{
				std::cout << "You are correct!  Play again?: " << std::endl;
				std::cin >> playAgain;
				if (playAgain == 'y' || playAgain == 'Y')
				{
					currentGame.clearAll();
					inGamePlay = false;
					break;
				}
				else {
					inGamePlay = false;
					play = false;
				}
			}
		}


	} while (play);

	std::cout << "Good-Bye!" << std::endl;

	return 0;
}