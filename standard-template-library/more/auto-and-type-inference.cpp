#include <iostream>
#include <typeinfo>
#include <string>
#include <set>
using namespace std;

int fun1() {
    return 10;
}

char fun2() {
    return 't';
}

// A generic function which finds minimum of two values return type is type of 
// variable which is minimum
template <class A, class B>
auto findMin(A a, B b) -> decltype(a < b? a : b)
{
    return (a < b? a : b);
}

int main() {
    auto x = 4;
    auto y = 3.14;
    auto ptr = &x;

    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    cout << typeid(ptr).name() << endl;

    set <string> st;
    st.insert({"Test", "The", "Code"});

    // it evalutes to iterator to set of string type automatically
    for(auto it = st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // decltype 
    // Data type of x is same as return type of fun1()
    // and type of y is same as return type of fun2()
    decltype(fun1()) x1;
    decltype(fun2()) y1;

    cout << typeid(x1).name() << endl;
    cout << typeid(y1).name() << endl;

    int a = 10;

    // j will be the type int: data type of x
    decltype(x) j = a + 10;

    cout << typeid(j).name() << endl;


    cout << findMin(4, 3.44) << endl;

    cout << findMin(5.4, 3) << endl;

    return 0;
}