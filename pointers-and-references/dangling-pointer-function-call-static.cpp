#include <stdio.h>

// function has static variable
int *fun() {
    // x is now has scope throughout the program
    static int x = 5;
    return &x;
}

int main() {
    int *p = fun();
    fflush(stdin);

    // No dangling pointer, has it points to to static variable
    printf("%p\n", p);
    printf("%d\n", *p);

    return 0;
}
