#include <iostream>
#include <vector>

using namespace std; 

void enterarray(vector<int>& v, int n) {
	
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
}

void print(const vector<int>& v) {
	for (int x : v) {
		cout << x << " ";
	}
}

void addZeros(vector<int>& v, int k) {
	for (int i = 0; i < k; i++) {
		v.push_back(0);
	}
}

void squareAll(vector<int>& v) {
	for (int& x : v) {
		x *= x;
	}
}
vector<int> readVector(int n) {

}


int main() {
	int n;
	cout << "Enter n: ";
	cin >> n;
	vector<int> v;
	cout << "Enter array: ";
	enterarray(v, n);

	cout << "Size: " << v.size() << " . " << "Capacity: " << v.capacity() << endl;
	int k;
	cout << "Enter k: ";
	cin >> k;

	addZeros(v, k);
	cout << "Size: " << v.size() << " . " << "Capacity: " << v.capacity() << endl;
	squareAll(v);
	cout << "Array: ";
	print(v);

}