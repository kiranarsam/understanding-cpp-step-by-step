#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int x;
    int *ptr1 = &x;
    int *ptr2 = (int *)malloc(sizeof(int));
    int *ptr3 = new int;
    int *ptr4 = NULL;

    //delete ptr1; // don't use, because ptr1 is allocated from STACK

    free(ptr2); // delete ptr2; don't use, ptr2 is allocated with malloc()

    delete ptr3;

    delete ptr4;

    return 0;
}