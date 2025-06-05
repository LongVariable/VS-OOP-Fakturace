#include "Platba.h"
#include <iostream>
Platba::Platba(int cislo,Date datumPlatby, double castka, string typPlatby)
{
    this->cislo = cislo;
    this->datumPlatby = datumPlatby;
    this->castka = castka;
    this->typPlatby = typPlatby;
}

int Platba::GetCisloPlatby()
{
    return this->cislo;
}

Date Platba::GetDatumPlatby()
{
    return datumPlatby;
}

double Platba::GetCastka()
{
    return castka;
}

string Platba::GetTypPlatby()
{
    return typPlatby;
}

void Platba::PrintPlatba()
{
    cout <<"c.: "<< cislo << "\n" << "Datum platby: " << datumPlatby.den << "." << datumPlatby.mesic << "." << datumPlatby.rok << "\n" << "Castka: " << castka << " Kc\n" << "Typ platby: " << typPlatby << "\n";
}