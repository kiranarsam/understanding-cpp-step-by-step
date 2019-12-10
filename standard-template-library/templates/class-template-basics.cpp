#include <iostream>
using namespace std;

template <class T>
class Array {
    private:
        T *ptr;
        int size;
    public:
        Array(T arr[], int s);
        void print();
};

template <class T>
Array<T>::Array(T arr[], int s) {
    ptr = new T[s];
    size = s;
    for(int i = 0; i < size; i++) {
        ptr[i] = arr[i];
    }
}

template <class T>
void Array<T>::print() {
    for(int i = 0; i < size; i++) {
        cout << " " << *(ptr + i);
    }
    cout << endl;
}

int main() {
    int arr[6] = {2,45,23,43,32,46};
    Array<int> a(arr, 6);
    a.print();

    return 0;
}