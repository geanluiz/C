#include "leap.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    if (argc < 2)    
    {
        printf("Usage: ./leap <year>\n");
        return 1;
    }

    int y = atoi(argv[1]);

    char *result = (leap_year(y) == false)? "not leap": "leap";
    printf("%s\n", result);
}

bool leap_year(int year)
{
    if ((year % 100) == 0)
    {
        if ((year % 400) == 0)
        {
            return true;
        }
    }
    else if ((year % 4) == 0)
    {
        return true;
    }
    return false;
}