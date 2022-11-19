#include "spo3_ain2.h"
#include "string.h"

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

static const char *mathe2 = "Mathematik 2";
static const char *prog2 = "Programmiertechnik 2";
static const char *rear = "Rechnerarchitekturen";
static const char *stoch = "Stochastik";
static const char *sypro = "Systemprogrammierung";

bool ist_ain2_modul(const char *modul)
{
    if (strcmp(modul, mathe2) == 0 || strcmp(modul, prog2) == 0 || strcmp(modul, rear) == 0 ||
        strcmp(modul, stoch) == 0 || strcmp(modul, sypro) == 0)
        return true;
    else
        return false;
}
