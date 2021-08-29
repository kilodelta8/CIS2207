/** @author John Durham */
/** @date 08/23/2021 */
/* CIS 2207.501
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
	bool game = true;
	int numGuesses, maxRange;
	std::string strInput;
	std::vector<int> guesses;

	do {
		std::cout << "Enter the number of guesses you wish to provide at a time: " << std::endl;
		std::cin >> numGuesses;
		std::cout << "Enter the maximum range of numbers to geuss from 1 to (x): " << std::endl;
		std::cin >> maxRange;

		Game newGame(numGuesses, maxRange);
		bool nestedGame = true;
		while (nestedGame) 
		{
			std::cout << "Enter your guess(es): " << std::endl;
			getline(std::cin, strInput);
			for (int i = 0; i < strInput.length(); i++)
			{
				std::cout << strInput.at(i) << std::endl;
				if (isdigit(i))
				{
					guesses.push_back(i);
				}
				else if (!isspace(i))
				{
					continue;
				}
			}

			int matches = newGame.compare(guesses);
			char input;
			std::cout << "matches: " << matches << std::endl;
			if (matches == newGame.getNumOfGuesses())
			{
				std::cout << "Congrats! All " << newGame.getNumOfGuesses() << " of your geusses were correct!" << std::endl;
				std::cout << "Wanna play again?: " << std::endl;
				std::cin >> input;
				if (input == 'y' || input == 'Y')
				{
					//setup new game
					nestedGame = false;
					guesses.clear();
				}
				else
				{
					//end game
					nestedGame = false;
					game = false;
				}
			}
			else
			{
				std::cout << "Sorry, only " << newGame.getNumOfGuesses() << " of your geusses were correct! Try again." << std::endl;
			}
			guesses.clear();
			
		} 

	} while (game);

	std::cout << "Goodbye!" << std::endl;

	return 0;
}


