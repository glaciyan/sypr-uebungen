#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubblesort(void *a, size_t ac, size_t size, int (*comp)(const void *, const void *));

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Aufruf: %s Anzahl\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 1)
    {
        printf("Anzahl muss mindestens 1 sein");
        return 1;
    }

    // char **a = (char **)malloc(sizeof(char *) * (size_t)n);

    srand((unsigned int)time(NULL));

    int m = strlen(argv[1]) + 1;
    int totalLenght = 0;
    char *str = (char *)calloc(n, m);
    if (str == NULL)
    {
        return 1;
    }

    printf("Unsortiertes Array:\n");
    for (int i = 0; i < n; ++i)
    {
        int r = rand() % n;
        totalLenght += sprintf(str + i * m, "%d", r);
        printf("%s ", str + i * m);
    }
    totalLenght += n; // spaces + null
    printf("\n");

    bubblesort(str, n, m, (int (*)(const void *, const void *))strcmp);

    char *output = (char *)malloc(totalLenght);
    if (output == NULL)
    {
        return 1;
    }
    strcpy(output, str);

    for (int i = 1; i < n; ++i)
    {
        if (strcmp(str + i * m, str + (i - 1) * m) == 0)
        {
            strcat(output, "*");
        }
        else
        {
            strcat(output, " ");
            strcat(output, str + i * m);
        }
    }
    printf("Sortiertes Array:\n");
    printf("%s\n", output);
    free(output);
    free(str);
}

void bubblesort(void *a, size_t ac, size_t size, int (*comp)(const void *, const void *))
{
    char *tmp = (char *)malloc(size);
    for (int i = ac; i > 1; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            // if (a[j] > a[j + 1])
            char *element = (char *)a + j * size;
            char *next = element + size;
            if (comp(element, next) > 0)
            {
                memcpy(tmp, next, size);
                memcpy(next, element, size);
                memcpy(element, tmp, size);
            }
        }
    }
    free(tmp);
}