#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    char wybor;

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt", "Adresaci_tymczasowi.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    while(true){
        if(ksiazkaAdresowa.czyUzytkownikJestZalogowany() == false)
        {
            system("cls");
            cout << "    >>> MENU  GLOWNE <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Koniec programu" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            wybor = getch();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            system("cls");
            cout << "    >>> MENU  UZYTKOWNIKA <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Zmiana hasla" << endl;
            cout << "2. Dodaj adresata" << endl;
            cout << "3. Wypisz wszystkich adresatow na ekran" << endl;
            cout << "4. Usun adresata" << endl;
            cout << "9. Wyloguj" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            wybor = getch();
            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '3':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '4':
                ksiazkaAdresowa.usunWybranegoAdresata();
                break;
            case '9':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            }
        }
    }
    return 0;
}
