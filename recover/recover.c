#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//defining a constant blocksize of the size 512
const int blocksize = 512;
//defining a new type to store data
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    //Condition to see if the user input only 1 argmuent:
    if (argc != 2)
    {
        printf("Name of the file should contain only one word.\n");
        return 1;
    }

    //Condition to see if it was possible to open the file:
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Can't open file.\n");
        return 1;
    }

    //defining a BUFFER the size of the blocksize of 512 bytes
    BYTE buffer[blocksize];
    //declaring a filename size 8
    char filename[8];
    //creating a new file output and initially assinging NULL
    FILE *output = NULL;
    //defining a new variable that count images
    int img_count = 0;

    //reading byte after byte, until the end of 512 bytes
    while (fread(buffer, sizeof(BYTE), blocksize, file) == blocksize)
    {
        //conditions to see if the file contains a jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if it is the first image we find, write the the jpg to a new file and update the img_count by 1
            if (img_count == 0)
            {
                sprintf(filename, "%03i.jpg", img_count);

                output = fopen(filename, "w");

                fwrite(buffer, sizeof(BYTE), blocksize, output);

                img_count++;
            }
            //if it is not the first, we close the file and write a new file with the new jpg
            else if (img_count > 0)
            {
                fclose(output);

                sprintf(filename, "%03i.jpg", img_count);

                output = fopen(filename, "w");

                fwrite(buffer, sizeof(BYTE), blocksize, output);

                img_count++;
            }
        }
        // if the conditions of being one of 4 bytes of a jpg is not fullfilled, we keep writing the same to the same file
        else if (img_count > 0)
        {
            fwrite(buffer, sizeof(BYTE), blocksize, output);
        }
    }
    fclose(output);
    fclose(file);

}