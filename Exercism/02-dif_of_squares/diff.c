#include "diff.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    if (argc < 2)    
    {
        printf("Usage: ./diff <number>\n");
        return 1;
    }

    int n = atoi(argv[1]);

    unsigned int result = difference_of_squares(n);
    printf("%i\n", result);
}

unsigned int sum_of_squares(unsigned int number)
{
    unsigned int sum = 0;
    for (unsigned int i = 1; i <= number; i++)
    {
        sum = sum + (i * i);
    }
    return sum;
}

unsigned int square_of_sum(unsigned int number)
{
    unsigned int sum = 0;
    for (unsigned int i = 1; i <= number; i++)
    {
        sum = sum + i;
    }
    return (sum * sum );
}

unsigned int difference_of_squares(unsigned int number)
{
    return square_of_sum(number) - sum_of_squares(number);
}