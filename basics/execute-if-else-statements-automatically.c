
#include <stdio.h>

int main()
{
    if(1) { // Replace 1 with 0, check the magic
        label_1:
            printf("Test the ");
        goto label_2;
    }
    else
    {
        goto label_1;

        label_2:
            printf("code.");
    }

    printf("\n");    

    return 0;
}