/** @file Game.cpp */
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
void Game::setNumberOfGuesses(int num) {numberOfGuesses = num;}
void Game::setMaxRangeOfList(int num) {rangeMaxOfList = num;}

//getters
int Game::getNumOfGuesses() const {return numberOfGuesses;}
int Game::getMaxRangeOfList() const {return rangeMaxOfList;}
std::vector<int> Game::getWinningNums() const {return this->winningNums;}



//Others
int Game::compare(std::vector<int>& guesses) {
	int guessesSize = guesses.size();
	int winningNUmsSize = winningNums.size();
	int counter = 0;
	for (int i = 0; i < guesses.size(); i++) {      //for each guessing number
		std::vector<int>::iterator it = std::find(winningNums.begin(), winningNums.end(), guesses.at(i));
		if (it - winningNums.begin() > 0)
		{
			counter++;
		}
		
		std::cout << "compare() - counter: " << counter << std::endl;
	}
	return counter;
}

void Game::generateWinningNumbers() {
	for (int i = 0; i < numberOfGuesses; i++) {
		int num = 1 + (rand() % static_cast<int>(rangeMaxOfList));
		if (num > 0 && num <= rangeMaxOfList) {
			std::cout << "generateWinningNumbers:  " << num << std::endl; //TODO - delete this line
			winningNums.push_back(num);
		}
	}
}


void Game::clearAll() {
	numberOfGuesses = 0;
	rangeMaxOfList = 0;
	winningNums.clear();
}