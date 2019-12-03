#include <iostream>
using namespace std;

void test(float x, float y) {
    cout << "Function with float called " << endl;
}

void test(int x, int y) {
    cout << "Function with int called " << endl;
}

// Comment this overloaded function, to check the ambiguous
void test(double x, double y) {
    cout << "Function with double called " << endl;
}

int main() {
    // You have to suffic with format 'f' in float literals
    test(3.5f, 5.6f);   // call of overloaded 'test(double, double)' is ambiguous, 
                        // if you won't specifiy suffix 'f'

    test(5.2, 4.5);

    return 0;
}
