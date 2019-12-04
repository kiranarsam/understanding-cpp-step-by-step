
#include <iostream>
using namespace std;

class Overload {
    private:
        int list[3];
    public:
        Overload(int i, int j, int k) {
            list[0] = i;
            list[1] = j;
            list[2] = k;
        }

        int operator[](int i) {
            return list[i];
        }
};

int main() {
    Overload obj(10,20,30);

    cout << "obj[1] = " << obj[1] << endl; // Invokes "int operator[](int i)" function
    return 0;
}