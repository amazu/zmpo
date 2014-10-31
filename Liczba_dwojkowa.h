#ifndef LICZBA_DWOJKOWA_H
#define LICZBA_DWOJKOWA_H

#include <string>
#include <stdint.h>

using namespace std;

class Liczba_dwojkowa {
public:
    Liczba_dwojkowa(int rozmiar);
    Liczba_dwojkowa(const Liczba_dwojkowa & l);
    ~Liczba_dwojkowa();

    void setWartosc(const string &s);
    string getWartosc();

    bool getBit(int ktory) const;
    void setBit(int ktory);
    void clearBit(int ktory);

    void dodawanie(const Liczba_dwojkowa &l);
    void odejmowanie(const Liczba_dwojkowa &l);
    void mnozenie(const Liczba_dwojkowa &l);
    void iloczyn(const Liczba_dwojkowa &l);
    void suma(const Liczba_dwojkowa &l);
    void negacja();

    Liczba_dwojkowa operator+(Liczba_dwojkowa &l);
    Liczba_dwojkowa operator-(Liczba_dwojkowa &l);
    Liczba_dwojkowa operator*(Liczba_dwojkowa &l);
    Liczba_dwojkowa &operator+=(Liczba_dwojkowa &l);
    Liczba_dwojkowa &operator-=(Liczba_dwojkowa &l);
    Liczba_dwojkowa &operator*=(Liczba_dwojkowa &l);



private:
    uint8_t *tab = nullptr;
    int rozmiarTab = 0;

};




#endif