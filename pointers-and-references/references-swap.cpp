#include <iostream>
using namespace std;

void swap(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;    
}

int main() {
    int a = 3, b = 6;

    swap(a, b);

    cout << "After swap a & b are : " << a << ", " << b << endl;

    return 0;
}