#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> readArray(int n) {
	vector<int> v;
	v.reserve(n);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	return v;	
}

int main() {
	int n;
	cout << "Enter n: ";
	cin >> n;
	
	cout << "Enter array: ";
	vector<int> v = readArray(n);

	auto it = remove_if(v.begin(), v.end(), [](int x) {return x < 0; });
	v.erase(it, v.end());
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	cout << "Your array: ";
	for (int x : v) {
		cout << x << " ";
	}
}