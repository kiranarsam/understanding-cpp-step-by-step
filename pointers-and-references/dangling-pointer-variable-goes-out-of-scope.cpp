#include <stdio.h>

int main() {
    int *ptr;

    {
        int ch;
        ptr = &ch;
    }

    // Here ptr, is an dangling pointer
    return 0;
}