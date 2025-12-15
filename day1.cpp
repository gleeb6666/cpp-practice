#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findmin(const vector<int>& dynamic) {
	int x = dynamic[0];
	for (int i = 1; i < dynamic.size(); i++) {
		if (x >= dynamic[i]) {
			x = dynamic[i];
		}
	}
	return x;
}
int findmax(const vector<int>& dynamic) {
	int x = dynamic[0];
	for (int i = 1; i < dynamic.size(); i++) {
		if (x <= dynamic[i]) {
			x = dynamic[i];
		}
	}
	return x;
}
	double avgsum(const vector<int>& dynamic) {
	double sum = 0;
	
	for (int i = 0; i < dynamic.size(); i++) {
		sum += dynamic[i];
	}
	return sum / dynamic.size();
}

	void SortVector(vector<int>& dynamic) {
		sort(dynamic.begin(), dynamic.end());
	}

	void printVector(const vector<int>& dynamic) {
		for (int num : dynamic) cout << num << " ";
		cout << endl;
	}


int main() {
	int size;
	cout << "Enter vector size: ";
	cin >> size;
	vector<int> dynamic(size);

	for (int i = 0; i < size; i++) {

		cin >> dynamic[i];
	}
	cout <<"|--------- MIN MAX AVG -----------|"<< endl;
	int min = findmin(dynamic);
	cout << "Min: " << min << endl;

	int max = findmax(dynamic);
	cout << "Max: " << max << endl;

	double average = avgsum(dynamic);
	cout << "Average: " << average << endl;

	cout <<"|--------- Sort massive ----------|"<< endl;
	cout << "Vector before sort: ";
	printVector(dynamic);

	SortVector(dynamic);
	cout << "Vector after sort: ";
	printVector(dynamic);
	cout << "\n|-------------- END --------------|" << endl;
}

