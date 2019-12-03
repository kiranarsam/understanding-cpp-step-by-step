#include <iostream>

using namespace std;

class College;

class Student {
    public:
        void showCollege(College &c);
};

class College {
    private:
        int pinCode;
    public:
        College() {
            pinCode = 0;
        }
        friend void Student::showCollege(College& c); // Friend function
};

void Student::showCollege(College& c) {
    cout << "College::pinCode = " << c.pinCode << endl;
}

int main() {
    Student s;
    College c;

    s.showCollege(c);

    return 0;
}