#include "Dodavatel.h"
#include <iostream>

Dodavatel::Dodavatel(string ico, string nazev, string adresa, string kontaktRodic, string kontaktDodavatel, string bankovniUcet, int dodaciLhuta) : ObchodniPartner(ico, nazev, adresa, kontaktRodic)
{
    this->kontakt = kontaktDodavatel; // shadowing
    this->bankovniUcet = bankovniUcet;
    this->dodaciLhuta = dodaciLhuta;
}

string Dodavatel::GetTyp()
{
    return "Dodavatel";
}

string Dodavatel::GetKontakt()
{
    return this->kontakt;
}

string Dodavatel::GetBankovniUcet()
{
    return this->bankovniUcet;
}

int Dodavatel::GetDodaciLhuta()
{
    return this->dodaciLhuta;
}

void Dodavatel::Print()
{
    cout << "Dodavatel: " << this->nazev
        << ", ICO: " << this->ico
        << ", Adresa: " << this->adresa
        << ", Kontakt: " << this->kontakt
        << ", Bankovni ucet: " << this->bankovniUcet
        << ", Dodaci lhuta: " << this->dodaciLhuta << " dni"
        << endl;
}

