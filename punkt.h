#ifndef PUNKT_H
#define PUNKT_H

class Okrag;

class Punkt {
friend class Okrag;
public:
    Punkt(double pierwsza, double druga);


private:
    double x;
    double y;
};

#endif