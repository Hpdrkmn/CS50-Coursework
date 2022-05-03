#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //arg count checker
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    //open file
    FILE *input_file = fopen(argv[1], "r");

    // Check if valid
    if (input_file == NULL)
    {
        printf("Could not open file.");
        return 2;
    }

    //512 bytes
    unsigned char buffer[512];

    //number of images
    int count_image = 0;

    //pointer
    FILE *output_file = NULL;

    //char files
    char *filename = malloc(8 * sizeof(char));

    //read blocks
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        //do bytes start jpeg?
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //filename
            sprintf(filename, "%03i.jpg", count_image);

            //output
            output_file = fopen(filename, "w");

            //count images found
            count_image++;
        }
        //check if input is valid
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}