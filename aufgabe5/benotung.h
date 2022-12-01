//
// Created by kevin on 01.12.2022.
//

#ifndef AUFGABE5_BENOTUNG_H
#define AUFGABE5_BENOTUNG_H


class benotung
{
private:
    int note;


public:
    explicit benotung(int);

    const static benotung beste;
    const static benotung schlechteste;

    int int_value() const;

    bool ist_bestanden() const;

    friend bool operator==(const benotung&, const benotung&);
    // es werden noch move und copy constructor und operator= generiert, diese sind richtig da wir kein speicher verwalten
};


#endif //AUFGABE5_BENOTUNG_H
