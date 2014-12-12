#include "CScene.h"




CObject * CScene::getObject(int nr) {
    return &(obiekty[nr]);
}

void CScene::addOject(const CObject &x) {
    obiekty.push_back(x);

}

void CScene::removeObject(int nr) {
    obiekty.erase(obiekty.begin() + nr);

}

vector<CollidingObjects> CScene::kolidujace() const {
    vector<CollidingObjects> oneKolidujomWykrzyknik;
    for (const CObject &o1 : obiekty) {
        for (const CObject &o2 : obiekty) {
            if(o1.isColliding(&o2)) oneKolidujomWykrzyknik.push_back(CollidingObjects(o1, o2));
        }
    }
}
