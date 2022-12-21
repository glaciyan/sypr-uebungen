//
// Created by kevin on 01.12.2022.
//

#ifndef AUFGABE5_FACHNOTE_H
#define AUFGABE5_FACHNOTE_H

#include <string>
#include "benotung.h"

class fachnote
{
public:
    const std::string fach;
    const benotung note;

    fachnote(const std::string&, const benotung&);

    fachnote(const fachnote&) = delete;
    fachnote& operator=(const fachnote&) = delete;
    fachnote(fachnote&&) = delete;
    fachnote& operator=(fachnote&&) = delete;
};


#endif //AUFGABE5_FACHNOTE_H
