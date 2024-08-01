#include "grains.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./grains <square Nth>");
        return 1;
    }

    int n = atoi(argv[1]);

    printf("%ld\n", square(n));
    printf("%ld\n", total());
}

uint64_t square(uint8_t index)
{
    return (index == 1)? 1 : (square(index - 1) * 2);
}

uint64_t total(void)
{
    uint64_t sum = 0;
    for (uint8_t i = 1; i < 64; i++)
    {
        sum = sum + square(i);
    }
    return sum;
}