#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubblesort(char **a, int ac)
{
    for (int i = ac; i > 1; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (strcmp(a[j], a[j + 1]) > 0)
            {
                char *tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

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

    srand((unsigned int) time(NULL));

    size_t m = strlen(argv[1]) + 1;
    int totalLength = 0;
    char *str = (char *) calloc(n, m);
    char **arr = (char **) calloc(n, sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = str + i * m;
    }

    if (str == NULL || arr == NULL)
    {
        return 1;
    }

    printf("Unsortiertes Array:\n");
    for (int i = 0; i < n; ++i)
    {
        int r = rand() % n;
        totalLength += sprintf(arr[i], "%d", r);
        printf("%s ", arr[i]);
    }
    totalLength += n; // spaces + null
    printf("\n");


    bubblesort(arr, n);

    char *output = (char *) malloc(totalLength);
    if (output == NULL)
    {
        return 1;
    }
    strcpy(output, arr[0]);

    for (int i = 1; i < n; ++i)
    {
        if (strcmp(arr[i], arr[i - 1]) == 0)
        {
            strcat(output, "*");
        }
        else
        {
            strcat(output, " ");
            strcat(output, arr[i]);
        }
    }

    printf("Sortiertes Array:\n");
    printf("%s\n", output);

    free(output);
    free(str);
    free(arr);
}
