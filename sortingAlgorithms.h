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

#include "selectionSort/selectionSort.tpp"
#include "bubbleSort/bubbleSort.tpp"
#include "insertionSort/insertionSort.tpp"
#include "countingSort/countingSort.tpp"