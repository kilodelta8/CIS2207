#include "ClassOne.h"
#include <iostream>

//setters
void setName(const std::string n)
{
	name = n;
}

void setAge(const int a)
{
	age = a;
}

void setWeight(const double w)
{
	weight = w;
}

//getters
std::string getName() const
{
	return name;
}

int getAge() const
{
	return age;
}

double getWeight() const
{
	return weight;
}

//others
void speak()
{
	std::cout << "HI! My name is " << name << std::endl;
}
/*
void printer() override
{

}*/