#include <iostream>
#include <cstdlib>
#include <ctime>
void print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int* createArray(int n) {
    std::cout << "Заполняем случайными элементами" << std::endl;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}
void findMinMax(int* arr, int n, int& u, int& v) {
    u = arr[0];
    v = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < u) u = arr[i];
        if (arr[i] > v) v = arr[i];
    }
    //ищем мин и макс для того чтобы после создавать массив count с корректным кол-вом ячеек(v-u+1)
}
void countingSort(int* arr, int n) {
    if (n <= 1) return;
    int u, v;
    findMinMax(arr, n, u, v);
    int range = v - u + 1;
    int* count = new int[range]();
    for (int i = 0; i < n; i++) {
        count[arr[i] - u]++;// число x будет храниться в count на позиции x-u
    }
    int q = 0;
    for (int i = u; i <= v; i++) {
        for (int j = 0; j < count[i - u]; j++) {
            arr[q++] = i;
        }
    }
    delete[] count;
}
int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    int* arr = createArray(n);
    print(arr, n);
    countingSort(arr, n);
    std::cout << "Отсортированный массив: ";
    print(arr, n);
    delete[] arr;
    return 0;
}