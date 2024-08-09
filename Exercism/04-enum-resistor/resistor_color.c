#include "resistor_color.h"

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./resistor_color <COLOR>");
        return 1;
    }

    char *userInput = argv[1];

	resistor_band_t color = colorName(userInput);

	//const resistor_band_t *colors();

    
    printf("The color number is %i\n", color_code(color));
}

resistor_band_t colorName(char *name)
{
	if (strcmp(name, "BLACK") == 0)
		return BLACK;
	if (strcmp(name, "BROWN") == 0)
		return BROWN;
	if (strcmp(name, "RED") == 0)
		return RED;
	if (strcmp(name, "ORANGE") == 0)
		return ORANGE;
	if (strcmp(name, "YELLOW") == 0)
		return YELLOW;
	if (strcmp(name, "GREEN") == 0)
		return GREEN;
	if (strcmp(name, "BLUE") == 0)
		return BLUE;
	if (strcmp(name, "VIOLET") == 0)
		return VIOLET;
	if (strcmp(name, "GREY") == 0)
		return GREY;
	if (strcmp(name, "WHITE") == 0)
		return WHITE;
}

const resistor_band_t p[10] = {
	BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};

const resistor_band_t *colors() // Returns all colors to the test that checks if enum is correct
{
    return &p[0];
}

resistor_band_t color_code(int color)
{
    resistor_band_t col = color;
    return col;
}

/* #include <stdio.h>

#define COLOR_TABLE \
X(red, "red")       \
X(green, "green")   \
X(blue, "blue")

#define X(a, b) a,
enum COLOR {
  COLOR_TABLE
};
#undef X

#define X(a, b) b,
char *color_name[] = {
  COLOR_TABLE
};
#undef X

int main() {
  enum COLOR c = red;
  printf("c=%s\n", color_name[c]);
  return 0;
} */