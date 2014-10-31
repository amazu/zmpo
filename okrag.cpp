#include <math.h>
#include "punkt.h"
#include "okrag.h"

double Okrag::odleglosc(Punkt p) {
    double wynik = sqrt((sr.x - p.x)*(sr.x-p.x) + (sr.y - p.y)*(sr.y-p.y));
    if(wynik >= r)
        return wynik - r;
    else
        return wynik;
}
