#include <iostream>
using namespace std;

template <class T, class U = char> // default value is "char" type
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
    Shop<char> ch; // This will call "Shop<char, char>"

    Shop<int> a; // This will call "Shop<int, char>"

    return 0;
}