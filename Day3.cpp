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

void minMax(int arr[max_n], int n) {
    if (n == 0) return;
    int minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    cout << "Max element: " << maxVal << endl;
    cout << "Min element: " << minVal << endl;
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
            break;

        case 2:
            if (!isArrayEntered) {
                cout << "Array is empty. Please choose option 1 first.\n";
                continue;
            }
            cout << "Your array: ";
            printArray(arr, n);
            break;

        case 3:
            if (!isArrayEntered) {
                cout << "Array is empty. Please choose option 1 first.\n";
                continue;
            }
            cout << "Sum of elements: " << sumArray(arr, n) << endl;
            break;

        case 4:
            if (!isArrayEntered) {
                cout << "Array is empty. Please choose option 1 first.\n";
                continue;
            }
            minMax(arr, n);
            break;

        case 5:
            if (!isArrayEntered) {
                cout << "Array is empty. Please choose option 1 first.\n";
                continue;
            }
            cout << "Average: " << averageArray(arr, n) << endl;
            break;

        case 6:
            if (!isArrayEntered) {
                cout << "Array is empty. Please choose option 1 first.\n";
                continue;
            }
            int maxsub;
            maxsub = maxAscendingSubsequence(arr, n);
            cout << "Length of max ascending subsequence: " << maxsub << endl;
            cout << "Subsequence: ";
            printArray(arrsub, maxsub);
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
