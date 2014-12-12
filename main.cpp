#include <iostream>
#include "CShapes.h"
#include "CObject.h"


using namespace std;

int main() {
//    CBaseCircle kolo1(CPunkt(0,0), 2);
//    CBaseCircle kolo2(CPunkt(3,5), 3);
//    CBaseTriangle trojkat1(CPunkt(1,1), CPunkt(3,3), CPunkt(0,4));
//    CBaseTriangle trojkat2(CPunkt(4,2), CPunkt(6,2), CPunkt(5,4));
//    CBaseTriangle trojkat3(CPunkt(0,0), CPunkt(3,4), CPunkt(7,1));
//    CBaseRect prostokat1(CPunkt(4,1), CPunkt(4,4), CPunkt(10, 1), CPunkt(10, 4));
//    CBaseRect prostokat2(CPunkt(6,0), CPunkt(6,3), CPunkt(10,3), CPunkt(10, 0));
//    cout << kolo2.isColliding(&prostokat1) << endl;
//    cout << kolo1.isColliding(&kolo2) << endl;
//    CObject cobj;
//    cobj.addShape(&trojkat1);

    CBaseCircle kolo(CPunkt(0,-2), 2.0009);
    CBaseTriangle trojkat(CPunkt(0,0), CPunkt(2,0), CPunkt(0,2));
    cout << kolo.isColliding(&trojkat) << endl;



    return 0;
}