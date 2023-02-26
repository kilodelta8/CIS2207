/*
* John Durham
* CIS 2207
* 02/16/23
You are asked to complete Programming Problem 9 on page 352 of your textbook. This program is meant to apply what you have learned in this topic.

Write a program to display the running time of the sorts described in this chapter.  Test the sorts on arrays of various sizes.  Arrays of the same size should contain identical entries.  Use the

clock from <ctime> to time each sort.  See the beginning of the programming problems in Chapter 10 for an example of how-to time code.

The Selection Sort (Listing 11-1 on pp. 327-328)
The Bubble Sort (Listing 11-2 on p. 330)
The Insertion Sort (Listing 11-3 on pp. 332-333)
The Merge Sort (Listing 11-4 on pp. 335-337)
The Quick Sort (Listing 11-5 on p. 344)
The Radix Sort (See pseudocode on p. 348)
*/

#include "Sort.h"
#include <iostream>


namespace Sort {

	template<class itemType>
	void tswap(itemType a, itemType b)
	{
		std::cout << "\"Swapping\"........" << std::endl;
		itemType temp = a;
		a = b;
		b = temp;
	}


	template<class itemType>
	int tfindLargestIndex(const itemType arr[], int arrSize)
	{
		std::cout << "Finding \"Largest Index\"........" << std::endl;
		int indexSoFar = 0;
		for (int currentIndex = 1; currentIndex < arrSize; currentIndex++)
		{
			if (arr[currentIndex] > arr[indexSoFar])
			{
				indexSoFar = currentIndex;
			}
		}
		return indexSoFar;
	}


	template<class itemType>
	void tselectionSort(itemType arr[], int arrSize)
	{
		std::cout << "Starting \"Selection Sort\"........" << std::endl;
		for (int last = arrSize - 1; last >= 1; last--)
		{
			int largest = findLargestIndex(arr, last + 1);
			swap(arr[largest], arr[last]);
		}
	}


	template<class ItemType>
	void tbubbleSort(ItemType arr[], int arrSize)
	{
		std::cout << "Starting \"Bubble Sort\"........" << std::endl;
		bool sorted = false;
		int pass = 1;
		while (!sorted && (pass < arrSize))
		{
			sorted = true;
			for (int index = 0; index < arrSize - pass; index++)
			{
				int nextIndex = index + 1;
				if (arr[index] > arr[nextIndex])
				{
					swap(arr[index], arr[nextIndex]);
					sorted = false;
				}
			}
			pass++;
		}
	}



	template<class itemType>
	void tinsertionSort(itemType arr[], int arrSize)
	{
		std::cout << "Starting \"Insertion Sort\"........" << std::endl;
		for (int unsorted = 1; unsorted < arrSize; unsorted++)
		{
			itemType nextItem = arr[unsorted];
			int location = unsorted;
			while ((location > 0) && (arr[location - 1] > nextItem))
			{
				arr[location] = arr[location - 1];
				location--;
			}
			arr[location] = nextItem;
		}
	}


	template<class itemType>
	void tmerge(itemType arr[], int first, int mid, int last)
	{
		std::cout << "Starting \"Merge\"........" << std::endl;
		const int MAX_SIZE = arr.size();
		itemType tempArr[MAX_SIZE];
		int first1 = first;
		int last1 = mid;
		int first2 = mid + 1;
		int last2 = last;

		int index = first1;
		while ((first1 <= last1) && (first2 <= last2))
		{
			if (arr[first1] <= arr[first2])
			{
				tempArr[index] = arr[first1];
				first1++;
			}
			else
			{
				tempArr[index] = arr[first2];
				first2++;
			}
			index++;
		}

		while (first1 <= last1)
		{
			tempArr[index] = arr[first1];
			first1++;
			index++;
		}

		while (first2 <= last2)
		{
			tempArr[index] = arr[first2];
			first2++;
			index++;
		}

		for (index = first; index <= last; index++)
		{
			arr[index] = tempArr[index];
		}
	}


