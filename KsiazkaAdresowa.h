#include <iostream>
#include <conio.h>

#include "UzytkownikManager.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikManager uzytkownikManager;

public:
    int idZalogowanegoUzytkownika;

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikManager(nazwaPlikuZUzytkownikami){
        uzytkownikManager.wczytajUzytkownikowZPliku();
        idZalogowanegoUzytkownika = 0;
    };

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);
    int logowanieUzytkownika();
};
