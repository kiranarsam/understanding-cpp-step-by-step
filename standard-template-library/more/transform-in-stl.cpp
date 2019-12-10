#include <bits/stdc++.h>
using namespace std;

// customized comparater
int increment(int x) {
    return (x + 1);
}

int main() {
    int arr1[] = {1,2,3};
    int arr2[] = {4,5,6};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int res[n];
    int res1[n];

    // code to add two arrays
    for(int i = 0; i < n; i++) {
        res[i] = arr1[i] + arr2[i];
    }

    for(int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    // // Single line code to add arr1[] and arr2[] and store result in res1[]
    transform(arr1, arr1+n, arr2, res1, plus<int>());

    // display the list
    for(int i = 0; i < n; i++) {
        cout << res1[i] << " ";
    }
    cout << endl;

    // Apply increment to all elements of arr2[] and store the modified elements 
    // back in arr2[]
    transform(arr2, arr2+n, arr2, increment);

    // display the list
    for(int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;    
}