#include <iostream>
#include <memory>
using namespace std;

class People {
    public:
        void show() {
            cout << "People::show()" << endl;
        }
};

int main() {
    auto_ptr<People> p1(new People);
    p1->show();

    // returns the memory address of p1
    cout << p1.get() << endl;

    // copy constructor called, this makes p1 empty
    auto_ptr<People> p2(p1);
    p2->show();

    // p1 is empty now 
    cout << p1.get() << endl;

    // p1 gets copied in p2
    cout << p2.get() << endl;

    return 0;
}
