#include "func.h"
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;
//сортировка выбором
Stats selectionSort(vector<int> a) {
    Stats s;
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        s.cmp_o++;
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            s.cmp_o++;
            s.cmp_e++;
            if (a[j] < a[min_idx]) min_idx = j;
        }
        if (min_idx != i) {
            swap(a[i], a[min_idx]); s.swp++;
        }
    }
    return s;
}

// 2. Простой обмен(пузырек)
Stats bubbleSort(vector<int> a) {
    Stats s;
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        s.cmp_o++;
        for (int j = 0; j < n - i - 1; j++) {
            s.cmp_o++;
            s.cmp_e++;
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]); s.swp++;
            }
        }
    }
    return s;
}

// 3. Улучшенный обмен (модифицированный пузырек)
Stats bubbleSortAdvanced(vector<int> a) {
    Stats s;
    int n = a.size();
    int k = n - 1;
    while (k > 0) {
        s.cmp_o++;
        int last = 0;
        for (int j = 0; j < k; j++) {
            s.cmp_o++;
            s.cmp_e++;
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                s.swp++;
                last = j;
            }
        }
        k = last;
    }
    return s;
}

// 4. Шейкер-сортировка
Stats shakerSort(vector<int> a) {
    Stats s;
    int left = 0, right = a.size() - 1, last = 0;
    while (left < right) {
        s.cmp_o++;
        for (int i = left; i < right; i++) {
            s.cmp_o++;
            s.cmp_e++;
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                s.swp++;
                last = i;
            }
        }
        right = last;
        s.cmp_o++;
        for (int i = right; i > left; i--) {
            s.cmp_o++;
            s.cmp_e++;
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                s.swp++;
                last = i;
            }
        }
        left = last;
    }
    return s;
}
// 5. Прямые вставки
Stats insertionSort(vector<int> a) {
    Stats s; int n = a.size();
    for (int i = 1; i < n; i++) {// Начинаем со второго элемента
        s.cmp_o++;
        int x = a[i], j = i - 1;
        while (j >= 0 && a[j] > x) {
            s.cmp_o++;
            s.cmp_e++;
            a[j + 1] = a[j];
            s.swp++;
            j--;
        }
        s.cmp_o++; a[j + 1] = x;
    }
    return s;
}
// 6. Вставки с барьером (используем a[0] как барьер)
Stats insertionSortWithBarrier(vector<int> a) {
    Stats s;
    a.insert(a.begin(), 0);
    int n = a.size();
    for (int i = 2; i < n; i++) {
        s.cmp_o++;
        a[0] = a[i];// Кладём текущий элемент в "барьер" (нулевую ячейку)
        int j = i - 1;
        while (a[j] > a[0]) {
            s.cmp_e++;
            a[j + 1] = a[j];
            s.swp++;
            j--;
        }
        s.cmp_e++;
        a[j + 1] = a[0];
    }
    return s;
}

// Вспомогательные для Слияния (№7) и Хоара (№8)
void merge(vector<int>& a, int l, int m, int r, Stats& s) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        s.cmp_o++; s.cmp_e++;
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
        s.swp++;
    }
    while (i < n1) { a[k++] = L[i++]; s.swp++; s.cmp_o++; }
    while (j < n2) { a[k++] = R[j++]; s.swp++; s.cmp_o++; }
}
//сортировка слияниями
void mSort(vector<int>& a, int l, int r, Stats& s) {
    if (l < r) {
        s.cmp_o++; int m = l + (r - l) / 2;
        mSort(a, l, m, s); mSort(a, m + 1, r, s);
        merge(a, l, m, r, s);
    }
}

Stats mergeSort(vector<int>& a) { Stats s; mSort(a, 0, a.size() - 1, s); return s; }
//сортировка Хоара(quick sort)
void qSort(vector<int>& a, int low, int high, Stats& s) {
    int i = low, j = high, pivot = a[(low + high) / 2];
    while (i <= j) {
        s.cmp_o++;
        while (a[i] < pivot) { s.cmp_e++; s.cmp_o++; i++; }
        while (a[j] > pivot) { s.cmp_e++; s.cmp_o++; j--; }
        s.cmp_e++;
        s.cmp_e++;
        if (i <= j) { swap(a[i], a[j]); s.swp++; i++; j--; }
    }
    if (low < j) qSort(a, low, j, s);
    if (i < high) qSort(a, i, high, s);
}

Stats quickSort(vector<int>& a) { Stats s; qSort(a, 0, a.size() - 1, s); return s; }



string getSortingTableRow(int methodNum, int n) {
    vector<int> s_arr(n), r_arr(n), rand_arr(n);
    for (int i = 0; i < n; i++) {
        s_arr[i] = i;
        r_arr[i] = n - i;
        rand_arr[i] = rand() % 100000;
    }

    Stats s1, s2, s3;
    switch (methodNum) {
    case 1:
        s1 = selectionSort(s_arr);
        s2 = selectionSort(r_arr);
        s3 = selectionSort(rand_arr);
        break;
    case 2:
        s1 = bubbleSort(s_arr);
        s2 = bubbleSort(r_arr);
        s3 = bubbleSort(rand_arr);
        break;
    case 3:
        s1 = bubbleSortAdvanced(s_arr);
        s2 = bubbleSortAdvanced(r_arr);
        s3 = bubbleSortAdvanced(rand_arr);
        break;
    case 4:
        s1 = shakerSort(s_arr);
        s2 = shakerSort(r_arr);
        s3 = shakerSort(rand_arr);
        break;
    case 5:
        s1 = insertionSort(s_arr);
        s2 = insertionSort(r_arr);
        s3 = insertionSort(rand_arr);
        break;
    case 6:
        s1 = insertionSortWithBarrier(s_arr);
        s2 = insertionSortWithBarrier(r_arr);
        s3 = insertionSortWithBarrier(rand_arr);
        break;
    case 7:
        s1 = mergeSort(s_arr);
        s2 = mergeSort(r_arr); s3 = mergeSort(rand_arr); break;
    case 8:
        s1 = quickSort(s_arr);
        s2 = quickSort(r_arr);
        s3 = quickSort(rand_arr);
        break;
    }

    stringstream ss;
    ss << "| №" << methodNum << " | "
        << setw(10) << s1.cmp_e << " | " << setw(10) << s1.cmp_o << " | " << setw(15) << s1.swp << " | "
        << setw(10) << s2.cmp_e << " | " << setw(10) << s2.cmp_o << " | " << setw(15) << s2.swp << " | "
        << setw(10) << s3.cmp_e << " | " << setw(10) << s3.cmp_o << " | " << setw(15) << s3.swp << " |";
    return ss.str();
}