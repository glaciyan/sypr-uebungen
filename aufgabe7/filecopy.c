//
// Created by kevin on 03.01.2023.
//

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

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

    if (read(srcFd, buff, statbuff.st_size) == -1) {
        perror(argv[1]);
        free(buff);
        close(srcFd);
        close(destFd);
        return -1;
    }

    if (write(destFd, buff, statbuff.st_size) == -1) {
        perror(argv[2]);
        free(buff);
        close(srcFd);
        close(destFd);
        return -1;
    }

    free(buff);
    close(srcFd);
    close(destFd);
}