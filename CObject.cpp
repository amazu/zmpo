#include "CObject.h"

void CObject::addShape(CShape *x) {
    ksztalty.push_back(x);

}

void CObject::removeShape(int x) {
    ksztalty.erase(ksztalty.begin() + x);
}

CShape *CObject::getShape(int nr) {
    return (ksztalty[nr]);
}

void CObject::shift(const CWektor x) {
    for (CShape *c : ksztalty) {
        c->shift(x);
    }

}

void CObject::rotate(const double radian) {
    for (CShape *c : ksztalty) {
        c->rotate(radian);
    }

}

bool CObject::isColliding(const CObject *x) const {
    for (const CShape *c1 : ksztalty) {
        for (const CShape *c2 : x->ksztalty) {
            if(c1->isColliding(c2)) return true;
        }

    }
    return false;
}
