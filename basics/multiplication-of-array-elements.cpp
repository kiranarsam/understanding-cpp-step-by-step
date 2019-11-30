
#include <iostream>
using namespace std;

// Iterative method

int iterativeMultiply(int array[], int n)
{
    int result = 1;
    for(int i = 0; i < n; i++) {
        result = result * array[i];
    }

    return result;
}

int recursiveMultiply(int a[], int n)
{
    // Termination condition
    if(n == 0) {
        return a[n];
    }
    else {
        return a[n] * recursiveMultiply(a, n-1);
    }
}

int main() {

    int array[] = {1,2,3,4,5};
    int len = sizeof(array)/sizeof(array[0]);

    cout << "Iterative Output: " << iterativeMultiply(array, len) << endl;

    cout << "Recursive Output: " << recursiveMultiply(array, len - 1) << endl;

    return 0;
}