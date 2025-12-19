#include <iostream>
using namespace std;

void inputArray(int* arr, int n) {
    cout << "Enter array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void printArray(int* arr, int n) {
    cout << "Your array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sumArray(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum;
}

int* resizeArray(int* arr, int oldSize, int newSize) {
    int* newArr = new int[newSize];          
    for (int i = 0; i < oldSize; i++)       
        newArr[i] = arr[i];

    delete[] arr;                            

    cout << "Enter " << (newSize - oldSize) << " new elements: ";
    for (int i = oldSize; i < newSize; i++) 
        cin >> newArr[i];

    return newArr;                          
}

int main() {
    int n;
    cout << "Enter initial array size: ";
    cin >> n;

    int* arr = new int[n];
    inputArray(arr, n);
    printArray(arr, n);
    cout << "Sum of array: " << sumArray(arr, n) << endl;

    int m;
    cout << "How many more elements to add? ";
    cin >> m;

    int newSize = n + m;
    arr = resizeArray(arr, n, newSize);     
    printArray(arr, newSize);
    cout << "Sum of new array: " << sumArray(arr, newSize) << endl;

    delete[] arr;                            
}
