#include <iostream>
#include <vector>

using namespace std;

void enterVector(vector<int>& v, int n) {
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
}

void doublVector(vector<int>& v, int n) {
	for (int i = 0; i < n; i++) {
		v.push_back(v[i]);
	}
}

void pow2Vector(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		v[i] *= v[i];
	}
}

int main() {
    vector<int> v;
    int n;
    cout << "Enter 'n' elements: ";
    cin >> n;

    cout << "Enter elements: ";
    enterVector(v, n);

    for (int x : v) cout << x << " ";
    cout << endl;

    cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << endl;

    doublVector(v, n);

    cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << endl;

    pow2Vector(v);

    for (int x : v) cout << x << " ";

    cout << endl;
}
