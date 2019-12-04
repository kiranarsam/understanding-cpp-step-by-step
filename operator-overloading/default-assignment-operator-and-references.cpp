#include <iostream>
using namespace std;

class Test {
    private:
        int id;
        int &ref;
    public:
        Test(int i) : id(i), ref(id) { }
        
        void print() {
            cout << ref << endl;
        }
        void setId(int i) {
            id = i;
        }
        Test& operator=(const Test& t) {
            id = t.id;
            return *this;
        }
};

int main() {
    Test t1(10);
    Test t2(20);

    t2 = t1;

    t1.setId(40);
    t2.print();
    return 0;
}