#pragma once
#pragma once
#include <random>
#include<iostream>
#include"func.h"
int* create_Array(const int size) {
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100;
	}
	return array;
}
int* helper_Array(int* array, const int size) {
	int* help_array = new int[size];
	int pos = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] % 2 == 0)
		{
			help_array[pos] = array[i];
			pos++;
		}
	}
	for (int i = 0; i < size; i++) {
		if (array[i] % 2 != 0)
		{
			help_array[pos] = array[i];
			pos++;
		}
	}
	return help_array;
}
void print(int* array, const int size) {
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}