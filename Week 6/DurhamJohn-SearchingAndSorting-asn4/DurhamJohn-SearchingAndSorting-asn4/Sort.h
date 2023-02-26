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

#pragma once
#ifndef SORT_H
#define SORT_H

namespace Sort{

template<class itemType>
void tswap(itemType a, itemType b);

template<class itemType>
int tfindLargestIndex(const itemType arr[], int arrSize);

template<class itemType>
void tselectionSort(itemType arr[], int arrSize);

template<class itemType>
void tbubbleSort(itemType arr[], int arrSize);

template<class itemType>
void tinsertionSort(itemType arr[], int arrSize);

template<class itemType>
void tmerge(itemType arr[], int first, int mid, int last);

template<class itemType>
void tmergeSort(itemType arr[], int first, int last);

template<class itemType>
void tsortFirstMiddleLast(itemType arr[], int first, int mid, int last);

template<class itemType>
int tpartition(itemType arr[], int first, int last);

template<class itemType>
void tquickSort(itemType arr, int first, int last);

template<class itemType>
int tgetMaxValue(itemType arr[], int size);

//https://simplesnippets.tech/radix-sort-algorithm-with-c-code-sorting-algorithms-data-structures-algorithms/
template<class itemType>
void tCountingSort(int arr[], int size, int div);

//https://simplesnippets.tech/radix-sort-algorithm-with-c-code-sorting-algorithms-data-structures-algorithms/
template<class itemType>
void tradixSort(itemType arr[], int size);

}

#endif // !SORT_
