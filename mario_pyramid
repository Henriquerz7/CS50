// In the mario program, the goal is to create a pyramid in C, albeit in text, using hashes (#) for bricks. And let’s allow the user to decide just how tall the pyramids should be by
// first prompting them for a positive integer between, say, 1 and 8, inclusive.

#include <cs50.h>
#include <stdio.h>

int get_height(void);

int main(void)
{
    int height = get_height();
    for(int a = 0; a < height; a++) // lines or height of the pyramide
    {
        for(int b = 0; b < height -a -1; b++) // spaces before the first hashes ("#") in each line
        printf(" ");

        for(int c = 0; c < a + 1; c++) // first hashes ("#") in each line
        printf("#");
        
        printf(" "); // center space

        for(int e = 0; e < a + 1; e++) // second hashes ("#") in each line
        printf("#");

        printf("\n");
    }
}

int get_height(void) // input receiver by user about how high will it be the pyramide
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}
