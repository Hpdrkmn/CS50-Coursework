#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{

//promt user for text input
    string text = get_string("Enter Text Here: \n");

//count the number of letters
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }

    }
    printf("\n");

    //count the number of words
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }

    }

    //count the number of sentences
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;

        }
    }

    //grade level index
    float calculation = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;
    int index = round(calculation);

    // if text is less than 1
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    // if text is greater than 16
    else if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        //print grade number based on index
        printf("Grade %i\n", index);
    }
}