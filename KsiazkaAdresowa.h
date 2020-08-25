#include <iostream>
#include <conio.h>

#include "UzytkownikManager.h"
#include "AdresatManager.h"


using namespace std;

class KsiazkaAdresowa
{
    UzytkownikManager uzytkownikManager;
    AdresatManager adresatManager;

public:
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikManager(nazwaPlikuZUzytkownikami),
      adresatManager(nazwaPlikuZAdresatami)
    {
        uzytkownikManager.wczytajUzytkownikowZPliku();
        idZalogowanegoUzytkownika = 0;
        idOstatniegoAdresata = 0;
    };

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);
    int logowanieUzytkownika();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wyswietlWszystkichAdresatow();
    void wylogowanie();
};
