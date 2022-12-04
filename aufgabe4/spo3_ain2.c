#include "spo3_ain2.h"
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

bool ist_spo_note(int note)
{
    switch (note)
    {
        case 10:
        case 13:
        case 17:
        case 20:
        case 23:
        case 27:
        case 30:
        case 33:
        case 37:
        case 40:
        case 50:
            return true;
        default:
            return false;
    }
}

bool ist_ain2_modul(const char *modul)
{
    static const char *faecher[] = {"Mathematik 2", "Programmiertechnik 2", "Rechnerarchitekturen", "Stochastik",
                                    "Systemprogrammierung", NULL};

    const char **q = faecher;
    while (*q != NULL)
    {
        if (strcmp(modul, *q) == 0) return true;
        q = q + 1;
    }

    return false;
}
