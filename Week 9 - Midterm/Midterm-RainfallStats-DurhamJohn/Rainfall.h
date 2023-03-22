#pragma once
#ifndef RAINFALL_H
#define RAINFALL_H

#include <string>

class Rainfall
{
private:
	std::string month;
	double rainfall;

public:
	Rainfall();
	Rainfall(std::string m);
	Rainfall(std::string m, double r);

	void setMonth(std::string& m);
	void setRainfall(double r);
	std::string getMonth();
	double getRainfall();
};



//
Rainfall::Rainfall() {}



//
Rainfall::Rainfall(std::string m) : month(m) {}



//
Rainfall::Rainfall(std::string m, double r) : month(m), rainfall(r) {}



//
void Rainfall::setMonth(std::string& m)
{
	month = m;
}



//
void Rainfall::setRainfall(double r)
{
	rainfall = r;
}



//
std::string Rainfall::getMonth()
{
	return month;
}



//
double Rainfall::getRainfall()
{
	return rainfall;
}

#endif // !RAINFALL_H

