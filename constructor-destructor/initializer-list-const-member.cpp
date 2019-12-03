#include <iostream>
using namespace std;

class Test {
    private:
        const int x;
    public:
        Test(int t) : x(t) {

        }

        int getX() { return x; }
};

int main() {
    Test t(10);
    cout << "x = " << t.getX() << endl;
    return 0;
}