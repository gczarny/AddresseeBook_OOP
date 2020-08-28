#include <iostream>
#include <conio.h>

#include "UzytkownikManager.h"
#include "AdresatManager.h"


using namespace std;

class KsiazkaAdresowa
{
    UzytkownikManager uzytkownikManager;
    AdresatManager *adresatManager;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikManager(nazwaPlikuZUzytkownikami),
      NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        adresatManager = NULL;
    };
    ~KsiazkaAdresowa()
    {
        delete adresatManager;
        adresatManager = NULL;
    };

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    int logowanieUzytkownika();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wylogowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();
};
