#include <iostream>
using namespace std;

// A generic smart point class
template <class Type>
class SmartPtr {
    private:
        Type *ptr; // Actual pointer
    public:
        // Constructor
        explicit SmartPtr(Type *p = NULL) : ptr(p) {
            cout << "SmartPtr Constructor Called " << endl;
        }

        ~SmartPtr() {
            delete (ptr);
            cout << "SmartPtr Destructor Called " << endl;
        }

        // Overloading dereferencing operator
        Type& operator * () {
            return *ptr;
        }

        // Overloading arrow operator so that members of Type can be accessed like a pointer 
        // if Type represents a class or struct or union type
        Type* operator -> () {
            return ptr;
        }
};

int main() {
    SmartPtr<int> ptr (new int());

    *ptr = 30;

    cout << *ptr << endl;

    return 0;
}