#include <iostream>
using namespace std;

// 1.
int& fun() {
    static int x = 10;
    return x;
}

// 2.
int fun2(int &x) {
    return x;
}

// 3. 
void swap(char* &str1, char* &str2) {
    char *temp = str1;
    str1 = str2;
    str2 = temp;
}

// 6. 
int& fun3() {
    int x = 10;
    return x;
}

int main() {

    // 1.
    fun() = 30;
    cout << fun() << endl;

    // 2.
    // cout << fun2(20) << endl; // Error: invalid initialization from rvalue of type int

    // 3.
    const char *str1 = "TestTheCode";
    const char *str2 = "CodeTheTest";
    swap(str1, str2);
    cout << "str1 = " << str1 << ", str2 = " << str2 << endl;

    // 4. 
    int x = 10;
    int *ptr = &x;
    //int &*ptr1 = ptr; // Error: You cannot declare pointer to int&

    // 5. 
    int *pp = NULL;
    int &ref = *pp;
    //cout << ref << endl; // Segmentation Fault (SIGSEGV)

    // 6. 
    fun3() = 30; // reference to local variable.
    //cout << fun3() << endl; // Segmentation Fault (SIGSEGV)

    return 0;
}