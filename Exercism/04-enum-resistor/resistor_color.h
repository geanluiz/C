#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_TABLE \
X(BLACK, "BLACK")   \
X(BROWN, "BROWN")   \
X(RED, "RED")       \
X(ORANGE, "ORANGE") \
X(YELLOW, "YELLOW") \
X(GREEN, "GREEN")   \
X(BLUE, "BLUE")     \
X(VIOLET, "VIOLET") \
X(GREY, "GREY")     \
X(WHITE, "WHITE")

#define X(a, b) a,
typedef enum {
    COLOR_TABLE
} resistor_band_t;
#undef X

#define X(a, b) a,
resistor_band_t color_num[] = {
  COLOR_TABLE
};
#undef X

#define X(a, b) b,
char *color_name[] = {
  COLOR_TABLE
};
#undef X

resistor_band_t colorName(char *name);

const resistor_band_t *colors();

resistor_band_t color_code(int color);
#endif