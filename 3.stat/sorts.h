#pragma once
#include <vector>
#include <string>

void selectionSort(std::vector<int>& a);
void bubbleSort(std::vector<int>& a);
void bubbleSortAdvanced(std::vector<int>& a);
void shakerSort(std::vector<int>& a);
void insertionSort(std::vector<int>& a);
void insertionSortWithBarrier(std::vector<int>& a);
void mergeSort(std::vector<int>& a);
void quickSort(std::vector<int>& a);

std::string getBenchmarkRow(int n);
