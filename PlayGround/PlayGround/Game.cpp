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
void Game::setNumberOfGuesses(int num) { numberOfGuesses = num; }
void Game::setMaxRangeOfList(int num) { rangeMaxOfList = num; generateWinningNumbers(); }

//getters
int Game::getNumOfGuesses() const { return numberOfGuesses; }
int Game::getMaxRangeOfList() const { return rangeMaxOfList; }
std::vector<int> Game::getWinningNums() { return winningNums; }
void Game::printWinningNumbers()
{
	for (int i = 0; i < winningNums.size(); i++)
	{
		std::cout << winningNums.at(i) << " - ";
	}
}



//Others
int Game::compare(std::vector<int>& guesses) {
	int counter = 0;
	for (int i = 0; i < winningNums.size(); i++)
	{
		for (int j = 0; j < guesses.size(); j++)
		{
			//std::cout << guesses.at(j) << " - " << winningNums.at(i) << std::endl;
			if (guesses.at(j) == winningNums.at(i))
			{
				counter++;
			}
		}
	}
	return counter;
}

void Game::generateWinningNumbers() {
	for (int i = 0; i < numberOfGuesses; i++) {
		int num = 1 + (rand() % static_cast<int>(rangeMaxOfList));
		if (num > 0 && num <= rangeMaxOfList) {
			winningNums.push_back(num);
		}
	}
}


void Game::clearAll() {
	numberOfGuesses = 0;
	rangeMaxOfList = 0;
	winningNums.clear();
}

//destructor
Game::~Game() { std::cout << "Goodbye!" << std::endl; }