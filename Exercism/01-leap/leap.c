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
    return (((year % 100) == 0) && ((year % 400) == 0)) || ((year % 4) == 0);
}