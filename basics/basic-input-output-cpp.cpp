
#include <iostream>
using namespace std;

int main() {
    int num;
    //1. cout - standard ouput stream
    cout << "Enter integer:  " << endl;
    //2. cin - standard input stream
    cin >> num;
    //3. cerr - Un-buffered standard error stream
    cerr << "An error occurred " << endl;
    //4. clog - Buffered standard error stream
    clog << "An error again occurred" << endl;

    return 0;
}