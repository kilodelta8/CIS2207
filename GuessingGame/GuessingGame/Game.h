/** @file Game.h */
#pragma once
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
#ifndef GAME_
#define GAME_

#include <vector>

/** @class */
class Game {
private:
	int numberOfGuesses;                //amount of guesses expected at a time
	int rangeMaxOfList;              //the maximum range of the list
	std::vector<int> winningNums;    //winning numbers selected from the list (or comparable)
public:
	//constructors
	Game();
	Game(int numGuesses, int maxRange);

	//setters
	void setNumberOfGuesses(int num);
	void setMaxRangeOfList(int num);

	//getters
	int getNumOfGuesses() const;
	int getMaxRangeOfList() const;
	std::vector<int> getWinningNums();
	void printWinningNumbers();

	//others
	int compare(std::vector<int>& guesses);
	void generateWinningNumbers();
	void clearAll();

	//destructor
	~Game();
};

#endif