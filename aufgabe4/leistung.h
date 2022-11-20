#ifndef LEISTUNG_H
#define LEISTUNG_H

#include "stdbool.h"

#define MAX_MODULE_NAME_LEN 20

enum leistungsart
{
    unbenotet,
    benotet,
};

struct leistung
{
    char *modulName; // 8 byte
    enum leistungsart typ; // 4 byte
    union // 4 byte
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
