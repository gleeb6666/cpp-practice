#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> inputArray(int n) {
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x = 0;
		cin >> x;
		v.push_back(x);
	}
	return v;
}

void printArray(vector<int> v) {
	for (int x : v) {
		cout << x << " ";
	}
}

int main() {
	int n;
	cout << "Entert n: ";
	cin >> n;
	cout << "Enter array: ";
	auto v = inputArray(n);

	auto it = remove_if(v.begin(), v.end(), [](int x) {return abs(x) < 5; });
	v.erase(it, v.end());
	sort(v.begin(), v.end(), [](int a, int b) {return a > b; });
	auto count = count_if(v.begin(), v.end(), [](int x) {return x > 10; });

	cout << "Your sorted array: ";
	printArray(v);
	cout << endl;
	cout << "Element bigger than 10: " << count;

}
