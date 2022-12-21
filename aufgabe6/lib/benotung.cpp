//
// Created by kevin on 01.12.2022.
//

#include "benotung.h"
#include <stdexcept>
#include <string>

void verify(int note)
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
            break;
        default:
            std::string message("unzulässige Note ");
            message += std::to_string(note);
            throw std::invalid_argument(message);
    }
}

benotung::benotung(int note) : note(note)
{
    verify(note);
}

const benotung benotung::beste(10);
const benotung benotung::schlechteste(50);

int benotung::int_value() const
{
    return this->note;
}

bool benotung::ist_bestanden() const
{
    return this->note <= 40;
}

bool operator==(const benotung& lhs, const benotung& rhs)
{
    return lhs.note == rhs.note;
}

benotung::benotung(int erste, int zweite) : note((erste + zweite) / 2)
{
    verify(erste);
    verify(zweite);
}

