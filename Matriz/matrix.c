#include <stdio.h>

int main()
{
    int i, j;

    // matrix 2x2
    printf("Matriz de 2x2\n");
    for (i = 1; i <= 2; i++)
    {
        for (j = 1; j <= 2; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    // o 4 presente na condicional vai representar o número de rows e columns!
    // PRIMEIRO FOR: ROW
    // SEGUNDO FOR: COLUMN

    printf("Matriz de 4x4\n");
    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 4; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
