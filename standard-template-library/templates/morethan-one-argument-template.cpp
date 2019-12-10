#include <iostream>
using namespace std;

template <class T, class U>
class Shop {
    private:
        T x;
        U y;
    public:
        Shop() {
            x = T();
            y = U();
            cout << "Constructor Called" << endl;
        }

        void display() {
            cout << "x = " << x << ", y = " << y << endl;
        }
};

int main() {
    Shop<char, char> ch;
    Shop<int, double> d;
    ch.display();
    d.display();

    return 0;
}