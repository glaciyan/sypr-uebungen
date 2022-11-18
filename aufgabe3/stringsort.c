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

    char **a = (char **) malloc(sizeof(char *) * (size_t) n);
    if (a == NULL)
    {
        return 1;
    }

    srand((unsigned int) time(NULL));

    size_t m = strlen(argv[1]) + 1;
    int totalLength = 0;
    printf("Unsortiertes Array:\n");
    for (int i = 0; i < n; ++i)
    {
        int r = rand() % n;
        char *str = (char *) malloc(m);

        if (str == NULL)
        {
            return 1;
        }

        totalLength += sprintf(str, "%d", r);
        a[i] = str;
        printf("%s ", a[i]);
    }
    totalLength += n; // spaces + null
    printf("\n");

    bubblesort(n, a);

    char *output = (char *) malloc(totalLength);
    if (output == NULL)
    {
        return 1;
    }

    strcpy(output, a[0]);

    for (int i = 1; i < n; ++i)
    {
        if (strcmp(a[i], a[i - 1]) == 0)
        {
            strcat(output, "*");
        }
        else
        {
            strcat(output, " ");
            strcat(output, a[i]);
        }
    }
    printf("Sortiertes Array:\n");
    printf("%s\n", output);

    for (int i = 0; i < n; ++i)
    {
        free(a[i]);
    }
    free(a);
    free(output);
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
