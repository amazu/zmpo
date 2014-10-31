#include <iostream>
#include "punkt.h"
#include "okrag.h"

using namespace std;

int main() {
    Punkt sr(1,2);
    Okrag o(sr, 1);
    Punkt a(5,6);

    cout << o.odleglosc(a) << endl;

    return 0;
}