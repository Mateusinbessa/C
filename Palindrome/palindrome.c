#include <stdio.h>

int main()
{
    int n, result = 0, q, remainder;
    printf("Please enter the number: \n");
    scanf("%d", &n);

    q = n;

    while (q != 0)
    {
        remainder = q % 10; // armazena o último dígito do numero
        result = result*10 + remainder; // forma de inverter o número
        q = q/10; // descarta o último dígito do numero
    }

    if (result == n)
    {
        printf("The number is a palindrome!\n");
    }
    else
    {
        printf("The number is not a palindrome!\n");
    }
    return 0;
}