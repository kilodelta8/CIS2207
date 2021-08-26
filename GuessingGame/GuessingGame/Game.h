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


class Game {
private:
	int numOfInts;
	int rangeMax;
	std::vector<int> guesses;
	std::vector<int> list;
public:
	//constructor
	Game();

	//setters
	void setNumOfInts(int num);
	void setMaxRange(int num);
	void setGuesses(int numOfGuesses);
	void setUserList();

	//getters
	int getNumOfInts() const;
	int getMaxRange() const;
	std::vector<int> getGuesses() const;
	std::vector<int> getUserList() const;

	//others
	bool isInList(int num);
	int compareGeussesToList();
	void parseInput(std::string str);
	void clearAll();
};

#endif