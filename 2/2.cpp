#include <iostream>
#include "func.h"
using namespace std;
int main() {
	int size;
	cout << "Input size of array: " << endl;
	cin >> size;
	int* array = create_Array(size);
	print(array, size);
	int* res_array = helper_Array(array, size);
	print(res_array, size);
}