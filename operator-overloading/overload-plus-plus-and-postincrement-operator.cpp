#include <iostream>
using namespace std;

class Overload {
    private:
        int count;
    public:
        Overload(int i) : count(i) {

        }

        Overload operator++(int) {
            return (count++);
        }

        Overload operator++() {
            count = count + 1;
            return count;
        }

        void display() {
            cout << "Count = " << count << endl;
        }
};

int main() {
    Overload i(5);
    Overload post(5);
    Overload pre(5);

    // this calls "Overload operator++()" function
    pre = ++i;
    cout << "Result of i obj: ";
    i.display();
    cout << "Result of pre increment: ";
    pre.display();

    // this calls "Overload operator++(int)" function
    i++;
    i++;

    post = i++;
    cout << "Result of post increment: ";
    post.display();
    cout << "Result of i, Here we see difference: ";
    i.display();

    return 0;
}