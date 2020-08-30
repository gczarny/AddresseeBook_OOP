#ifndef UZYTKOWNIKMANAGER_H
#define UZYTKOWNIKMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class UzytkownikManager
{
    vector <Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika;
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    UzytkownikManager(string nazwaPliku)
    : plikZUzytkownikami(nazwaPliku)
    {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };

    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    bool czyUzytkownikJestZalogowany();
    void wylogowanieUzytkownika();
};

#endif
