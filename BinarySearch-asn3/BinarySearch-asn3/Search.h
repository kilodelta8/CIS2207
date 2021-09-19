/** @file Search.h header file */
/** @author John Durham */
/** @date 09/16/2021 */
/** @version 0.0.1 */
/* CIS 2207.501
* You are asked to complete Programming Problem 3 on page 94 of your textbook.
* Problem 3: Implement the binarySearch algorithm presented in this chapter for an array of string.
* This program is meant to apply what you have learned in this topic.
* Make sure to implement the binarySearch algorithm presented in this chapter for the array of strings (page 70).
* Note that the binarySearch is a recursive algorithm.
*/
#pragma once
#ifndef SEARCH_
#define SEARCH_
#include <string>

namespace Search{
/** Binary search function for integer arrays */
int binarySearch(std::string arr[], int first, int last, std::string target);
//TODO - implement overidden binarySearch() for all data types


/** used within bubble sort to swap values */
void swap(std::string& a, std::string& b);
/** bubble sort the string array */
void bubbleSort(std::string arr[], int size);
/** selection sorts the string array */
void selectionSort(std::string arr[], int size);
}

#endif
