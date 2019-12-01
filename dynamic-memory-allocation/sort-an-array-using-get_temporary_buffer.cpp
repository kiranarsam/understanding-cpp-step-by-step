
#include <iostream>
#include <algorithm>
#include <memory>

#include <string.h>

using namespace std;

void sorting(int b[], int n)
{
    int i, c = 0;
    for(i = 0; i < n; i++) {
        if(b[i] % 2 == 0) {
            c++;
        }
    }
    cout << "Total even numbers are: " << c << endl;
    cout << "Original array: ";
    for (i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";

    pair<int*, ptrdiff_t> p = get_temporary_buffer<int>(10);

    //copy the contents in temporary buffer with pair
    uninitialized_copy(b, b + p.second, p.first);

    sort(p.first, p.first + p.second);
    cout << "sorted array: ";
    for(i = 0; i < p.second; i++) {
        cout << p.first[i] << " ";
    }
    cout << endl;
}

//Sort the characters
void sortingStringCharacters(char b[], int n) 
{ 
    int i; 
    pair<char*, ptrdiff_t> p = get_temporary_buffer<char>(n); 
  
    // copy the contents in temporary buffer with pair 
    uninitialized_copy(b, b + p.second, p.first); 
  
    // sort char array 
    sort(p.first, p.first + p.second); 
  
    cout << "sorted characters are :" << endl; 
    for (i = 0; i < p.second; i++) { 
        cout << p.first[i] << " "; 
    } 
  
    // to release the temporary buffer 
    return_temporary_buffer(p.first); 
} 

int main() {
    int b[] = { 8, 9, 2, 1, 10, 14, 3, 67, 8, 46};
    int n = sizeof(b)/sizeof(b[0]);
    sorting(b, n);

    char str[] = { 'b', 'g', 'y', 'v', 'p'};
    int c;
    c = strlen(str);
    sortingStringCharacters(str, c);
    
    return 0;
}