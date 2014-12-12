#ifndef COBJECT_H
#define COBJECT_H

#include <vector>
#include "CShapes.h"

using namespace std;


class CObject {
public:
    void addShape(CShape *x);
    void removeShape(int x);
    CShape* getShape(int nr);
    virtual bool isColliding(const CObject *x) const;
    virtual void shift(const CWektor x);
    virtual void rotate(const double radian);

private:
    vector<CShape*> ksztalty;
};


#endif