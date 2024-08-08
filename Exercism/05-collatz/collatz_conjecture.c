#include "collatz_conjecture.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./collatz <number>");
        return 1;
    }

    int start = atoi(argv[1]);
    printf("Total of %i steps for number %i\n", steps(start), start);
}

int steps(int start)
{
    int stepCount = 0;
    
    if (start == 1)
    {
         return 0;   
    }
    else if (start < 1)
    {
        return ERROR_VALUE;
    }
    do    
    {
        if ((start % 2) == 0)
        {
            start = (start / 2);
        }
        else
        {
            start = ((start * 3) + 1);
        }
        stepCount++;
    }while (start != 1); 
    return stepCount;
}