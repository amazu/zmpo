#ifndef OKRAG_H
#define OKRAG_H

#include "punkt.h"

class Okrag {
public:
    Okrag(Punkt srodek, double promien): sr(srodek), r(promien) {};

    double odleglosc(Punkt p);
private:
    Punkt sr;
    double r;
};

#endif