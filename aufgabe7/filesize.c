//
// Created by kevin on 03.01.2023.
//

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <locale.h>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    if (argc > 1) // we have files here, get all their sizes
    {
        for (int i = 1; i < argc; i++)
        {
            char *filePath = argv[i];
            struct stat statbuff;

            if (stat(filePath, &statbuff) == -1)
            {
                perror(filePath);
                continue;
            }

            printf("%s: %ld bytes\n", filePath, statbuff.st_size);
        }
    }
    else // read from stdin
    {
        int n = 0;
        unsigned char byte;

        while (read(STDIN_FILENO, &byte, 1) > 0)
        {
            n++;
        }

        printf("stdin: %d bytes\n", n);
        return 0;
    }
}
