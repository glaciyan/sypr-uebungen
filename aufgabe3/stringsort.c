#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubblesort(int, char **);

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

    char **a = (char **)malloc(sizeof(char *) * (size_t)n);

    srand((unsigned int)time(NULL));

    printf("Unsortiertes Array:\n");
    for (int i = 0; i < n; ++i)
    {
        int r = rand() % n;
        char *str = (char *)malloc(12);
        sprintf(str, "%d", r);
        a[i] = str;
        printf("%s ", a[i]);
    }
    printf("\n");

    bubblesort(n, a);

    printf("Sortiertes Array:\n");
    printf("%s", a[0]);
    for (int i = 1; i < n; ++i)
    {
        if (strcmp(a[i], a[i - 1]) == 0)
        {
            printf("*");
        }
        else
        {
            printf(" %s", a[i]);
        }
    }
    printf("\n");

    for (int i = 0; i < n; ++i)
    {
        free(a[i]);
    }
    free(a);
}

void bubblesort(int ac, char **a)
{
    for (int i = ac; i > 1; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            // if (a[j] > a[j + 1])
            if (strcmp(a[j], a[j + 1]) > 0)
            {
                char *tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}