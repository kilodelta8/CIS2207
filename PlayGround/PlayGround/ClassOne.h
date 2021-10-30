#pragma once
#include "Interface.h"
#include <string>
#ifndef CLASS_ONE_H
#define CLASS_ONE_H

class ClassOne
{
private:
	std::string name;
	int age;
	double weight;

public:
	//setters
	void setName(const std::string n);
	void setAge(const int a);
	void setWeight(const double w);

	//getters
	std::string getName() const;
	int getAge() const;
	double getWeight() const;

	//others
	void speak();
};

//setters
void ClassOne::setName(const std::string n)
{
	this->name = n;
}

void ClassOne::setAge(const int a)
{
	this->age = a;
}

void ClassOne::setWeight(const double w)
{
	this->weight = w;
}

//getters
std::string ClassOne::getName() const
{
	return this->name;
}

int ClassOne::getAge() const
{
	return this->age;
}

double ClassOne::getWeight() const
{
	return this->weight;
}

//others
void speak()
{
	std::cout << "HI! My name is BLANK" << std::endl;
}
#endif // !CLASS_ONE_H