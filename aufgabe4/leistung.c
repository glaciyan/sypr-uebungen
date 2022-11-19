#include "leistung.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "spo3_ain2.h"

#define QUOTE(str) #str
#define PERCENT_QUOTE(num) QUOTE(%num)
#define MODUL_NAME_FORMAT (PERCENT_QUOTE(MAX_MODULE_NAME_LEN) "s")

bool leistung_einlesen(leistung *out)
{
    out->modulName = (char *) malloc(MAX_MODULE_NAME_LEN + 1);

    // modulName einlesen
    if (scanf(MODUL_NAME_FORMAT, out->modulName) <= 0)
    {
        dispose_leistung(out);
        return false;
    }
    char *underscore = strchr(out->modulName, (int) '_');
    if (underscore != NULL)
    {
        *underscore = ' ';
    }

    // note oder beurteilung einlesen
    if (scanf("%d", &out->note) > 0) // NOLINT(cert-err34-c)
    {
        out->typ = benotet;
        return true;
    }
    else if (scanf("%c", &out->beurteilung) > 0)
    {
        out->typ = unbenotet;
        return true;
    }
    else
    {
        dispose_leistung(out);
        return false;
    }
}

void ausgeben_unbenotet(char status)
{
    printf("\tS\t");
    if (status == 'B')
    {
        printf("bestanden");
    }
    else if (status == 'N')
    {
        printf("nicht bestanden");
    }
    else
    {
        printf("Fehler: %c", status);
    }
}

void ausgeben_benotet(int note)
{
    printf("\tL\t");
    if (!ist_spo_note(note))
    {
        printf("Fehler: %d", note);
    }
    else
    {
        printf("%d", note / 10);
        printf(",%d", note % 10);
    }
}

void ausgeben(leistung *leistung)
{
    if (!ist_ain2_modul(leistung->modulName))
    {
        printf("Fehler: %s\n", leistung->modulName);
        return;
    }

    printf("%-20s", leistung->modulName);
    if (leistung->typ == benotet)
    {
        ausgeben_benotet(leistung->note);
    }
    else if (leistung->typ == unbenotet)
    {
        ausgeben_unbenotet(leistung->beurteilung);
    }

    printf("\n");
}

void dispose_leistung(leistung *leistung)
{
    free(leistung->modulName);
    leistung->modulName = NULL;
}
