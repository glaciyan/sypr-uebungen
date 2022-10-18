#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>

int main(void)
{
    printf("Anzahl bisher geschriebene C-Programme eingeben: ");
    int anzahl;
    if (scanf("%d", &anzahl))
    {
        if (errno == ERANGE) {
            printf("Zu gross\n");
            return 1;
        }

        printf("Vorname eingeben: ");
        /* const vorname[8]; */
        char *vorname = (char*) malloc(8);
        scanf("%7s", vorname);

        printf("%ss %d. C-Programm funktioniert!\n", vorname, anzahl + 1);

        free(vorname);
        return 0;
    }
}
