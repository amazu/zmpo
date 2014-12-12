#ifndef CSHAPES_H
#define CSHAPES_H

#include <utility>
//#include <bits/stl_bvector.h>

using namespace std;
typedef pair<double, double> CWektor;
typedef pair<double, double> CPunkt;

struct CollisionUtils;

class CShape {
public:
    virtual bool isColliding(const CShape *x) const = 0;
    virtual void shift(const CWektor x) = 0;
    virtual void rotate(const double radian) = 0;

};

class CBaseTriangle : public CShape {
public:
    virtual bool isColliding(const CShape *x) const;

    virtual void shift(const CWektor x);
    virtual void rotate(const double radian);
    CBaseTriangle(CPunkt _a, CPunkt _b, CPunkt _c) : a(_a), b(_b), c(_c) {}
private:
    CPunkt a, b, c;
    friend struct CollisionUtils;

};

class CBaseCircle : public CShape {
public:
    virtual bool isColliding(const CShape *x) const;

    virtual void shift(const CWektor x);
    virtual void rotate(const double radian);
    CBaseCircle(CPunkt _sr, double _r) : sr(_sr), r(_r) {}
private:
    CPunkt sr;
    double r;
    friend struct CollisionUtils;

};

class CBaseRect : public CShape {
public:

    virtual bool isColliding(const CShape *x) const;

    virtual void shift(const CWektor x);
    virtual void rotate(const double radian);
    CBaseRect(CPunkt _a,CPunkt _b, CPunkt _c, CPunkt _d) : a(_a), b(_b), c(_c), d(_d) {}
private:
    CPunkt a, b, c, d;

    friend struct CollisionUtils;
};

//class CBaseWielokat : public CShape {
//public:
//    virtual bool isColliding(const CShape *x) const;
//    virtual void shift(const CWektor x);
//    virtual void rotate(const double radian);
//    CBaseWielokat(const int _liczbaWierzcholkow, CPunkt _srodek, double _r, vector<CPunkt> _wierzcholki)
//            : liczbaWierzcholkow(_liczbaWierzcholkow), srodek(_srodek), r(_r), wierzcholki(_wierzcholki) {};
//    vector<CPunkt> dajWierzcholki(CPunkt srodek, double promien, int ilosc);
//
//
//private:
//    int liczbaWierzcholkow;
//    CPunkt srodek;
//    double r;
//    vector<CPunkt> wierzcholki;
//    friend struct CollisionUtils;
//};

struct CollisionUtils {
    static bool isColliding(const CBaseCircle *c1, const CBaseCircle *c2);
    static bool isColliding(const CBaseCircle *c, const CBaseTriangle *t);
    static bool isColliding(const CBaseCircle *c, const CBaseRect *r);
    static bool isColliding(const CBaseTriangle *t1, const CBaseTriangle *t2);
    static bool isColliding(const CBaseTriangle *t, const CBaseRect *r);
    static bool isColliding(const CBaseRect *r1, const CBaseRect *r2);
};


CPunkt przesun(CPunkt p, CWektor w);
CPunkt obroc(CPunkt p, double rad);
double liczOdlegloscMiedzyPunktami(CPunkt x, CPunkt y);
pair<double, double> dajWzorProstej(CPunkt x1, CPunkt x2);
double odlegloscOdProstej(CPunkt x, pair<double, double> prostaa);
//CPunkt dajPunkt(CPunkt srodek, double promien);
//CWektor dajWektor(CPunkt srodek, CPunkt wierzcholek);

#endif