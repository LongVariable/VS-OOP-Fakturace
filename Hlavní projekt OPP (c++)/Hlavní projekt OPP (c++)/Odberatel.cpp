#include "Odberatel.h"
#include <iostream>

Odberatel::Odberatel(string ico, string nazev, string adresa, string kontaktRodic, string kontaktOdberatel, double sleva, bool pravidelnyZakaznik) : ObchodniPartner(ico, nazev, adresa, kontaktRodic)
{
    this->kontakt = kontaktOdberatel; // shadowing 
    this->sleva = sleva;
    this->pravidelnyZakaznik = pravidelnyZakaznik;
}

double Odberatel::GetSleva()
{
    return this->sleva;
}

bool Odberatel::JePravidelnyZakaznik()
{
    return this->pravidelnyZakaznik;
}

void Odberatel::NastavSlevu(double sleva)
{
    this->sleva = sleva;
}

string Odberatel::GetTyp()
{
    return "Odberatel";
}

void Odberatel::Print()
{
    cout << "Odberatel: " << this->nazev
        << ", ICO: " << this->ico
        << ", Adresa: " << this->adresa
        << ", Kontakt: " << this->kontakt
        << ", Sleva: " << this->sleva << "%"
        << ", Pravidelny zakaznik: " << (this->pravidelnyZakaznik ? "Ano" : "Ne")
        << endl;
}

