/* @author  John Durham
*  asn4-Palindrome
*  23.SP.CIS.2207.501 Data Structures & Algorithms
*  @date    02/25/2023
*  @version 0.0.1
*  @file    PrecondViolatedExcept.h
* -------------------------------------------------------------------------------------------------------------
* This code defines an exception class called PrecondViolatedExcept, which is derived from the std::logic_error class. 
  The exception is thrown when a precondition of a function is violated.
  The PrecondViolatedExcept class has a constructor that takes a string message as an argument, which is concatenated 
  with the prefix "Precondition Violated Exception: " and passed to the constructor of std::logic_error class.
*/
#pragma once
#ifndef PRECOND_VIOLATED_EXCEPT_H
#define PRECOND_VIOLATED_EXCEPT_H

#include <stdexcept>
#include <string>

class PrecondViolatedExcept : public std::logic_error
{
public:
	PrecondViolatedExcept(const std::string& message = "");
};

PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message)
	: std::logic_error("Precondition Violated Exception: " + message) {}

#endif

