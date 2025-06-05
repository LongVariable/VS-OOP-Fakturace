#include "PolozkaFaktury.h"
#include <iostream>

PolozkaFaktury::PolozkaFaktury(string nazev, int mnozstvi, double DPH, double cenaZaKus)
{
    this->nazev = nazev;
    this->mnozstvi = mnozstvi;
    this->DPH = DPH;
    this->cenaZaKus = cenaZaKus;
    VypocetCenyCelkem();
}

void PolozkaFaktury::VypocetCenyCelkem()
{
    this->cenaCelkem = this->mnozstvi * this->cenaZaKus * (1 + this->DPH / 100);
}

string PolozkaFaktury::GetNazev()
{
    return this->nazev;
}

int PolozkaFaktury::GetMnozstvi()
{
    return this->mnozstvi;
}

double PolozkaFaktury::GetDPH()
{
    return this->DPH;   
}

double PolozkaFaktury::GetCenaZaKus()
{
    return this->cenaZaKus;
}

double PolozkaFaktury::GetCenaCelkem()
{
    return this->cenaCelkem;
}

void PolozkaFaktury::PrintPolozkaFaktury()
{
    cout << "Nazev: " << this->nazev << ", Mnozstvi: " << this->mnozstvi << ", Cena za kus: " << this->cenaZaKus << " Kc, DPH: " << this->DPH << "%, Cena celkem: " << this->cenaCelkem << " Kc" << endl;
}