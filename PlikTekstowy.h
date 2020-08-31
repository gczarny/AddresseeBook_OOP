#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H
#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy
{
    const string NAZWA_PLIKU;
    const string NAZWA_PLIKU_TYMCZASOWEGO;

public:
    PlikTekstowy(string nazwaPliku)
    : NAZWA_PLIKU(nazwaPliku){}

    PlikTekstowy(string nazwaPliku, string nazwaPlikuTymczasowego)
    : NAZWA_PLIKU(nazwaPliku),
      NAZWA_PLIKU_TYMCZASOWEGO(nazwaPlikuTymczasowego)
    {};

    string pobierzNazwePliku();
    string pobierzNazwePlikuTymczasowego();
    bool czyPlikJestPusty();
    bool czyPlikTymczasowyJestPusty();
};

#endif
