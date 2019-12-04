
#include <bits/stdc++.h>
using namespace std;

class GFG {
    public:
        int num;
        GFG(int j) : num (j) {

        }

        GFG* operator->(void) {
            return this;
        }
};

int main() {
    GFG obj(5);
    GFG *ptr = &obj;

    // Accessing num normally
    cout << "obj.num = " << obj.num << endl;

    // Accessing num using normal object pointer
    cout << "ptr->num = " << ptr->num << endl;

    // Accessing num using "->" operator
    cout << "obj->num = " << obj->num << endl;

    return 0;
}