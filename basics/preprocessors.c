
#include <stdio.h>

#define LIMIT (5U)
#define AREA(l,b) (l*b)

void func1();
void func2();

#pragma startup func1
#pragma exit func2

// If gcc, doesn't execute only with #pragma as above. then try with below code
void __attribute__((constructor)) func1();
void __attribute__((destructor)) func2();



void func1()
{
    printf("Start of the main function\n");
}
void func2()
{
    printf("Exit of the main function\n");
}

int main()
{
    void func1();
    void func2();
    for (int i = 0; i < LIMIT; i++)
    {
        printf(" %d", i);
    }
    printf("\n");
    int area = AREA(10,20);
    printf("Area: %d\n",area);

#undef LIMIT

    return 0;
}
