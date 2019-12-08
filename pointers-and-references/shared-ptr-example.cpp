#include <iostream>
#include <memory>
using namespace std;

class Shop {
    public:
        Shop() {
            cout << "Shop Constructor Called" << endl;
        }
        ~Shop() {
            cout << "Shop Destructor Called" << endl;
        }
        void display() {
            cout << "Shop::display() invoked" << endl;
        }
};

int main() {
    shared_ptr<Shop> p1(new Shop);
    cout << p1.get() << endl;
    p1->display();

    shared_ptr<Shop> p2(p1);
    p2->display();
    cout << p1.get() << endl;
    cout << p2.get() << endl;

    // Returns the number of shared_ptr objects
    // referring to the same managed object.
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;

    // Relinquishes owner of p1 on the object and pointer becomes NULL
    p1.reset();

    cout << p1.get() << endl;
    cout << p2.use_count() << endl;
    cout << p2.get() << endl;

    return 0;
}