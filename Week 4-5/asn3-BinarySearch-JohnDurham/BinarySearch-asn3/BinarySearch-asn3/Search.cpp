/** @file Search.cpp implemetataion file */
/** @author John Durham */
/** @date 02/02/2023 */
/** @version 0.0.3 */
/* CIS 2207.501
* You are asked to complete Programming Problem 3 on page 94 of your textbook.
* Problem 3: Implement the binarySearch algorithm presented in this chapter for an array of string.
* This program is meant to apply what you have learned in this topic.
* Make sure to implement the binarySearch algorithm presented in this chapter for the array of strings (page 70).
* Note that the binarySearch is a recursive algorithm.
*/
#include "Search.h"
#include <string>


/** Searches through an array of strings
* @param 
* @post return the index of the target if found OR -1 indicating it wasn't found
*/
int Search::binarySearch(const std::string arr[], int size, int first, int last, std::string target)
{
	if (first > last)
		return -1;
	else
	{
		int mid = first + (last - first) / 2;
		int comparison = target.compare(arr[mid]);
		if (comparison == 0)
			return mid;
		else if (comparison < 0)
			return binarySearch(arr, size, first, mid - 1, target);
		else
			return binarySearch(arr, size, mid + 1, last, target);
	}
}




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
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j].compare(arr[minIndex]) < 0)
				minIndex = j;
		}
		std::swap(arr[minIndex], arr[i]);
	}
}