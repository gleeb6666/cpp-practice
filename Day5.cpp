#include <iostream>

using namespace std;
void swapValues(int& x, int& y) {	
	int number = x;
	x = y;
	y = number;
}

void incrementAll(int arr[], int n) {
	int* p2 = arr;
	for (int i = 0; i < 5; i++) {
		*(p2 + i) += 1;
	}
}

void printarray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

void swapPointers(int*& p1, int*& p2){
	int* num1 = p1;
	p1 = p2;
	p2 = num1;
}

int main() {
	int a = 10;
	int* p = &a;
	cout << "Adress 'a': " << p << endl;
	*p = 20;
	cout << "New value: " << *p << endl;
	
	int arr[5] = {1, 2, 3, 4, 5};
	int* p1 = arr;
	for (int i = 0; i < 5; i++) {
		cout << *(p1 +i) << " ";
	}
	cout << endl;
	*(p1 + 2) = 10;
	
	for (int i = 0; i < 5; i++) {
		cout << *(p1+i) << " ";
	
	}
	cout << endl;
	
	int a1 = 5;
	int b = 10;
	cout << "Before a and b: " << a1  << " and " << b << endl;
	swapValues(a1, b);
	cout << "After a and b: " << a1 << " and " << b << endl;
	
	int arr1[5] = {2, 4, 6, 8, 10};
	printarray(arr1, 5);
	incrementAll(arr1, 5);
	cout << endl;
	printarray(arr1, 5);
	cout << endl;
	int x = 40;
	int y = 20;
	int* p2 = &x;
	int* p3 = &y;
	cout << p2 << " and " << p3 << endl;

	swapPointers(p2, p3);
	cout << p2 << " and " << p3 << endl;
}
