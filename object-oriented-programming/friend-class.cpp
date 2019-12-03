#include <iostream>

using namespace std;

class Student {
    private:
        int id;
    public:
        Student() {
            id = 0;
        }

        friend class College;
};

class College {
    private:
        int pinCode;
    public:
        void showStudent(Student &s) {
            cout << "Student::id = " << s.id << endl;
        }
};

int main() {
    Student s;
    College c;

    c.showStudent(s);

    return 0;
}