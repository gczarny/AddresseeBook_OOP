#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikManager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikManager.logowanieUzytkownika();
    if(uzytkownikManager.czyUzytkownikJestZalogowany())
    {
        adresatManager = new AdresatManager(NAZWA_PLIKU_Z_ADRESATAMI, NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikManager.wylogowanieUzytkownika();
    //~KsiazkaAdresowa();
    delete adresatManager;
    adresatManager = NULL;
}

void KsiazkaAdresowa::dodajAdresata()
{
    if(uzytkownikManager.czyUzytkownikJestZalogowany())
        adresatManager->dodajAdresata(); // -> poniewaz pracujemy na wskazniku

    else
    {
        cout << "Aby dodac adresata, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    if(uzytkownikManager.czyUzytkownikJestZalogowany())
        adresatManager->wyswietlWszystkichAdresatow(); //

    else
    {
        cout << "Aby zobaczyc adresatow, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    if(uzytkownikManager.czyUzytkownikJestZalogowany())
        return true;
    else
        return false;
}

void KsiazkaAdresowa::usunWybranegoAdresata()
{
    if(uzytkownikManager.czyUzytkownikJestZalogowany())
        adresatManager->usunWybranegoAdresata();

    else
    {
        cout << "Aby usunac adresatow, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }

}

void KsiazkaAdresowa::edytujWybranegoAdresata()
{
    if(uzytkownikManager.czyUzytkownikJestZalogowany())
        adresatManager->edytujAdresata();

    else
    {
        cout << "Aby edytowac adresatow, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }

}
