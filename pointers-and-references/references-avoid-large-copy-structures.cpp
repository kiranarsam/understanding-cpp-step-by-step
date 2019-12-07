
#include <iostream>
using namespace std;

struct Student {
    string name;
    string address;
    int rollNo;
};

void print(const Student &s) {
    cout << s.name << " " << s.address << " " << s.rollNo << endl;
}