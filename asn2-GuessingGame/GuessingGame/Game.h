#pragma once
/** @file Game.h */
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
#ifndef GAME_
#define GAME_

#include <vector>

/** @class Game
* This ADT generates a list of winning numbers within a range entered by the user
* for the user to guess against.
*/
class Game {
private:
	int numberOfGuesses;             //amount of guesses expected at a time
	int rangeMaxOfList;              //the maximum range of the list
	std::vector<int> winningNums;    //winning numbers selected from the list (or comparable)

public:
	//constructors
	Game();
	Game(int numGuesses, int maxRange);

	//setters
	/** Sets the number of guesses for the Game object */
	void setNumberOfGuesses(int num);
	/** Sets the maximum range of number to guess from for the Game object */
	void setMaxRangeOfList(int num);

	//getters
	/** Returns the number of guesses from the Game object as a constant */
	int getNumOfGuesses() const;
	/** Returns the maximum range of numbers to guess from, from the Game object, as a constant */
	int getMaxRangeOfList() const;
	/** Returs the generated winning numbers as a std::vector from the Game object */
	std::vector<int> getWinningNums();
	/** Needs to print the winning numbers to the console output */
	virtual void printWinningNumbers();

	//others
	/** Returns the number of matchesmade after comparing user guesses to winning numbers that were generated */
	int compare(std::vector<int>& guesses);
	/** Generates the winning numbers for the Game object */
	void generateWinningNumbers();
	/** Resets the Game object to all zero's versus dynamically deleting the object */
	void clearAll();

	
};

#endif