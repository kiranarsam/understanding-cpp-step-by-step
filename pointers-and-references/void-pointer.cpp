#include <stdio.h>

int main() {
    int x = 4;
    float y = 5.5;

    // void pointer
    void *ptr;
    ptr = &x;

    // (int*)ptr = does type casting to void 
    // *((int*)ptr) = derefernces the typecasted void pointer variables
    printf("Integer variable is = %d\n", *((int*)ptr));

    // void pointer now float
    ptr = &y;
    printf("Integer variable is = %f\n", *((float*)ptr));

    return 0;
}