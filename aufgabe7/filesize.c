//
// Created by kevin on 03.01.2023.
//

#define _POSIX_C_SOURCE 1

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <locale.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    if (argc > 1) // we have files here, get all their sizes
    {
        struct stat statbuff;

        for (int i = 1; i < argc; i++)
        {
            char *filePath = argv[i];

            if (stat(filePath, &statbuff) == -1)
            {
                perror(filePath);
                continue;
            }

            printf("%s: %jd bytes\n", filePath, (intmax_t) statbuff.st_size);
        }
    }
    else // read from stdin
    {
        uintmax_t n = 0;
        unsigned char byte;

        while (read(STDIN_FILENO, &byte, 1) == 1)
        {
            n++;
        }

        printf("stdin: %ju bytes\n", n);
        return 0;
    }
}
