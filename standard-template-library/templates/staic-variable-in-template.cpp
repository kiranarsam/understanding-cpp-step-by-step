#include <iostream>
using namespace std;

template <typename T>
void fun(const T& x) {
    static int i = 10;

    cout << ++i << endl;

    return;
}

template <class T>
class Test {
    private:
        T val;
    public:
        static int count;
        Test() {
            count++;
        }
        // Some other stuff
};

template <class T>
int Test<T>::count = 0;


int main() {
    // function static templates
    fun<int>(1); // prints 11
    fun<int>(2); // prints 12
    fun<int>(3); // prints 13
    fun<double>(1.1); // prints 11
    fun('a'); // prints 11
    fun<int>(4); // prints 14

    // class static templates
    Test<int> a;
    Test<int> b;
    Test<double> c;

    cout << Test<int>::count << endl; // prints 2
    cout << Test<double>::count << endl; // prints 1

    return 0;
}