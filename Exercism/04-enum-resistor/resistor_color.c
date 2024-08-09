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
    printf("The color number is %i\n", color_code(color));
}

resistor_band_t colorName(char *name)
{
	for (int i = 0; i < sizeof(color_num); i++)
	{
		if (strcmp(name, color_name[i]) == 0)
			return color_num[i];
	}
} 

const resistor_band_t *colors() // Returns all colors to the test that checks if enum is correct
{
    return &color_num[0];
}

resistor_band_t color_code(int color)
{
    resistor_band_t col = color;
    return col;
}