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
#include <vector>
#include <cstdlib>
#include "Game.h"

Game::Game() {}

bool Game::setNumOfInts(int num) {
	numOfInts = num;
}

bool Game::setNumOfEachInts(int num) {
	numOfEachInts = num;
}

void Game::setGuesses(int numOfGuesses) {
	guesses.push_back(numOfGuesses);
}

void Game::setUserList(int userListMax) {
	for (int i = 0; i < userListMax; i++) {
		int num = (rand() % userListMax);
		if (isInList(num)) {
			i--;
		}
		else {
			list.push_back(num);
		}
	}
}

//getters
int Game::getNumOfInts() const {
	return numOfInts;
}

int Game::getNumOfGuesses() const {
	return numOfEachInts;
}

std::vector<int> Game::getGuesses() const {
	return guesses;
}

std::vector<int> Game::getUserList() const {
	return list;
}

//others
bool Game::isInList(int num) {
	bool flag = false;
	for (int i = 0; i < list.size(); i++) {
		if (num == list[i])
		{
			flag = true;
		}
	}
	return flag;
}

int Game::compareGeussesToList() {
	int counter = 0;
	for (int i = 0; i < guesses.size(); i++) {
		for (int j = 0; j < list.size(); j++) {
			if (guesses[i] == list[j])
			{
				counter++;
			}
		}
	}
	return counter;
}