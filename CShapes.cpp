#include <cmath>
#include <iostream>
#include "CShapes.h"

bool CBaseTriangle::isColliding(const CShape *x) const {
    if(const CBaseCircle *c = dynamic_cast<const CBaseCircle*>(x)) {
        return CollisionUtils::isColliding(c, this);
    } else if(const CBaseTriangle *t = dynamic_cast<const CBaseTriangle*>(x)) {
        return CollisionUtils::isColliding(this, t);
    } else if(const CBaseRect *r = dynamic_cast<const CBaseRect*>(x)) {
        return CollisionUtils::isColliding(this, r);
    } else
        return false;
}

void CBaseTriangle::shift(const CWektor x) {
    a = przesun(a, x);
    b = przesun(b, x);
    c = przesun(c, x);
}

void CBaseTriangle::rotate(const double radian) {
    a = obroc(a, radian);
    b = obroc(b, radian);
    c = obroc(c, radian);

}

// ---------------------------------------------------------

bool CBaseCircle::isColliding(const CShape *x) const {
    if(const CBaseCircle *c = dynamic_cast<const CBaseCircle*>(x)) {
        return CollisionUtils::isColliding(this, c);
    } else if(const CBaseTriangle *t = dynamic_cast<const CBaseTriangle*>(x)) {
        return CollisionUtils::isColliding(this, t);
    } else if(const CBaseRect *r = dynamic_cast<const CBaseRect*>(x)) {
        return CollisionUtils::isColliding(this, r);
    } else
        return false;
}

void CBaseCircle::shift(const CWektor x) {
    sr = przesun(sr, x);

}

void CBaseCircle::rotate(const double radian) {
    sr = obroc(sr, radian);

}

// ---------------------------------------------------------

bool CBaseRect::isColliding(const CShape *x) const {
    if(const CBaseCircle *c = dynamic_cast<const CBaseCircle*>(x)) {
        return CollisionUtils::isColliding(c, this);
    } else if(const CBaseTriangle *t = dynamic_cast<const CBaseTriangle*>(x)) {
        return CollisionUtils::isColliding(t, this);
    } else if(const CBaseRect *r = dynamic_cast<const CBaseRect*>(x)) {
        return CollisionUtils::isColliding(this, r);
    } else
        return false;
}

void CBaseRect::shift(const CWektor x) {
    a = przesun(a, x);
    b = przesun(b, x);
    c = przesun(c, x);
    d = przesun(d, x);


}

void CBaseRect::rotate(const double radian) {
    a = obroc(a, radian);
    b = obroc(b, radian);
    c = obroc(c, radian);
    d = obroc(d, radian);

}

// ---------------------------------------------------------

CPunkt przesun(CPunkt p, CWektor w) {
    double x = p.first + w.first;
    double y = p.second + w.second;


    return CPunkt(x, y);
}

CPunkt obroc(CPunkt p, double rad) {
    double s = sin(rad);
    double c = cos(rad);

    // rotate point
    double xnew = p.first * c - p.second * s;
    double ynew = p.first * s + p.second * c;

    return CPunkt(xnew, ynew);

}

double liczOdlegloscMiedzyPunktami(CPunkt x, CPunkt y) {
    return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}

bool CollisionUtils::isColliding(const CBaseCircle *c1, const CBaseCircle *c2) {
    return liczOdlegloscMiedzyPunktami(c1->sr, c2->sr) >= (c1->r + c2->r);
}

bool CollisionUtils::isColliding(const CBaseCircle *c, const CBaseTriangle *t) {
    pair<double, double> prosta;
    prosta = dajWzorProstej(t->a, t->b);

    if(odlegloscOdProstej(c->sr, prosta) <= c->r) return true;

    prosta = dajWzorProstej(t->b, t->c);
    if(odlegloscOdProstej(c->sr, prosta) <= c->r) return true;

    prosta = dajWzorProstej(t->c, t->a);
    if(odlegloscOdProstej(c->sr, prosta) <= c->r) return true;

    return false;
}

bool CollisionUtils::isColliding(const CBaseCircle *c, const CBaseRect *r) {
    pair<double, double> prosta;
    prosta = dajWzorProstej(r->a, r->b);

    if(odlegloscOdProstej(c->sr, prosta) <= c->r) return true;

    prosta = dajWzorProstej(r->b, r->c);
    if(odlegloscOdProstej(c->sr, prosta) <= c->r) return true;

    prosta = dajWzorProstej(r->c, r->d);
    if(odlegloscOdProstej(c->sr, prosta) <= c->r) return true;

    prosta = dajWzorProstej(r->d, r->a);
    if(odlegloscOdProstej(c->sr, prosta) <= c->r) return true;

    return false;
}

