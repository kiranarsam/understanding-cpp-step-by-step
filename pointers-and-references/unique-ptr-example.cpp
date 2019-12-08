#include <iostream>
#include <memory>

using namespace std;

class Shop {
    public:
        Shop() {
            cout << "Shop Consructor Called " << endl;
        }
        ~Shop() {
            cout << "Shop Destructor Called " << endl;
        }
        void show() {
            cout << "Shop::show() is invoked " << endl;
        }
};

int main() {
    unique_ptr<Shop> p1(new Shop);
    p1->show();

    //returns the memory address of p1
    cout << p1.get() << endl;

    // transfers ownership to p2
    unique_ptr<Shop> p2 = move(p1);
    p2->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;

    // transfers ownership to p3
    unique_ptr<Shop> p3 = move(p2);
    p3->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    cout << p3.get() << endl;

    return 0;
}