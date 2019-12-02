#include <iostream>

using namespace std;

class Encapsulation {
    private:
        int x; // data is hidden from outside the world
    public:
        Encapsulation(){
            x = 0;
        }

        void set(int a) {
            x = a;
        }

        int get() {
            return x;
        }
};

int main() {
    Encapsulation obj;

    obj.set(5);
    cout << obj.get() << endl;
    return 0;
}