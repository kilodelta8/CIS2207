#pragma once
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