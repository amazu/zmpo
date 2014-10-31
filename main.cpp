#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include "Liczba_dwojkowa.h"

using namespace std;

int main() {
    try {
        Liczba_dwojkowa l(8);
        l.setWartosc("1010");
        Liczba_dwojkowa k(8);
        k.setWartosc("1110");

        k+=l;

        cout << "Wynik: " << k.getWartosc() << endl;

    } catch (runtime_error *e) {
        cout << e->what() << endl;
    }


    return 0;

}