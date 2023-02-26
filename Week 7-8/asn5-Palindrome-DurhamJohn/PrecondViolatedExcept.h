/* @author  John Durham
*  asn4-Palindrome
*  23.SP.CIS.2207.501 Data Structures & Algorithms
*  @date    02/25/2023
*  @version 0.0.1
*  @file    PrecondViolatedExcept.h
* -------------------------------------------------------------------------------------------------------------
* You are asked to complete Programming Problem 3 on page 413 on your textbook. This program is meant to apply what
  you have learned in this topic. Implement the palindrome-recognition algorithm described in Section 13.2.2 on page 398.
  Note that the algorithm uses both a Stack and a Queue, both of which you are expected to implement for this assignment.
  StackInterface.h in Listing 6-1 on p. 197.
  QueueInterface.h in Listing 13-1 on p. 396.
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

