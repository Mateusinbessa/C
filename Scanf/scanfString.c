#include <stdio.h>

#define MAX_INPUT_SIZE 256


void myScanf(int a, int *p)
{
    *p = a;
}

void readInput(char *buffer, int bufferSize)
{
    int i = 0;
    char c;

    while (i < bufferSize - 1) 
    {
        c = getchar();

        if (c == '\n' || c == EOF) {
            break;
        }

        buffer[i] = c;
        i++;
    }

    buffer[i] = '\0';
}

int main(void)
{
    char input[MAX_INPUT_SIZE];

    printf("Digite algo: ");

    readInput(input, sizeof(input));
    printf("Voce digitou: %s\n", input);

    return 0;
}