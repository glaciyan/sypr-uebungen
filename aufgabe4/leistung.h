#ifndef LEISTUNG_H
#define LEISTUNG_H

#include "stdbool.h"

#define MAX_MODULE_NAME_LEN 21

enum leistungsart
{
    unbenotet,
    benotet,
};

struct leistung
{
    char *modulName;
    enum leistungsart typ;
    union
    {
        int note;
        char beurteilung;
    };
};

typedef struct leistung leistung;

bool leistung_einlesen(leistung *);

void ausgeben(leistung *);

void dispose_leistung(leistung *leistung);

#endif
