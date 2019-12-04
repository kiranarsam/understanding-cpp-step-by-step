
// Overlading operator for Array class
#include <iostream>
#include <cstdlib>
using namespace std;

class Array {
    private:
        int *ptr;
        int size;
    public:
        Array(int *, int);

        int& operator[](int); // overloading [] operator

        void print();
};

// Constructor for array class
Array::Array(int *p = NULL, int s = 0) {
    size = s;
    ptr = NULL;
    if(s != 0) {
        ptr = new int[s];
        for(int i = 0; i < s; i++) {
            ptr[i] = p[i];
        }
    }
}

// Implementation of [] operator
int& Array::operator[](int index) {
    if(index >= size) {
        cout << "Array index out of bound, existing " << endl;
        exit(0);
    }
    return ptr[index];
}

void Array::print() {
    for(int i = 0; i < size; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {1,2,4,5,6};
    Array array(a, 5);
    array[2] = 3;
    array.print();
    array[8] = 10;

    return 0;
}

