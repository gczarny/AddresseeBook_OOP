#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

KsiazkaAdresowa::KsiazkaAdresowa()
{
    uzytkownikManager.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikManager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}
