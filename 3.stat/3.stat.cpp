#include <iostream>
#include <fstream>
#include "sorts.h"

using namespace std;

int main() {
    ofstream f("table2.txt");

    f << "n        | №1         | №2         | №3         | №4         | №5         | №6         | №7         | №8         |" << endl;
    f << "---------|------------|------------|------------|------------|------------|------------|------------|------------|" << endl;
    f << getBenchmarkRow(10000) << endl;  cout << "10k done..." << endl;
    f << getBenchmarkRow(20000) << endl;  cout << "20k done..." << endl;
    f << getBenchmarkRow(30000) << endl;  cout << "30k done..." << endl;
    f << getBenchmarkRow(40000) << endl;  cout << "40k done..." << endl;
    f << getBenchmarkRow(50000) << endl;  cout << "50k done..." << endl;
    f << getBenchmarkRow(60000) << endl;  cout << "60k done..." << endl;
    f << getBenchmarkRow(70000) << endl;  cout << "70k done..." << endl;
    f << getBenchmarkRow(80000) << endl;  cout << "80k done..." << endl;
    f << getBenchmarkRow(90000) << endl;  cout << "90k done..." << endl;
    f << getBenchmarkRow(100000) << endl; cout << "100k done!" << endl;

    f.close();
    cout << "\nРезультаты успешно записаны в файл table2.txt" << endl;

    return 0;
}