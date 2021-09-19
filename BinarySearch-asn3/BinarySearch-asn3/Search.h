#pragma once
#ifndef SEARCH_
#define SEARCH_
#include <string>

namespace Search{
/** Binary search function for integer arrays */
int binarySearch(std::string arr[], int first, int last, std::string target);

//TODO - implement overidden binarySearch() for all data types

void swap(std::string& a, std::string& b);
void bubbleSort(std::string arr[], int size);
void selectionSort(std::string arr[], int size);
}

#endif
