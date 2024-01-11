#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check if there is only one input
    if (argc != 2)
    {
        printf("Usage: ./recover filename.raw\n");
        return 1;
    }

    // open memory card
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Could not open the file.\n");
        return 1;
    }

    // create a buffer to store the data
    uint8_t buffer[512];

    // repeat until end of card
    int i = 0;
    FILE *img = NULL;

    // read 512 bytes into a buffer
    while (fread(buffer, 1, 512, file) == 512)
    {
        // if start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", i);
            img = fopen(filename, "w");
            i++;
        }

        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    fclose(file);
    fclose(img);
}