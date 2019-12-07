#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<string> vect {"testthecode", "TestTheCode", "CodeTheTest"};

    for (const auto &x : vect) {
        cout << x << endl;
    }
    return 0;
}