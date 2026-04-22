#pragma once
#include <vector>
#include <string>

struct Stats {
    long long cmp_e = 0;
    long long cmp_o = 0;
    long long swp = 0;
};

Stats selectionSort(std::vector<int> a);
Stats bubbleSort(std::vector<int> a);
Stats bubbleSortAdvanced(std::vector<int> a);
Stats shakerSort(std::vector<int> a);
Stats insertionSort(std::vector<int> a);
Stats insertionSortWithBarrier(std::vector<int> a);
Stats mergeSort(std::vector<int>& a);
Stats quickSort(std::vector<int>& a);

std::string getSortingTableRow(int methodNum, int n);

