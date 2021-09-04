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
#include <sstream>
#include "Game.h"

//proto
void parseUserInput(std::vector<int>& vec, const std::string& str);


int main() {
	//vars and decs
	bool game = true;
	int numGuesses, maxRange;
	std::string strInput;
	std::vector<int> guesses;

	//pregame setup
	do {
		std::cout << "Enter the number of guesses you wish to provide at a time: " << std::endl;
		std::cin >> numGuesses;
		std::cout << "Enter the maximum range of numbers to geuss from 1 to (x): " << std::endl;
		std::cin >> maxRange;


		//prep and start the game
		Game newGame(numGuesses, maxRange);
		bool nestedGame = true;
		std::cin.ignore();  //clean the buffer
		do 
		{
			//prompt for guesses, parse the input into vector
			std::cout << "Enter your guess(es): " << std::endl;
			getline(std::cin, strInput);
			parseUserInput(guesses, strInput);

			//check for matches
			int matches = newGame.compare(guesses);
			char input;
			//std::cout << "matches: " << matches << std::endl;
			//if all the geusses were correct prompt to play again
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
					newGame.clearAll();
				}
				else
				{
					//or end game
					nestedGame = false;
					game = false;
				}
			}
			else
			{
				//if not all matches were made
				std::cout << "Sorry, only " << newGame.getNumOfGuesses() << " of your geusses were correct! Try again." << std::endl; //TODO - something isnt right here
			}
			guesses.clear(); //clear the guesses vec
			
		} while (nestedGame);

	} while (game);


	return 0;
}




//FUNCTIONS
void parseUserInput(std::vector<int>& vec, const std::string& str)
{
	std::stringstream ss;
	ss << str;
	int found;
	std::string temp;

	while (std::getline(ss, temp, ' ')) {
		if (std::stringstream(temp) >> found)
		{
			//std::cout << found << std::endl;
			vec.push_back(found);
		}
	}
}