#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, row, column, space;
    // int prompt between 1 - 8
    do
    {
        height = get_int("Enter Height here: ");
    }
    while (height < 1 || height > 8);

    // row height outer loop
    for (row = 0; row < height; row++)
    {
        //spaces loop
        for (space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        //column width inner loop
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}