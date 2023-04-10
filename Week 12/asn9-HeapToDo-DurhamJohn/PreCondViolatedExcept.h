#pragma once
#ifndef PRECONDVIOLATEDEXCEPT_H
#define PRECONDVIOLATEDEXCEPT_H
#include <stdexcept>


class PrecondViolatedExcept : public std::logic_error
{
public:
	PrecondViolatedExcept(const std::string& message = "");
};

#endif



PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message)
	: std::logic_error("Precondition Violated Exception: " + message)
{
}