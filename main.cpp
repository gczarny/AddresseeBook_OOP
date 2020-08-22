#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    char wybor;

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");

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
            //wybor = wybierzOpcjeZMenuGlownego();
            wybor = getch();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
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
            cout << "1. Wypisz wszystkich na ekran" << endl;
            cout << "2. Zmiana hasla" << endl;
            cout << "8. Wyloguj" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            wybor = getch();
            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
                break;
            case '2':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(ksiazkaAdresowa.idZalogowanegoUzytkownika);
                break;
            case '8':
                ksiazkaAdresowa.idZalogowanegoUzytkownika = 0;
                //adresaci.clear();
                break;
            }
        }
    }
    return 0;
}
