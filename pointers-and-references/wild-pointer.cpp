#include <stdio.h>

int main() {
    int *p; // Wild poiinter

    int x = 10;

    //p is not a wild pointer now
    p = &x;

    return 0;
}