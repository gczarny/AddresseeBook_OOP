#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    char wybor;

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    while(true){
        if (ksiazkaAdresowa.idZalogowanegoUzytkownika == 0)
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
                ksiazkaAdresowa.idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
                ksiazkaAdresowa.idOstatniegoAdresata = ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ksiazkaAdresowa.idZalogowanegoUzytkownika);
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
            cout << "id Ostatniego Adresata: " << ksiazkaAdresowa.idOstatniegoAdresata;
            cout << "    >>> MENU  UZYTKOWNIKA <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Zmiana hasla" << endl;
            cout << "2. Dodaj adresata" << endl;
            cout << "3. Wypisz wszystkich adresatow na ekran" << endl;
            cout << "9. Wyloguj" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            wybor = getch();
            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(ksiazkaAdresowa.idZalogowanegoUzytkownika);
                break;
            case '2':
                ksiazkaAdresowa.idOstatniegoAdresata = ksiazkaAdresowa.dodajAdresata(ksiazkaAdresowa.idZalogowanegoUzytkownika, ksiazkaAdresowa.idOstatniegoAdresata);
                break;
            case '3':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '9':
                ksiazkaAdresowa.wylogowanie();
                break;
            }
        }
    }
    return 0;
}
