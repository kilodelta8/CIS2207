#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Game.h"

//proto
void parseUserInput(std::vector<int>& vec, const std::string& str);

int main() {

	Game gameOne;
	Game gameTwo(1, 10);
	int input;
	std::vector<int> guess;
	std::string guesses;
	

	std::cout << "Enter the number of guesses: " << std::endl;
	std::cin >> input;
	gameOne.setNumberOfGuesses(input);
	std::cout << "Enter the range: " << std::endl;
	std::cin >> input;
	gameOne.setMaxRangeOfList(input);

	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "gameOne Object" << std::endl;
	std::cout << "Number of guesses: " << gameOne.getNumOfGuesses() << std::endl
		<< "Range of guesses:  " << gameOne.getMaxRangeOfList() << std::endl
		<< "Winning numbers:   ";
	std::vector<int> winningNums = gameOne.getWinningNums();
	gameOne.printWinningNumbers();
	std::cout << std::endl;
	std::cin.ignore();
	std::cout << "Enter your " << gameOne.getNumOfGuesses() << " guesses: ";
	getline(std::cin, guesses);
	parseUserInput(guess, guesses);
	std::cout << "Guess vector from input: ";
	for (int i = 0; i < guess.size(); i++)
	{
		std::cout << " " << guess.at(i);
	}
	std::cout << std::endl;
	int matches = gameOne.compare(guess);
	std::cout << "Matches: " << matches;

	guesses = "";
	guess.clear();
	winningNums.clear();

	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cin.clear();
	std::cout << "gameTwo Object" << std::endl;
	std::cout << "Number of guesses: " << gameTwo.getNumOfGuesses() << std::endl
		<< "Range of guesses:  " << gameTwo.getMaxRangeOfList() << std::endl
		<< "Winning numbers:   ";
	winningNums = gameTwo.getWinningNums();
	gameTwo.printWinningNumbers();
	std::cout << std::endl;
	//std::cin.ignore();
	std::cout << "Enter your " << gameTwo.getNumOfGuesses() << " guesses: ";
	getline(std::cin, guesses);
	parseUserInput(guess, guesses);
	std::cout << "Guess vector from input: ";
	for (int i = 0; i < guess.size(); i++)
	{
		std::cout << " " << guess.at(i);
	}
	std::cout << std::endl;
	matches = gameTwo.compare(guess);
	std::cout << "Matches: " << matches;

	guesses = "";
	guess.clear();
	winningNums.clear();

	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	return 0;
}





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
	/*
	std::stringstream ss;
	int found;
	while (ss.good()) {
		ss >> found;
		if (found)
		{
			std::cout << found << std::endl;
			vec.push_back(found);
		}
	}*/
}