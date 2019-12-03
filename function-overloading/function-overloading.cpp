#include <iostream>
using namespace std;

void print(int i) {
    cout << "Here is integer " << i << endl;
}

void print(char c) {
    cout << "Here is character " << c << endl;
}

void print(double d) {
    cout << "Here is double " << d << endl;
}

int main() {
    print(20);
    print('a');
    print(39.2);

    return 0;
}

