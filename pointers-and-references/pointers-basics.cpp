#include <stdio.h>

int main() {
    int x = 10;
    int *ptr; // ptr is pointer to an integer type variable
    int v[3] = {10, 100, 200};

    printf("Address = %p\n", &x); // prints address of x

    ptr = &x; // & operator used, to get address of variable x, and assigned to ptr

    printf("Address ptr = %p, value *ptr = %d \n", ptr, *ptr);

    *ptr = 20;

    printf("Address ptr = %p, value *ptr = %d, x = %d \n", ptr, *ptr, x);

    ptr = v;

    for(int i = 0; i < 3; i++) {
        printf("value of *ptr = %d, ptr = %p \n", *ptr, ptr);
        ptr++; // Increment pointer by 1
    }

    ptr = v;

    printf("Elements of array: %d, %d, %d\n", ptr[0], ptr[1], ptr[2]);

    return 0;
}