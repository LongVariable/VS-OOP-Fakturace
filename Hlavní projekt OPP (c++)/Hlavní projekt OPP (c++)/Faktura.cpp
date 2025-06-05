#include "Faktura.h"
#include <iostream>


int Faktura::objectCount = 0; //Třida v roli objektu
double Faktura::globalDopravne = 100.0;

Faktura::Faktura(int cF, Date dV, Date dS)
{
    this->cisloFaktury = cF;
    this->datumVystaveni = dV;
    this->datumSplatnosti = dS;
    this->poznamka = "";
    this->dopravne = 0.0;
    this->cenaCelkem = 0.0;
    this->zaplaceno = false;
    this->uhrazenaCastka = 0.0;
    this->odberatel = nullptr;
    this->dodavatel = nullptr;

    Faktura::objectCount += 1;
}

Faktura::Faktura(int cF, Date dV, Date dS, string poznamka)
{
    this->cisloFaktury = cF;
    this->datumVystaveni = dV;
    this->datumSplatnosti = dS;
    this->cenaCelkem = 0.0;
    this->poznamka = poznamka;
    this->dopravne = 0.0;
    this->zaplaceno = false;
    this->uhrazenaCastka = 0.0;
    this->odberatel = nullptr;
    this->dodavatel = nullptr;

    Faktura::objectCount += 1;
}

Faktura::Faktura(int cF, Date dV, Date dS, string poznamka, double dopravne)
{
    this->cisloFaktury = cF;
    this->datumVystaveni = dV;
    this->datumSplatnosti = dS;
    this->cenaCelkem = 0.0;
    this->poznamka = poznamka;
    this->dopravne = dopravne;
    this->zaplaceno = false;
    this->uhrazenaCastka = 0.0;
    this->odberatel = nullptr;
    this->dodavatel = nullptr;

    Faktura::objectCount += 1;
}

Faktura::Faktura(int cF, Date dV, Date dS, double cenaCelkem)
{
    this->cisloFaktury = cF;
    this->datumVystaveni = dV;
    this->datumSplatnosti = dS;
    this->cenaCelkem = cenaCelkem;
    this->poznamka = "";
    this->dopravne = 0;
    this->zaplaceno = false;
    this->uhrazenaCastka = 0.0;
    this->odberatel = nullptr;
    this->dodavatel = nullptr;

    Faktura::objectCount += 1;
}

Faktura::Faktura(int cF, Date dV, Date dS, double cenaCelkem, double dopravne)
{
    this->cisloFaktury = cF;
    this->datumVystaveni = dV;
    this->datumSplatnosti = dS;
    this->cenaCelkem = cenaCelkem;
    this->poznamka = "";
    this->dopravne = dopravne;
    this->zaplaceno = false;
    this->uhrazenaCastka = 0.0;
    this->odberatel = nullptr;
    this->dodavatel = nullptr;

    Faktura::objectCount += 1;
}

Faktura::Faktura(int cF, Date dV, Date dS, double cenaCelkem, string poznamka)
{
    this->cisloFaktury = cF;
    this->datumVystaveni = dV;
    this->datumSplatnosti = dS;
    this->cenaCelkem = cenaCelkem;
    this->poznamka = poznamka;
    this->dopravne = 0.0;
    this->zaplaceno = false;
    this->uhrazenaCastka = 0.0;
    this->odberatel = nullptr;
    this->dodavatel = nullptr;

    Faktura::objectCount += 1;
}

Faktura::Faktura(int cF, Date dV, Date dS, double cenaCelkem, string poznamka, double dopravne)
{
    this->cisloFaktury = cF;
    this->datumVystaveni = dV;
    this->datumSplatnosti = dS;
    this->cenaCelkem = cenaCelkem;
    this->poznamka = poznamka;
    this->dopravne = dopravne;
    this->zaplaceno = false;
    this->uhrazenaCastka = 0.0;
    this->odberatel = nullptr;
    this->dodavatel = nullptr;

    Faktura::objectCount += 1;
}

