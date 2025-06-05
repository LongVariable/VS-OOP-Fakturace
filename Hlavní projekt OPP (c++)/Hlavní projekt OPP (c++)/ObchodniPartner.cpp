#include "ObchodniPartner.h"
#include <iostream>

ObchodniPartner::ObchodniPartner(string ico, string nazev,  string adresa, string kontakt) : Firma(nazev, adresa)
{
    this->ico = ico;
    this->kontakt = kontakt;
}

string ObchodniPartner::GetIco()
{
    return this->ico;
}

string ObchodniPartner::GetKontakt()
{
    return this->kontakt;
}

void ObchodniPartner::Print()
{
    Firma::Print();
    cout << "ICO: " << ico << "\nKontakt: " << kontakt << endl;
}