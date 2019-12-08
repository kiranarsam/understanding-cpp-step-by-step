#include <stdlib.h>
#include <stdio.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));

    // After below free(ptr), ptr becomes a dangling pointer
    free(ptr);

    // IF we do, then no more dangling pointer
    ptr = NULL;

    return 0;
}