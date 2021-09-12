/** @file Game.cpp implementation file */
/** @author John Durham */
/** @date 08/23/2021 */
/** @version 0.0.4 */
/** CIS 2207.501 */
/* Design and implement an ADT for a one-person guessing game that chooses n random integers in the range of 1 to m and asks the user to guess them.  The same integer might be chosen more than once.  For example, the game might choose the following four integers that range from 1 to 10: 4, 6, 1, 6.
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
#include <algorithm>
#include <cstdlib>
#include <string>
#include "Game.h"


//Constructors
Game::Game() {}
Game::Game(int numGuesses, int maxRange)
{
	numberOfGuesses = numGuesses;
	rangeMaxOfList = maxRange;
	generateWinningNumbers();
}



//setters
/** Sets the number of guesses for the Game object
* @param num A simple integer entred by the user to represent the number of guesses to guess at one time.
*/
void Game::setNumberOfGuesses(int num) { numberOfGuesses = num; }


/** Sets the maximum range of number to guess from for the Game object
* @param num A simple integer entred by the user to represent the maximum range of numbers.
* @pre This function attempts to idiot proof the data by padding or selecting for the user
* in the event they fail to enter a proper number.
*/
void Game::setMaxRangeOfList(int num) { 
	if (rangeMaxOfList < numberOfGuesses)
	{
		rangeMaxOfList += num; 
	}
	else if (rangeMaxOfList > numberOfGuesses)
	{
		rangeMaxOfList = num;
	}
	generateWinningNumbers(); 
}



//getters
/** @post Returns the number of guesses from the Game object as a constant 
*/
int Game::getNumOfGuesses() const { return numberOfGuesses; }


/** @post Returns the maximum range of numbers to guess from, from the Game object, as a constant 
*/
int Game::getMaxRangeOfList() const { return rangeMaxOfList; }


/** @post Returns the generated winning numbers as a std::vector from the Game object 
*/
std::vector<int> Game::getWinningNums() { return winningNums; }


/** Needs to print the winning numbers to the console output 
*/
void Game::printWinningNumbers()
{
	for (int i = 0; i < winningNums.size(); i++)
	{
		std::cout << winningNums.at(i) << "  ";
	}
}



//Others
/** Returns the number of matchesmade after comparing user guesses to winning numbers that were generated 
* @param guesses A standard vector that holds user input guesses to compare against Game object winningNums
* @post Returns total number of matches of guesses to winning numbers
*/
int Game::compare(std::vector<int>& guesses) {
	int counter = 0;
	for (int i = 0; i < winningNums.size(); i++)
	{
		for (int j = 0; j < guesses.size(); j++)
		{
			if (guesses.at(j) == winningNums.at(i))
			{
				counter++;
			}
		}
	}
	return counter;
}


/** Generates the winning numbers for the Game object 
* @post Generates random number(s) based off of the number of guesses and stores them in
* a vector for the Game object
*/
void Game::generateWinningNumbers() {
	for (int i = 0; i < numberOfGuesses; i++) {
		int num = 1 + (rand() % static_cast<int>(rangeMaxOfList));
		if (num > 0 && num <= rangeMaxOfList) {
			winningNums.push_back(num);
		}
	}
}


/** Resets the Game object to all zero's versus dynamically deleting the object 
* @post resets all of the Game ADT's data to zero's and clears vector(s) so that the game 
* may be played again with new values entered (versus dynamically instantiating and deleteing
* a new object)
*/
void Game::clearAll() {
	numberOfGuesses = 0;
	rangeMaxOfList = 0;
	winningNums.clear();
}
