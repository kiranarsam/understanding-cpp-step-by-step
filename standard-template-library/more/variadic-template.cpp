#include <iostream>
using namespace std;

void print() {
    cout << "Its empty function and called at last." << endl;
}

// Variadic function template that takes variable number of arguments 
// and prints all of them
template <typename T, typename... Types>
void print(T var1, Types... var2 ) {
    cout << var1 << endl;

    print(var2...);
}

int main() {
    print(1, 2, 3.14, "Pass any number", "i will print all of them");

    return 0;
}

/*

The variadic templates work as follows :
The statement, print(1, 2, 3.14, "Pass any number", "i will print all of them"); 
is evaluated in following manner :
Firstly, the compiler resolves the statement into

cout<< 1 <<endl ;
print(2, 3.14, "Pass any number", "i will print all of them");
Now, the compiler finds a print() function which can take those arguments 
and in result executes the variadic print() function again in similar manner :

cout<< 2 <<endl ;
print(3.14, "Pass any number", "i will print all of them");
Again, it is resolved into the following forms :
(*)

cout<< 3.14 <<endl ;
print("Pass any number", "i will print all of them");
(*)

cout<< "Pass any number" <<endl ;
print(i will print all of them");
(*)

cout<< "i will print all of them" <<endl ;
print();
Now, at this point the compiler searches for a function overload whose match 
is the empty function i.e. the function which has no argument.

This means that, all functions that have 1 or more arguments are matched 
to the variadic template and all functions that with no argument are matched 
to the empty function.


*/