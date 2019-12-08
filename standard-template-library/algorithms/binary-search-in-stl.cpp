#include <algorithm>
#include <iostream>
using namespace std;

int print(int a[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[10] = { 1, 4, 2, 9, 5, 3, 6, 8, 7, 10};
    int aSize = sizeof(a)/sizeof(a[0]);

    cout << "The array is: ";
    print(a, aSize);

    cout << "So, first sort the array: ";
    sort(a, a+10);
    print(a, aSize);
    cout << "Binary search for 2: ";
    if(binary_search(a, a+10, 2)) {
        cout << "Element found in the array" << endl;
    }
    else {
        cout << "Not found in array" << endl;
    }

    cout << "Binary search for 10: ";
    if(binary_search(a, a+10, 20)) {
        cout << "Element found in the array" << endl;
    }
    else {
        cout << "Not found in array" << endl;
    }

    return 0;
}