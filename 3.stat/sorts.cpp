#include "sorts.h"
#include <algorithm>
#include <chrono>
#include <sstream>
#include <iomanip>

using namespace std;
using namespace std::chrono;



void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int mi = i;
        for (int j = i + 1; j < n; j++) if (a[j] < a[mi]) mi = j;
        swap(a[i], a[mi]);
    }
}

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
}

void bubbleSortAdvanced(vector<int>& a) {
    int k = a.size() - 1;
    while (k > 0) {
        int last = 0;
        for (int j = 0; j < k; j++) if (a[j] > a[j + 1]) { swap(a[j], a[j + 1]); last = j; }
        k = last;
    }
}

void shakerSort(vector<int>& a) {
    int l = 0, r = a.size() - 1, last = 0;
    while (l < r) {
        for (int i = l; i < r; i++) if (a[i] > a[i + 1]) { swap(a[i], a[i + 1]); last = i; }
        r = last;
        for (int i = r; i > l; i--) if (a[i] < a[i - 1]) { swap(a[i], a[i - 1]); last = i; }
        l = last;
    }
}

void insertionSort(vector<int>& a) {
    for (int i = 1; i < (int)a.size(); i++) {
        int x = a[i], j = i - 1;
        while (j >= 0 && a[j] > x) { a[j + 1] = a[j]; j--; }
        a[j + 1] = x;
    }
}

void insertionSortWithBarrier(vector<int>& a) {
    if (a.empty()) return;
    a.insert(a.begin(), 0);
    for (int i = 2; i < (int)a.size(); i++) {
        a[0] = a[i]; int j = i - 1;
        while (a[j] > a[0]) { a[j + 1] = a[j]; j--; }
        a[j + 1] = a[0];
    }
    a.erase(a.begin());
}

void mrg(vector<int>& a, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++]; while (j < n2) a[k++] = R[j++];
}
void mSort(vector<int>& a, int l, int r) { if (l < r) { int m = l + (r - l) / 2; mSort(a, l, m); mSort(a, m + 1, r); mrg(a, l, m, r); } }
void mergeSort(vector<int>& a) { mSort(a, 0, a.size() - 1); }

void qSort(vector<int>& a, int low, int high) {
    int i = low, j = high, pivot = a[(low + high) / 2];
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) swap(a[i++], a[j--]);
    }
    if (low < j) qSort(a, low, j); if (i < high) qSort(a, i, high);
}
void quickSort(vector<int>& a) { qSort(a, 0, a.size() - 1); }


double getAvgTime(int method, int n) {
    double totalTime = 0;
    for (int rep = 0; rep < 10; rep++) {
        vector<int> a(n);
        for (int k = 0; k < n; k++) a[k] = rand() % 100000;

        auto start = high_resolution_clock::now();
        if (method == 1) selectionSort(a);
        else if (method == 2) bubbleSort(a);
        else if (method == 3) bubbleSortAdvanced(a);
        else if (method == 4) shakerSort(a);
        else if (method == 5) insertionSort(a);
        else if (method == 6) insertionSortWithBarrier(a);
        else if (method == 7) mergeSort(a);
        else if (method == 8) quickSort(a);
        auto end = high_resolution_clock::now();

        totalTime += duration<double>(end - start).count();
    }
    return totalTime / 10.0;
}

string getBenchmarkRow(int n) {
    stringstream ss;
    ss << left << setw(8) << n << " | ";
    for (int m = 1; m <= 8; m++) {
        ss << fixed << setprecision(5) << setw(10) << getAvgTime(m, n) << " | ";
    }
    return ss.str();
}