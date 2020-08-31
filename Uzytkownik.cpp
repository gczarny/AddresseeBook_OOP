#include <iostream>
#include "Uzytkownik.h"

using namespace std;

void Uzytkownik::ustawId(int noweId)
{
    if(noweId >= 0)
        id = noweId;
}

void Uzytkownik::ustawLogin(string nowyLogin)
{
    login = nowyLogin;
}

void Uzytkownik::ustawHaslo(string noweHaslo)
{
    while(noweHaslo.length() <= 4)
    {
        cout << "Haslo powinno skladac sie przynajmniej z 5 dowolnych znakow lub liczb: ";
        cin >> noweHaslo;
    }
    haslo = noweHaslo;
}

int Uzytkownik::pobierzId()
{
    return id;
}

string Uzytkownik::pobierzLogin()
{
    return login;
}

string Uzytkownik::pobierzHaslo()
{
    return haslo;
}
