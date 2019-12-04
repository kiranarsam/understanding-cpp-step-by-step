#include <iostream>
using namespace std;

class Overload {
    private:
        int count;
    public:
        Overload() : count(4) {

        }

        void operator++() {
            count = count + 1;
        }

        void display() {
            cout << "Count = " << count << endl;
        }
};

int main() {
    Overload i;

    // This calls function "void operator++()"
    ++i;
    i.display();

    return 0;
}

/*
This function is called when ++ operator operates on the object of 
overload class (object i in this case). In the program, 
void operator ++ () operator function is defined (inside overload class). 
This function increments the value of count by 1 for i object.
*/