bool CollisionUtils::isColliding(const CBaseTriangle *t1, const CBaseTriangle *t2) {
    double minxT1 = min(min(t1->a.first, t1->b.first), t1->c.first);
    double minxT2 = min(min(t2->a.first, t2->b.first), t2->c.first);

    double maxxT1 = max(max(t1->a.first, t1->b.first), t1->c.first);
    double maxxT2 = max(max(t2->a.first, t2->b.first), t2->c.first);


    double minyT1 = min(min(t1->a.second, t1->b.second), t1->c.second);
    double minyT2 = min(min(t2->a.second, t2->b.second), t2->c.second);

    double maxyT1 = max(max(t1->a.second, t1->b.second), t1->c.second);
    double maxyT2 = max(max(t2->a.second, t2->b.second), t2->c.second);


    bool cond1 = (minxT1 < minxT2) ? minxT1 <= maxxT2 && minxT2 <= maxxT1 : minxT2 <= maxxT1 && minxT1 <= maxxT2;
    bool cond2 = (minyT1 < minyT2) ? minyT1 <= maxyT2 && minyT2 <= maxyT1 : minyT2 <= maxyT1 && minyT1 <= maxyT2;

    return cond1 && cond2;
}

bool CollisionUtils::isColliding(const CBaseTriangle *t, const CBaseRect *r) {

    double minxT1 = min(min(t->a.first, t->b.first), t->c.first);
    double minxT2 = min(min(min(r->a.first, r->b.first), r->c.first), r->d.first);

    double maxxT1 = max(max(t->a.first, t->b.first), t->c.first);
    double maxxT2 = max(max(max(r->a.first, r->b.first), r->c.first), r->d.first);


    double minyT1 = min(min(t->a.second, t->b.second), t->c.second);
    double minyT2 = min(min(min(r->a.second, r->b.second), r->c.second), r->d.second);

    double maxyT1 = max(max(t->a.second, t->b.second), t->c.second);
    double maxyT2 = max(max(max(r->a.second, r->b.second), r->c.second), r->d.second);


    bool cond1 = (minxT1 < minxT2) ? minxT1 <= maxxT2 && minxT2 <= maxxT1 : minxT2 <= maxxT1 && minxT1 <= maxxT2;
    bool cond2 = (minyT1 < minyT2) ? minyT1 <= maxyT2 && minyT2 <= maxyT1 : minyT2 <= maxyT1 && minyT1 <= maxyT2;

    return cond1 && cond2;



}

bool CollisionUtils::isColliding(const CBaseRect *r1, const CBaseRect *r2) {

    double minxT1 = min(min(min(r1->a.first, r1->b.first), r1->c.first), r1->d.first);
    double minxT2 = min(min(min(r2->a.first, r2->b.first), r2->c.first), r2->d.first);


    double maxxT1 = max(max(max(r1->a.first, r1->b.first), r1->c.first), r1->d.first);
    double maxxT2 = max(max(max(r2->a.first, r2->b.first), r2->c.first), r2->d.first);


    double minyT1 = min(min(min(r1->a.second, r1->b.second), r1->c.second), r1->d.second);
    double minyT2 = min(min(min(r2->a.second, r2->b.second), r2->c.second), r2->d.second);

    double maxyT1 = max(max(max(r1->a.second, r1->b.second), r1->c.second), r1->d.second);
    double maxyT2 = max(max(max(r2->a.second, r2->b.second), r2->c.second), r2->d.second);


    bool cond1 = (minxT1 < minxT2) ? minxT1 <= maxxT2 && minxT2 <= maxxT1 : minxT2 <= maxxT1 && minxT1 <= maxxT2;
    bool cond2 = (minyT1 < minyT2) ? minyT1 <= maxyT2 && minyT2 <= maxyT1 : minyT2 <= maxyT1 && minyT1 <= maxyT2;

    return cond1 && cond2;
}

pair<double, double> dajWzorProstej(CPunkt x1, CPunkt x2) {
    double a = (x1.second - x2.second) / (x1.first - x2.first);
    double b = x1.second - a* x1.first;
    return pair<double, double>(a, b);
}

double odlegloscOdProstej(CPunkt x, pair<double, double> prostaa) {
    double odl = abs(prostaa.first*x.first - x.second + prostaa.second) / sqrt(prostaa.first* prostaa.first + 1);
    return odl;
}


// ---------------------------------------------------------
//
//bool CBaseWielokat::isColliding(const CShape *x) const {
//    return false;
//}
//
//void CBaseWielokat::shift(const CWektor x) {
//
//}
//
//void CBaseWielokat::rotate(const double radian) {
//
//}
//
//CPunkt dajPunkt(CPunkt srodek, double promien) {
//    double x1 = srodek.first + promien;
//    double x2 = srodek.second + promien;
//    return CPunkt(x1, x2);
//}
//
//
//CWektor dajWektor(CPunkt srodek, CPunkt wierzcholek) {
//    return CWektor(wierzcholek.first - srodek.first, wierzcholek.second- srodek.second);
//}
//
//vector<CPunkt> CBaseWielokat::dajWierzcholki(CPunkt srodek, double promien, int ilosc) {
//    for (int i = 0; i < ilosc, i++) {
//        CPunkt w1 = NULL;
//        w1 = dajPunkt(srodek, promien);
//        CWektor wek = NULL;
//        wek = dajWektor(srodek, w1);
//        wierzcholki.push_back(w1);
//        CPunkt w2 = NULL;
//        w2 = obroc(w1, 3.14 / ilosc);
//        wek = CWektor(w2.first - srodek.first, w2.second - srodek.second);
//        wierzcholki.push_back(w2);
//    }
//    return wierzcholki;
//
//}