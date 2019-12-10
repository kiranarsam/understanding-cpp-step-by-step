#include <iostream>
#include <algorithm>

using namespace std;

void show(int a[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// ===================================
// Writing own comparator function
struct Interval {
    int start, end;
};

// Compares two intervals according to starting values
bool compareInterval(Interval i1, Interval i2) {
    return (i1.start < i2.start);
}
// ====================================

bool compare_ascending(int a, int b) {
    return a < b;
}
// =====================================
//
int main() {
    int arr[] = {1,5,8,6,9,7,2,4,3,0};

    int n = sizeof(arr)/sizeof(arr[0]);

    // By default ascending order
    sort(arr, arr+n);

    show(arr, n);

    // Sort by descending order
    sort(arr, arr+n, greater<int>());

    show(arr, n);

    // Sort by descending order
    sort(arr, arr+n, compare_ascending);

    show(arr, n);

    // using user defined comparator function
    // Sort in increasing order of time
    Interval arr1[] = {{6,8}, {1,9}, {2,4}, {4,7}};
    n = sizeof(arr1) / sizeof(arr1[0]);
    sort(arr1, arr1+n, compareInterval);
    for(int i = 0; i < n; ++i) {
        cout << "[" << arr1[i].start << "," << arr1[i].end << "]" << " ";
    }
    cout << endl;

    return 0;
}