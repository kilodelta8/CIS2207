/** @file Search.cpp implemetataion file */
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
#include "Search.h"


/** Searches through an array of strings
* @param 
* @post return the index of the target if found OR -1 indicating it wasn't found
*/
int Search::binarySearch(std::string arr[], int first, int last, std::string target)
{
	int middle;
	if (first > last)
		return -1;
	middle = (first + last) / 2;
	if (arr[middle] == target)
		return middle;
	if (arr[middle] < target)
		return binarySearch(arr, middle + 1, last, target);
	else
		return binarySearch(arr, first, middle - 1, target);
}









//======================================================================================
/** used within bubble sort to swap values */
void Search::swap(std::string& a, std::string& b)
{
	std::string temp = a;
	a = b;
	b = temp;
}

/** bubble sort the string array 
* @param Takes a std::string array and the size of the array
* @post no return, just sorts the array
*/
void Search::bubbleSort(std::string arr[], int size)
{
	int maxElement, index;
	for (maxElement = size - 1; maxElement > 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			if (arr[index] > arr[index + 1])
			{
				swap(arr[index], arr[index + 1]);
			}
		}
	}
}

/** selection sorts the string array 
* @param Takes a std::string array and the size of the array
* @post no return, just sorts the array
*/
void Search::selectionSort(std::string arr[], int size)
{
	std::string minIndex, minValue;
	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = arr[start];
		for (int index = start + 1; index < size; index++)
		{
			if (arr[index] < minValue)
			{
				minValue = arr[index];
				minIndex = index;
			}
		}
	}
}



//TODO - implement overidden binarySearch() for all data types

