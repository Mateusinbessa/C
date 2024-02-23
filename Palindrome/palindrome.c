#include <stdio.h>

int main()
{
    int n, result = 0, q, remainder;
    printf("Please enter the number: \n");
    scanf("%d", &n);

    q = n;

    while (q != 0)
    {
        remainder = q % 10;
        result = result*10 + remainder;
        q = q/10;
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
