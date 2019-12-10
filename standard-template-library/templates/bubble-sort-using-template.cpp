#include <iostream>
using namespace std;

// Template function to implement bubble sort

template <class T>
void bubbleSort(T a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = n - 1; i < j; j--) {
            if(a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
            }
        }
    }
}

void print(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// test the code
int main() {
    int a[6] = {10, 50, 30, 20, 40, 15};
    int n = sizeof(a) / sizeof(a[0]);

    bubbleSort(a, n); // calls the template function

    cout << "Sorted Array: ";
    print(a, n);
    
    return 0;
}