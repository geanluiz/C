#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
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
} resistor_band_t;

resistor_band_t colorName(char *name);

const resistor_band_t *colors();

resistor_band_t color_code(int color);
#endif