Faktura::~Faktura()
{
    Faktura::objectCount -= 1;
}

double Faktura::GetCenaCelkem()
{
    return this->cenaCelkem;
}

double Faktura::GetDopravne()
{
    return this->dopravne;
}

double Faktura::GetZaplacenaCastka()
{
    return this->uhrazenaCastka;

}

int Faktura::GetCisloFaktury()
{
    return this->cisloFaktury;
}

Dodavatel* Faktura::GetDodavatel()
{
    return this->dodavatel;
}

Odberatel* Faktura::GetOdberatel()
{
    return this->odberatel;
}

void Faktura::PridejPolozku(PolozkaFaktury polozka)
{
    polozky.push_back(polozka);
    double cenaPolozky = polozka.GetCenaZaKus() * polozka.GetMnozstvi();
    double cenaSDPH = cenaPolozky + (cenaPolozky * (polozka.GetDPH() / 100.0));
    this->cenaCelkem += cenaSDPH;
    cout << "Polozka " << polozka.GetNazev() << " byla pridana do faktury "<< GetCisloFaktury() << "." << endl;
}

void Faktura::VypocetCelkoveCeny()
{
    this->cenaCelkem = this->cenaCelkem + this->dopravne;
}

void Faktura::PrintFaktura()
{
    cout << "-----------------------------" << endl;
    cout << "Faktura c.: " << this->cisloFaktury << endl;
    cout << "Datum vystaveni: " << datumVystaveni.den << "/" << datumVystaveni.mesic << "/" << datumVystaveni.rok <<endl;
    cout << "Datum splatnosti: " << datumSplatnosti.den << "/" << datumSplatnosti.mesic << "/" << datumSplatnosti.rok << endl;

    if (this->polozky.size() > 0)
    {
        cout << "Polozky ve fakture:" << endl;
        for (size_t i = 0; i < this->polozky.size(); i++)
        {
            this->polozky[i].PrintPolozkaFaktury();
        }
    }

    if (this->odberatel != nullptr)
    {
        cout << "Odberatel: " << this->odberatel->GetNazev() << endl;
    }
    else
    {
        cout << "Odberatel neni prirazen." << endl;
    }

    if (this->dodavatel != nullptr)
    {
        cout << "Dodavatel: " << this->dodavatel->GetNazev() << endl;
    }
    else
    {
        cout << "Dodavatel neni prirazen." << endl;
    }
    

    cout << "Cena celkem bez dopravy: " << this->cenaCelkem << " Kc" << endl;
    cout << "Dopravne: " << this->dopravne << " Kc" <<endl;
    VypocetCelkoveCeny();
    cout << "Cena celkem s dopravou: " << this->cenaCelkem << " Kc" <<endl;

    if (!this->poznamka.empty())
    {
        cout << "Poznamka: " << this->poznamka << endl;
    }
    cout << "-----------------------------" << endl;
}

void Faktura::PriradPlatbu(Platba& platba)
{
    this->uhrazenaCastka += platba.GetCastka();
    if (VypocetZbyvajiciCastky() <= 0)
    {
        OznacJakoZaplacene();
    }
}

void Faktura::OznacJakoZaplacene()
{
    this->zaplaceno = true;
}

double Faktura::VypocetZbyvajiciCastky()
{
    return cenaCelkem + dopravne - uhrazenaCastka;
}

bool Faktura::JeZaplaceno()
{
    return (this->uhrazenaCastka >= this->cenaCelkem);
}

void Faktura::PridatOdberatele(Odberatel* odberatel)
{
    this->odberatel = odberatel;
}

void Faktura::PridatDodavatele(Dodavatel* dodavatel)
{
    this->dodavatel = dodavatel;
}

//Třida v roli objektu
int Faktura::GetObjectCount()
{
    return Faktura::objectCount;
}

double Faktura::GetGlobalDopravne()
{
    return Faktura::globalDopravne;
}

void Faktura::SetGlobalDopravne(double dopravne)
{
    Faktura::globalDopravne = dopravne;
}