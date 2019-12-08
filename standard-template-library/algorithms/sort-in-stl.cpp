#include <iostream>
#include <algorithm>

using namespace std;

void show(int a[]) {
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[10] = { 1, 4, 2, 9, 5, 3, 6, 8, 7, 10};
    cout << "Before sorting: ";
    show(a);

    sort(a, a+10);

    cout << "After sorting: ";
    show(a);

    return 0;
}