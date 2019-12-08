#include <stdio.h>

// The pointer pointing to local variables becomes dangling when local variables is not static
int *fun() {
    // x is a local variable and goes out of scope after an execution of fun() is over
    int x = 5;
    return &x;
}

int main() {
    int *p = fun();
    fflush(stdin);

    // p points to something which is not valid anymore
    printf("%p\n", p);
    printf("%d\n", *p); // This will give segmentation fault (core dumped)

    return 0;
}
