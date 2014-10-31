
#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "Liczba_dwojkowa.h"

Liczba_dwojkowa::Liczba_dwojkowa(int rozmiar) {
    if (rozmiar % 8 != 0) {
        throw new runtime_error("Rozmiar nie jest wielokrotnoscia 8.");
    }
    tab = new uint8_t[rozmiar / 8];
    for (int i = 0; i < rozmiar / 8; i++)
        tab[i] = 0;
    rozmiarTab = rozmiar;

}

Liczba_dwojkowa::Liczba_dwojkowa(const Liczba_dwojkowa & l) {
    tab = new uint8_t[l.rozmiarTab / 8];
    for (int i = 0; i < l.rozmiarTab / 8; i++)
        tab[i] = l.tab[i];
    rozmiarTab = l.rozmiarTab;

}

Liczba_dwojkowa::~Liczba_dwojkowa() {
    delete[] tab;
}

bool Liczba_dwojkowa::getBit(int ktory) const {
    if (ktory >= rozmiarTab) return 0;
    return (tab[ktory / 8] & 1 << (ktory % 8)) != 0;
}

void Liczba_dwojkowa::setBit(int ktory) {
    if (ktory >= rozmiarTab) throw new runtime_error("Nie ma tylu bitów");
    tab[ktory / 8] |= 1 << (ktory % 8);
}

string Liczba_dwojkowa::getWartosc() {
    string s = "";
    for (int i = rozmiarTab - 1; i >= 0; i--) {
        if (getBit(i))
            s += "1";
        else
            s += "0";
    }
    return s;
}

void Liczba_dwojkowa::setWartosc(const string &s) {
    for (int i = 0; i < rozmiarTab; i++) {
        if (i >= s.length() || s[s.length() - 1 - i] == '0')
            clearBit(i);
        else if (s[s.length() - 1 - i] == '1')
            setBit(i);
        else
            throw new runtime_error("Niewłaściwy znak.");
    }
}

void Liczba_dwojkowa::clearBit(int ktory) {
    tab[ktory / 8] &= ~(1 << (ktory % 8));
}


void Liczba_dwojkowa::dodawanie(const Liczba_dwojkowa &l) {
    bool przeniesienie = 0;
    for (int i = 0; i < rozmiarTab; i++) {
        bool bitA = getBit(i);
        bool bitB = l.getBit(i);
        int suma = (int)bitA + (int)bitB + (int)przeniesienie;
        if (suma > 1)
            przeniesienie = 1;
        else
            przeniesienie = 0;

        if (suma == 1 || suma == 3)
            setBit(i);
        else
            clearBit(i);
    }

    if (przeniesienie) {
        throw new runtime_error("Przekroczony zakres.");
    }

}

void Liczba_dwojkowa::odejmowanie(const Liczba_dwojkowa &l) {
    bool pozyczenie = 0;
    for (int i = 0; i < rozmiarTab; i++) {
        bool bitA = getBit(i);
        bool bitB = l.getBit(i);
        int suma = (int)bitA - (int)bitB - (int) pozyczenie;
        switch(suma) {
            case 1:
                setBit(i);
                pozyczenie = 0;
                break;
            case 0:
                pozyczenie = 0;
                clearBit(i);
                break;
            case -1:
                setBit(i);
                pozyczenie = 1;
                break;
            case -2:
                pozyczenie = 1;
                clearBit(i);

            default:break;
        }
    }

    if (pozyczenie) {
        throw new runtime_error("Przekroczony zakres.");
    }


}

void Liczba_dwojkowa::mnozenie(const Liczba_dwojkowa &l) {
    Liczba_dwojkowa kopia(*this);
    setWartosc("0");
    bool przeniesienie = 0;
    for(int i = 0; i < kopia.rozmiarTab; i++) {
        przeniesienie = 0;
        if (kopia.getBit(i) == 1) {
            for (int j = 0; j < l.rozmiarTab; j++) {
                bool bitA = getBit(j + i);
                bool bitB = l.getBit(j);
                int suma = (int) bitA + (int) bitB + (int) przeniesienie;
                if (suma > 1)
                    przeniesienie = 1;
                else
                    przeniesienie = 0;

                if (suma == 1 || suma == 3)
                    setBit(j + i);
                else
                    clearBit(j + i);
            }
        }
    }
    if (przeniesienie) {
        throw new runtime_error("Przekroczony zakres.");
    }


}
void Liczba_dwojkowa::iloczyn(const Liczba_dwojkowa &l) {
    int koniec = max(rozmiarTab, l.rozmiarTab);;
    for(int i = 0; i < koniec; i++) {
        if (getBit(i) && l.getBit(i))
           setBit(i);
        else clearBit(i);
    }
}

void Liczba_dwojkowa::suma(const Liczba_dwojkowa &l) {
    int koniec = max(rozmiarTab, l.rozmiarTab);;
    for(int i = 0; i < koniec; i++) {
        if (getBit(i) || l.getBit(i))
            setBit(i);
        else clearBit(i);
    }
}

void Liczba_dwojkowa::negacja() {
    for(int i = 0; i < rozmiarTab; i++) {
        if (!getBit(i))
            setBit(i);
        else clearBit(i);
    }
}

Liczba_dwojkowa Liczba_dwojkowa::operator+(Liczba_dwojkowa &l) {
    Liczba_dwojkowa kopia(*this);
    kopia.dodawanie(l);
    return kopia;
}

Liczba_dwojkowa Liczba_dwojkowa::operator-(Liczba_dwojkowa &l) {
    Liczba_dwojkowa kopia(*this);
    kopia.odejmowanie(l);
    return kopia;
}

Liczba_dwojkowa Liczba_dwojkowa::operator*(Liczba_dwojkowa &l) {
    Liczba_dwojkowa kopia(*this);
    kopia.mnozenie(l);
    return kopia;
}


Liczba_dwojkowa& Liczba_dwojkowa::operator+=(Liczba_dwojkowa &l) {

    dodawanie(l);
    return *this;
}

Liczba_dwojkowa& Liczba_dwojkowa::operator-=(Liczba_dwojkowa &l) {

    odejmowanie(l);
    return *this;
}


Liczba_dwojkowa& Liczba_dwojkowa::operator*=(Liczba_dwojkowa &l) {

    mnozenie(l);
    return *this;
}

