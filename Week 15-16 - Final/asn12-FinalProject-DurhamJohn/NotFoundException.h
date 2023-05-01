#pragma once
#ifndef NOT_FOUND_EXEPTION_H
#define NOT_FOUND_EXEPTION_H
#include <stdexcept>
#include <string>

using namespace std;

class NotFoundException : public logic_error
{
public:
	NotFoundException(const string& message = "") :
		logic_error("Not Found Exception: " + message) {};

};
#endif