#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <format>

using namespace std;
struct Student {
	string name;
	int grade;
};

vector<Student> inputStudents(int n) {
    vector<Student> v;
    for (int i = 0; i < n; i++) {
        Student s;
        cout << format("{}. ", i+1);
        cin >> s.name >> s.grade;
        v.push_back(s);
    }
    return v;
}

static void printStudents(const vector<Student>& stu) {
    for (Student x : stu) {
        cout << "Name: " << x.name << ", grade: " << x.grade << endl;
    }
}

int main() {
	
	int n;
	cout << "Enter count of students: ";
	cin >> n;

    cout << "Enter student Name and grade: " << endl;
    vector<Student> stu = inputStudents(n);

    auto it = remove_if(stu.begin(), stu.end(), [](const Student& grade) {return grade.grade < 60; });
    stu.erase(it, stu.end());

    sort(stu.begin(), stu.end(), [](const Student&  a, const Student& b) {return a.grade > b.grade; });
    auto count = count_if(stu.begin(), stu.end(), [](const Student& grade) {return grade.grade >= 90; });

    cout << "Students  names and grades: " << endl;
    printStudents(stu);

    cout << "Students with grade more than 90: " << count;
}
