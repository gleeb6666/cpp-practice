#include <iostream>
#include <format>

using namespace std; 
const int Max_I = 100;
const int Max_J = 100;
void inputMatrix(int mat[Max_I][Max_J], int i, int j) {
	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			cin >> mat[x][y];
		}
	}
}

void printMatrix(int mat[Max_I][Max_J], int i, int j) {
	for (int x = 0; x < i; x++) {
		cout << '|';
		for (int y = 0; y < j; y++) {
			cout << mat[x][y] << ' ';
		}
		cout << '|';
		cout << endl;
	}
}

void sumRows(int mat[Max_I][Max_J], int i, int j) {
	int sum = 0;
	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			sum += mat[x][y];
		}
		cout << "Sum of row " << x << " = "<< sum << endl;
		sum = 0;
	}
}

void sumCols(int mat[Max_I][Max_J], int i, int j) {
	int sum = 0;
	for (int y = 0; y < j; y++) {
		for (int x = 0; x < i; x++) {
			sum += mat[x][y];
		}
		cout << "Sum of Column " << y << " = " << sum << endl;
		sum = 0;
	}
}

void findMinMax(int mat[Max_I][Max_J], int i, int j) {
	int min = mat[0][0];
	int max = mat[0][0];
	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			if (min > mat[x][y]) min = mat[x][y];
			if (max < mat[x][y]) max = mat[x][y];
		}
	}
	cout << "Min element = " << min << endl;
	cout << "Max element = " << max << endl;
}

void sumMainDiagonal(int mat[Max_I][Max_J], int i, int j) {
	int sum = 0;
	for (int x = 0; x < min(i,j); x++) {
		sum += mat[x][x];
	}
	cout << "Sum of main diagonal = " << sum << endl;
}

void averageMatrix(int mat[Max_I][Max_J], int i, int j) {
	double sum = 0;
	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			sum += mat[x][y];
		}
	}
	cout << "Average value = " << sum / (i*j) << endl;
}
void transposeMatrix(int mat[Max_I][Max_J], int i, int j) {
	for (int y = 0; y < j; y++) {
		cout << '|';
		for (int x = 0; x < i; x++) {
			cout << mat[x][y] << ' ';
		}
		cout << '|';
		cout << endl;
	}
}

void sumPositiveElements(int mat[Max_I][Max_J], int i, int j) {
	int sum = 0;
	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			if (mat[x][y] > 0) sum += mat[x][y];
		}
	}
	cout << "Sum of positive elements = " << sum << endl;
}

bool isSymmetric(int mat[Max_I][Max_J], int i, int j) {
	if (i != j) return false;          
	for (int x = 0; x < i; x++) {
		for (int y = x + 1; y < j; y++) { 
			if (mat[x][y] != mat[y][x]) return false;
		}
	}
	return true;
}

int main() {
	int i, j;
	cout << "Enter number of rows and columns: ";
	cin >> i >> j;
	cout << format("Enter matrix[{}][{}]: ", i, j);
	int mat[Max_I][Max_J] = {};
	inputMatrix(mat, i, j);
	cout << "-------Your matrix-------" << endl;
	printMatrix(mat, i, j);
	cout << "---Your transpose matrix--" << endl;
	transposeMatrix(mat, i, j);
	cout << "--------Sum of Row--------"<< endl;
	sumRows(mat, i, j);
	cout << "------Sum of Column------" << endl;
	sumCols(mat, i, j);
	cout << "-------Min and Max-------" << endl;
	findMinMax(mat, i, j);
	cout << "---Sum of main Diagonal---" << endl;
	sumMainDiagonal(mat, i, j);
	cout << "-------Average value------" << endl;
	averageMatrix(mat, i, j);
	cout << "---Sum positive elements--" << endl;
	sumPositiveElements(mat, i, j);
	cout << "-----Symmetric matrix-----" << endl;
	cout << "Matrix symmetry: " << isSymmetric(mat, i, j) << endl;
}