	template<class itemType>
	void tmergeSort(itemType arr[], int first, int last)
	{
		std::cout << "Starting \"Merge Sort\"........" << std::endl;
		if (first < last)
		{
			int mid = first + (last - first) / 2;
			mergeSort(arr, first, mid);
			mergeSort(arr, mid + 1, last);
			merge(arr, first, mid, last);
		}
	}


	template<class itemType>
	void tsortFirstMiddleLast(itemType arr[], int first, int mid, int last)
	{
		std::cout << "Starting \"SortFML\"........" << std::endl;
		if (arr[first] > arr[mid])
			swap(arr[first], arr[mid]);

		if (arr[mid] < arr[last])
			swap(arr[mid], arr[last]);

		if (arr[first] > arr[mid])
			swap(arr[first], arr[mid]);
	}


	template<class itemType>
	int tpartition(itemType arr[], int first, int last)
	{
		std::cout << "Starting \"Partitioning\"........" << std::endl;
		int mid = first + (last - first) / 2;
		sortFirstMiddleLast(arr, first, mid, last);
		swap(arr[mid], arr[last - 1]);
		int pivotIndex = last - 1;
		int pivot = arr[pivotIndex];

		int indexFromLeft = first + 1;
		int indexFromRight = last - 2;

		bool done = false;
		while (!done)
		{
			while (arr[indexFromLeft] < pivot)
				indexFromLeft = indexFromLeft + 1;

			while (arr[indexFromRight] > pivot)
				indexFromRight = indexFromRight - 1;

			if (indexFromLeft < indexFromRight)
			{
				swap(arr[indexFromLeft], arr[indexFromRight]);
				indexFromLeft = indexFromLeft + 1;
				indexFromRight = indexFromRight - 1;
			}
			else
			{
				done = true;
			}
		}

		swap(arr[pivotIndex], arr[indexFromLeft]);
		pivotIndex = indexFromLeft;

		return pivotIndex;
	}


	template<class itemType>
	void tquickSort(itemType arr, int first, int last)
	{
		std::cout << "Starting \"Quick Sort\"........" << std::endl;
		const int MIN_SIZE = arr.size();//TODO - this cannot EVEN be correct
		if ((last - first + 1) < MIN_SIZE)
		{
			insertionSort(arr, first, last);
		}
		else
		{
			int pivotIndex = partition(arr, first, last);
			quickSort(arr, first, pivotIndex - 10);
			quickSort(arr, pivotIndex + 1, last);
		}
	}


	//https://simplesnippets.tech/radix-sort-algorithm-with-c-code-sorting-algorithms-data-structures-algorithms/
	template<class itemType>
	int tgetMaxValue(itemType arr[], int size)
	{
		int max = arr[0];
		for (int i = 1; i < size; i++)
			if (arr[i] > max)
				max = arr[i];
		return max;
	}


	//https://simplesnippets.tech/radix-sort-algorithm-with-c-code-sorting-algorithms-data-structures-algorithms/
	template<class itemType>
	void tCountingSort(int arr[], int size, int div)
	{
		std::cout << "Starting \"Counting Sort\"........" << std::endl;
		int output[size];
		int count[10] = { 0 };

		for (int i = 0; i < size; i++)
			count[(arr[i] / div) % 10]++;

		for (int i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (int i = size - 1; i >= 0; i--)
		{
			output[count[(arr[i] / div) % 10] - 1] = arr[i];
			count[(arr[i] / div) % 10]--;
		}

		for (int i = 0; i < size; i++)
			arr[i] = output[i];
	}



	//https://simplesnippets.tech/radix-sort-algorithm-with-c-code-sorting-algorithms-data-structures-algorithms/
	template<class itemType>
	void tradixSort(itemType arr[], int size)
	{
		std::cout << "Starting \"Radix Sort\"........" << std::endl;
		int val = getMax(arr, size);
		for (int div = 1; val / div > 0; div *= 10)
			CountingSort(arr, size, div);
	}
}