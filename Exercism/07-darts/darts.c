#include "darts.h"
#include <math.h>

uint8_t score(coordinate_t position)
{    
    if (d(position) > 10)
        return 0;
    else if (d(position) > 5 && d(position) <= 10)
        return 1;
    else if (d(position) > 1 && d(position) <= 5)
        return 5;
    else
        return 10;
}

float d(coordinate_t position)
{
    double x_square = pow((position.x - 0), 2.0);
    double y_square = pow((position.y - 0), 2.0);
    float d_root = sqrt(x_square + y_square);
    
    return d_root;
}