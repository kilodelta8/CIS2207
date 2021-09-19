#include "Search.h"


/** Searches through an array of strings
* @param 
*/
                         //arr to search    first subscript      target value 
                         //                            last subscript
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
void Search::swap(std::string& a, std::string& b)
{
	std::string temp = a;
	a = b;
	b = temp;
}


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

