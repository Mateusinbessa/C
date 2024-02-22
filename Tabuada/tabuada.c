#include <stdio.h>

int main()
{
    int i, j, result;

    for (i = 1; i <= 10; i++)
    {
        i == 1 ? printf("-----------------------------------------------\n") : 0;
        printf("Tabuada do %d\n\n", i);
        for (j = 1; j <= 10; j++)
        {
            result = i * j;
            printf("%d x %d = %d\n", i, j, result);
        }
        printf("-----------------------------------------------\n");
    }
}