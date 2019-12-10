#include <iostream>
using namespace std;

template <class T>
void fun(T a) {
    cout << "The main template fun(): " << a << endl;
}

template <>
void fun(int a) {
    cout << "Specialized Template for int type: " << a << endl;
}

template <class T>
class Test {
    // Data members of test
    public:
        Test() {
            // Initilization of dat members
            cout << "General template object" << endl;
        }
        // Other methods of Test
};

template <>
class Test <int>
{
    public:
        Test() {
            // Initilization of dat members
            cout << "Specialized Template object" << endl;
        }
};


int main() {
    fun<char>('a');
    fun<int>(10);
    fun<double>(3.14);

    // class objects
    Test<int> a;
    Test<char> ch;
    Test<float> fl;
    
    return 0;
}