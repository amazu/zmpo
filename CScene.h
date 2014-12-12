#ifndef CSCENE_H
#define CSCENE_H


#include "CObject.h"
typedef pair<CObject, CObject> CollidingObjects;
using namespace std;

class CScene {
public:
    void addOject(const CObject &x);
    void removeObject(int nr);
    CObject * getObject(int nr);
    vector<CollidingObjects> kolidujace() const;
private:
    vector<CObject> obiekty;

};


#endif