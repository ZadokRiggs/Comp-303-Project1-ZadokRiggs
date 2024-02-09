#include "function.h"
#include <iostream>
using namespace std;

int check_num(int &size, int array[], int num) {
	for (int i = 0; i < size; i++) {
		if (array[i] == num) {
			return i;
		}
	}
	return -999;
}
int modify(int &size, int array[], int num, int num2) {
	//replaces space at num with num2
	if (num < size && num >= 0) {
		array[num] = num2;
		return 1;
	}
	return 0;
	
}
void append(int &size, int array[], int num) {
	size += 1;
	int* new_data = new int[size];
	for (int i = 0; i < size; i++) {
		new_data[i] = array[i];
		cout << i << " ";
	}
	cout << 3 << endl;
	new_data[size-1] = num;
	cout << 2 << endl;
	delete[] array;
	cout << 1 << endl;
	array = new_data;
	cout << endl 
		<< "Append Successful." 
		<< endl 
		<< endl;
	return;
}
int zero_out(int &size, int array[], int num) {
	if (num < size && num >= 0) {
		array[num] = 0;
		return 1;
	}
	return 0;
}
