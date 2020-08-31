#include <iostream>
#include "PlikTekstowy.h"

using namespace std;

string PlikTekstowy::pobierzNazwePliku()
{
    return NAZWA_PLIKU;
}

string PlikTekstowy::pobierzNazwePlikuTymczasowego()
{
    return NAZWA_PLIKU_TYMCZASOWEGO;
}


bool PlikTekstowy::czyPlikJestPusty()
{
    bool pusty = true;
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() != 0)
            pusty = false;
    }

    plikTekstowy.close();
    return pusty;
}

bool PlikTekstowy::czyPlikTymczasowyJestPusty()
{
    bool pusty = true;
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePlikuTymczasowego().c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() != 0)
            pusty = false;
    }

    plikTekstowy.close();
    return pusty;
}

