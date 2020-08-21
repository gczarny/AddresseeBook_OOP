#include <iostream>
#include <vector>

#include "Uzytkownik.h"


using namespace std;

class KsiazkaAdresowa
{
    vector <Uzytkownik> uzytkownicy;
    //vector <Adresat> adresaci;
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

public:
    void rejestracjaUzytkownika();

};
