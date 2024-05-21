#pragma once

#include "list/list.h"


// Protótipos das funções de algoritmos
template <typename T>
void bubbleSort(Node<T>**);
template <typename T>
void optimized_bubbleSort(Node<T>**);
template <typename T>
void selectionSort(Node<T>**);
template <typename T>
void optimizedSelectionSort(Node<T>**);

template <typename T>
void insertionSort(Node<T>**);

template <typename T>
void countingSort(Node<T>**);

#include "selection_sort/selection_sort.tpp"
#include "bubble_sort/bubble_sort.tpp"
#include "insertion_sort/insertion_sort.tpp"
#include "counting_sort/countingSort.tpp"