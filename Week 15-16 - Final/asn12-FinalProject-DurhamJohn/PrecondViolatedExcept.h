#pragma once
#ifndef PRECOND_VIOLATED_EXCEPT_H
#define PRECOND_VIOLATED_EXCEPT_H
#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolationExcept : public logic_error
{
public:
	PrecondViolationExcept(const string& message = "") :
		logic_error("Precondition Violation Exception: " + message) {};

};
#endif