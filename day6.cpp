#include <iostream>

using namespace std; 

int* createarray(int size) {
	int* a = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}
	return a;
}

void printarray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}
 int* copyarray(int* arr, int Oldsize, int Newsize) {
	int* b = new int[Newsize];
	for (int i = 0; i < Oldsize; i++) {
	  b[i] = arr[i];
	}
	delete[] arr;
	arr = b;
	for (int i = Oldsize; i < Newsize; i++) {
		b[i] = -1;
	}
	return b;
}

int main() {
	int n;
	cout << "Enter array size: ";
	cin >> n;
	cout << "\nEnter array: ";
	int* arr = createarray(n);
	cout << "\nOld array: ";
	printarray(arr, n);
	int newsize = n + 2;
	
	arr = copyarray(arr, n, newsize);
	cout << "\nNew array: ";
	printarray(arr, newsize);
	delete[] arr;
	arr = nullptr;
	return 0;
}
