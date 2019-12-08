#include <iostream>
#include <utility> // pair
using namespace std;

int main() {
    pair <int, char> id_pair;
    id_pair.first = 100;
    id_pair.second = 'K';
    
    cout << "first = " << id_pair.first << endl;
    cout << "second = " << id_pair.second << endl;

    pair <string, double> PAIR2("TestTheCode",  3.14);

    cout << "PAIR2.first: " << PAIR2.first << ", PAIR2.second: " << PAIR2.second << endl;

    pair<int, double> PAIR3;
    pair<string, char> PAIR4;

    cout << "PAIR3.first: " << PAIR3.first << ", PAIR3.second: " << PAIR3.second << endl;
    cout << "PAIR4.first: " << PAIR4.first << ", PAIR4.second: " << PAIR4.second << endl;

    // Another way of creating pair
    pair<string, string> PAIR5;
    PAIR5 = make_pair("CPP-Lang", "C-Lang");
    cout << "PAIR5.first: " << PAIR5.first << ", PAIR5.second: " << PAIR5.second << endl;

    // We can use operator on pairs such as ( ==, !=, >=, <=, >, <)
    pair<int, int>pair1 = make_pair(1, 12); 
    pair<int, int>pair2 = make_pair(9, 12); 
    cout << "(pair1 == pair2) = " << (pair1 == pair2) << endl;

    // Swap the pairs
    cout << "Before swap pair1: " << pair1.first << " and " << pair1.second << endl;
    cout << "Before swap pair2: " << pair2.first << " and " << pair2.second << endl;
    pair1.swap(pair2);
    cout << "After swap pair1: " << pair1.first << " and " << pair1.second << endl;
    cout << "After swap pair2: " << pair2.first << " and " << pair2.second << endl;

    return 0;
}
