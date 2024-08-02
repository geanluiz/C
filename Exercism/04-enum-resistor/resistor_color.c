#include "resistor_color.h"
#include <stdio.h>

int main ()
{
    const resistor_band_t *colors();

    resistor_band_t color_code(int color);
}

const resistor_band_t p[10] = {
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
    };

const resistor_band_t *colors()
{
    return &p[0];
}

resistor_band_t color_code(int color)
{
    resistor_band_t col = color;
    return col;
}