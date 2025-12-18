#include <iostream>
#include <string>
using namespace std;

const int max_n = 100;
int arrsub[max_n] = {};

bool isArrayEntered = false;
int n = 0;

bool inputArray(int arr[max_n], int& n) {
    int count = 0;
    string input;
    cout << "Enter the desired array length (max " << max_n << "): ";
    cin >> n;

    if (n <= 0 || n > max_n) {
        cout << "Invalid length!\n";
        return false;
    }
    
    cout << "Enter your array elements (type 'stop' to finish early): ";
    while (count < n) {
        cin >> input;
        if (input == "stop") break;
        try {
            arr[count] = stoi(input);
            count++;
        }
        catch (...) {
            cout << "Error: not a number. Try again.\n";
        }
    }
    n = count;
    return true;
}

bool checkArray(bool isArrayEntered) {
    if (!isArrayEntered) {
        cout << "Array is empty. Please choose option 1 first.\n";
        return false;
    }
    return true;
}


void printArray(int arr[max_n], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int sumArray(int arr[max_n], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum;
}

int MaxVal(int arr[max_n], int n) {
    if (n == 0) return 0;
    int maxval = arr[0];
    for (int i = 1; i < n; i++) {
     
        if (arr[i] > maxval) maxval = arr[i];
    }
    return maxval;
}
int MinVal(int arr[max_n], int n){
    if (n == 0) return 0;
    int minval = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minval) minval = arr[i];
    }
    return minval;
}

double averageArray(int arr[max_n], int n) {
    if (n == 0) return 0;
    return static_cast<double>(sumArray(arr, n)) / n;
}

int maxAscendingSubsequence(int arr[max_n], int n) {
    if (n == 0) return 0;

    int sub = 1;
    int maxsub = 1;
    int endIndex = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] < arr[i]) sub++;
        else sub = 1;

        if (sub > maxsub) {
            maxsub = sub;
            endIndex = i + 1;
        }
    }

    for (int x = 0; x < maxsub; x++)
        arrsub[x] = arr[endIndex - maxsub + x];

    return maxsub;
}

void ClearArray(int arr[max_n], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
}

void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore(10000, '\n');
    cin.get();
}

void ReverseArray(int arr[max_n], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}
void sort(int arr[max_n], int n) {
    if (n <= 1) return;
    int pivot = arr[n / 2];
    int arrleft[max_n], arrright[max_n];
    int leftCount = 0, rightCount = 0;
    for (int i = 0; i < n; i++) {
        if (i == n / 2) continue;
        if (arr[i] < pivot) arrleft[leftCount++] = arr[i];
        else arrright[rightCount++] = arr[i];
    }
    sort(arrleft, leftCount);
    sort(arrright, rightCount);
    int index = 0;
    for (int i = 0; i < leftCount; i++) arr[index++] = arrleft[i];
    arr[index++] = pivot;
    for (int i = 0; i < rightCount; i++) arr[index++] = arrright[i];
}



int main() {
    int arr[max_n] = {};
    int action;

    while (true) {
        cout << "\n---- Menu ----\n";
        cout << "1. Enter array\n";
        cout << "2. Show array\n";
        cout << "3. Sum of elements\n";
        cout << "4. Max and Min\n";
        cout << "5. Average\n";
        cout << "6. Maximum ascending subsequence\n";
        cout << "7. Reverse array\n";
        cout << "8. Sort array\n";
        cout << "9. Clear array\n";
        cout << "0. Exit\n";

        cout << "Choose action: ";
        cin >> action;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Try again.\n";
            continue;
        }

        cout << endl;

        switch (action) {
        case 1:
            isArrayEntered = inputArray(arr, n);
            pause();
            break;

        case 2:
            if (!checkArray(isArrayEntered)) continue;
            cout << "Your array: ";
            printArray(arr, n);
            pause();
            break;

        case 3:
            if (!checkArray(isArrayEntered)) continue;
            cout << "Sum of elements: " << sumArray(arr, n) << endl;
            pause();
            break;

        case 4:
            if (!checkArray(isArrayEntered)) continue;
            cout << "Max: " << MaxVal(arr, n) << endl;
            cout << "Min: " << MinVal(arr, n) << endl;
            pause();
            break;

        case 5:
            if (!checkArray(isArrayEntered)) continue;
            cout << "Average: " << averageArray(arr, n) << endl;
            pause();
            break;

        case 6:
            if (!checkArray(isArrayEntered)) continue;
            int maxsub;
            maxsub = maxAscendingSubsequence(arr, n);
            cout << "Length of max ascending subsequence: " << maxsub << endl;
            cout << "Subsequence: ";
            printArray(arrsub, maxsub);
            pause();
            break;
        
        case 7:
            if (!checkArray(isArrayEntered)) continue;
            ReverseArray(arr, n);
            cout << "Your reverse array: ";
            printArray(arr, n);
            pause();
            break;
       
        case 8:
            if (!checkArray(isArrayEntered)) continue;
            sort(arr, n);
            cout << "Your sort array: ";
            printArray(arr, n);
            pause();
            break;
        
        case 9:
            if (!checkArray(isArrayEntered)) continue;
            ClearArray(arr, n);
            cout << "Your array clean!" << endl;
            n = 0;
            isArrayEntered = false;
            pause();
            break;

        case 0:
            cout << "Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
            break;
        }
    }
}
