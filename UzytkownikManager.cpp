#include <iostream>
#include "UzytkownikManager.h"


using namespace std;

void UzytkownikManager::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikManager::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    string login, haslo;
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo (haslo powinno skladac sie przynajmniej z 5 dowolnych znakow lub liczb): ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikManager::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikManager::czyIstniejeLogin(string login)
{
    for(int i = 0; i < uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikManager::wypiszWszystkichUzytkownikow()
{
    system("cls");
    if (!uzytkownicy.empty())
    {
        cout << "             >>> UZYTKOWNICY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < uzytkownicy.size(); i++)
        {
            cout << "Id:    " << uzytkownicy[i].pobierzId() << endl;
            cout << "Login: " << uzytkownicy[i].pobierzLogin() << endl;
            cout << "Haslo: " << uzytkownicy[i].pobierzHaslo() << endl;
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Nie ma uzytkownikow." << endl << endl;
    }
    system("pause");
}

int UzytkownikManager::logowanieUzytkownika()
{
    string login = "", haslo = "";
    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    for(int i = 0; i < uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin() == login)
        {
            for(int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if(uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return idZalogowanegoUzytkownika;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UzytkownikManager::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo (haslo powinno skladac sie przynajmniej z 5 dowolnych znakow lub liczb): ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    if(czyUzytkownikJestZalogowany())
    {
        for(int i = 0; i < uzytkownicy.size(); i++)
        {
            if(uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
            {
                uzytkownicy[i].ustawHaslo(noweHaslo);
                    cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
            }
        }
        plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
    }
    else
    {
        cout << "Aby zmienic haslo, nalezy sie zalogowac" << endl;
        system("pause");
    }
}

int UzytkownikManager::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

bool UzytkownikManager::czyUzytkownikJestZalogowany()
{
    if(idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

void UzytkownikManager::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
}
