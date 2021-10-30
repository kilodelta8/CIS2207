#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Game.h"
#include <map>
#include "ClassOne.h"

//proto
void parseUserInput(std::vector<int>& vec, const std::string& str);
std::vector<int> twoNumSum(std::vector<int> arr, int target);

int main() {

	ClassOne* person = new ClassOne();

	person->setName("Johnny");
	person->setAge(38);
	person->setWeight(255.8);

	std::cout << "  Name: " << person->getName() << std::endl;
	std::cout << "   Age: " << person->getAge() << std::endl;
	std::cout << "Weight: " << person->getWeight() << std::endl;

	delete person;
	person = nullptr;


	/*
	std::vector<int> vec = { 5, 8, 2, 4, 7, 10, -1, 6 }; //8
	int targetSum = 10;
	std::vector<int> vec2 = {twoNumSum(vec, targetSum)};

	//std::cout << vec2.size() << std::endl;
	std::cout << "0th <> 1st" << std::endl;
	if (vec2.size() == 2)
	{
		std::cout << vec2[0] << " " << vec2[1] << std::endl;
	}
	else if (vec2.size() == 1)
	{
		std::cout << vec2[0] << std::endl;
	}
	else if ( vec2.size() == 0)
	{
		std::cout << "the vector is zero" << std::endl;
	}
	else if (vec2.size() > 2)
	{
		std::cout << "the vector is bigger than 2 at size: " << vec2.size() << std::endl;
		/*for (int i = 0; i < vec2.size(); i++)
		{
			std::cout << vec2[i] << " - ";
		}
		std::cout << std::endl;
		std::cout << "---------------------------------------------------------" << std::endl;
	}
	else
	{
		std::cout << "Strange happening Dr Durham, Strange happenings. . . ." << std::endl;
	}*/




	
	return 0;
}



std::vector<int> twoNumSum(std::vector<int> arr, int target)
{
	std::map<int, bool> nums;
	std::map<int, bool>::iterator it;
	for (int i = 0; i < arr.size(); i++)
	{
		int potentialSum = target - arr[i];
		it = nums.find(potentialSum);
		//int poss = (int)it->first;
		if (nums[it->first] == potentialSum)
		{
			std::cout << it->first << " " << it->second << std::endl;
			return std::vector<int>(potentialSum, arr[i]);
		}
		else
		{
			nums[arr[i]] = true;
		}
	}
	return std::vector<int>();
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