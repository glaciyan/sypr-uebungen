//
// Created by kevin on 03.01.2023.
//

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Es braucht 2 dateien.\n");
        fprintf(stderr, "Verwendung:\n");
        fprintf(stderr, "%s Quelle Ziel", argv[0]);
        return -1;
    }

    int srcFd = open(argv[1], O_RDONLY);
    if (srcFd == -1)
    {
        perror(argv[1]);
        return -1;
    }

    struct stat statbuff;
    if (fstat(srcFd, &statbuff) == -1)
    {
        perror(argv[1]);
        close(srcFd);
        return -1;
    }

    int destFd = open(argv[2], O_CREAT | O_WRONLY);
    if (destFd == -1)
    {
        perror(argv[2]);
        close(srcFd);
        return -1;
    }

    char *buff = (char *) malloc(statbuff.st_size);
    if (buff == NULL)
    {
        fprintf(stderr, "malloc wollte nicht\n");
        close(srcFd);
        close(destFd);
        return -1;
    }

    intmax_t readRes = read(srcFd, buff, statbuff.st_size);

    if (readRes < statbuff.st_size)
    {
        free(buff);
        close(srcFd);
        close(destFd);

        if (readRes == -1)
        {
            perror(argv[1]);
            return -1;
        }
        else
        {
            fprintf(stderr, "%s: Konnte nicht die ganze Datei lesen", argv[1]);
            return -1;
        }
    }

    intmax_t writeRes = write(destFd, buff, statbuff.st_size);

    if (writeRes < statbuff.st_size)
    {
        free(buff);
        close(srcFd);
        close(destFd);

        if (writeRes == -1)
        {
            perror(argv[2]);
            return -1;
        }
        else
        {
            fprintf(stderr, "%s: Konnte nicht die ganze Datei schreiben", argv[2]);
            return -1;
        }
    }

    free(buff);
    close(srcFd);
    close(destFd);
}
