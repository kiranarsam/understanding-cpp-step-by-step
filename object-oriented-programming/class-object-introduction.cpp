#include <iostream>
using namespace std;

class Test
{
    public: // access specifier
        string name;
        int id;

        void printId();
        void print() {
            cout << "NAME => " << name << endl;
        }
};

void Test::printId() {
    cout << "ID ==> " << id << endl;
}

int main()
{
    Test t;
    t.name = "testcase1";
    t.id = 46;
    t.print();
    t.printId();

    return 0;
}
