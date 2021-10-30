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
