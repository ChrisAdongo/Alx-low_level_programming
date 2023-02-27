#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random passwords for 101-crackme.
 * Return: 0 on success.
 */
int main(void)
{
        int sum = 0;
        char c;

        srand(time(NULL));
        for (sum = 0; sum <= 2645; sum += c)
        {
                c = rand() % 128;
                putchar(c);
        }
        putchar(2772 - sum);

        return (0);
}
