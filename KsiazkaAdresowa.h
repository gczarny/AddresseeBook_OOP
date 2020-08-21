#include <iostream>
#include <vector>
#include <windows.h>

#include "Uzytkownik.h"


using namespace std;

class KsiazkaAdresowa
{
    vector <Uzytkownik> uzytkownicy;
    //vector <Adresat> adresaci;
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};
