#include "Firma.h"
#include <iostream>
Firma::Firma(string nazev, string adresa)
{
    this->nazev = nazev;
    this->adresa = adresa;
}

string Firma::GetNazev()
{
    return this->nazev;
}

string Firma::GetAdresa()
{
    return this->adresa;
}

void Firma::Print()
{
    cout << "Nazev: " << nazev << "\nAdresa: " << adresa << endl;
}

