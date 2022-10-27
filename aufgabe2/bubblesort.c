#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Aufruf: %s Anzahl\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int *a = (int *)calloc((size_t)n, sizeof(int));

    printf("Bitte %d ganze Zahlen eingeben: ", n);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) < 1) {
            break;
        }
        k++;
    }

    srand((unsigned int)time(NULL));

    for (int i = k; i < n; i++)
    {
        a[i] = rand();
        printf("%d\n", a[i]);
    }

    for (int i = n; i > 1; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }

    printf("Sortierte Zahlenfolge: \n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }

    free(a);
    return 0;
}
