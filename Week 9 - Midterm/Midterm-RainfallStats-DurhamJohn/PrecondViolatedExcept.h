#pragma once
#ifndef PRECONDVIOLATEDEXCEPT_H
#define PRECONDVIOLATEDEXCEPT_H
#include <stdexcept>


class PrecondViolatedExcept : public std::logic_error
{
public:
    PrecondViolatedExcept(const std::string& message = "");
};


#endif // !PRECONDVIOLATEDEXCEPT_H

