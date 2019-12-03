#include <iostream>
using namespace std;

class Student {
        int id;
    public:
        Student() {
            id = 0;
        }

        //global friend function
        friend void displayStudent(Student& s);
};

void displayStudent(Student & s) {
    cout << "Student::id = " << s.id << endl;
}

int main() {
    Student s;
    displayStudent(s);

    return 0;
}