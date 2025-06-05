#include "Fakturace.h"
#include <iostream>

Fakturace::Fakturace(int faktury, int platby, int firmy)
{
    this->faktury = new Faktura* [faktury]();
    this->platby = new Platba * [platby]();
    this->firmy = new ObchodniPartner * [firmy]();

    this->pocetFaktur = 0;
    this->pocetPlateb = 0;
    this->pocetFirem = 0;
}

Fakturace::~Fakturace()
{
    for (int i = 0; i < pocetFaktur; ++i)
    {
        delete faktury[i];
    }
    pocetFaktur = 0;
    for (int i = 0; i < pocetPlateb; ++i)
    {
        delete platby[i];
    }
    pocetPlateb = 0;
    for (int i = 0; i < pocetFirem; ++i)
    {
        delete firmy[i];
    }
    pocetFirem = 0;

    delete[] faktury;
    delete[] platby;
    delete[] firmy;
}

void Fakturace::PridejFakturu(Faktura& faktura)
{
    faktury[pocetFaktur++] = &faktura;
}

void Fakturace::PridejPlatbu(Platba& platba)
{
    platby[pocetPlateb++] = &platba;
}

void Fakturace::PrintFaktury()
{
    for (int i = 0; i < pocetFaktur; ++i)
    {
        if (faktury[i] != nullptr)
        {
            faktury[i]->PrintFaktura();
        }
    }
}

void Fakturace::PrintPlatby()
{
    for (int i = 0; i < pocetPlateb; ++i)
    {
        if (platby[i] != nullptr)
        {
            platby[i]->PrintPlatba();
        }
    }
}

void Fakturace::PriradPlatbuKFakture(int cisloFaktury, Platba& platba)
{
    Faktura* faktura = nullptr;
    for (int i = 0; i < pocetFaktur; ++i)
    {
        if (faktury[i] != nullptr && faktury[i]->GetCisloFaktury() == cisloFaktury)
        {
            faktura = faktury[i];
            break;
        }
    }

    if (faktura == nullptr)
    {
        cout << "Neplatne cislo faktury." << endl;
        return;
    }

    faktura->PriradPlatbu(platba);

    if (faktura->GetZaplacenaCastka() >= faktura->GetCenaCelkem() + faktura->GetDopravne())
    {
        faktura->OznacJakoZaplacene();
        cout << "Faktura cislo " << cisloFaktury << " byla oznacena jako zaplacena." << endl;
    }
    else
    {
        cout << "Faktura cislo " << cisloFaktury << " je castecne zaplacena." << endl;
    }

    cout << "Platba byla pridana k fakture cislo " << cisloFaktury << "." << endl;
}

void Fakturace::VypisNezaplaceneFaktury()
{
    bool nalezeno = false;

    for (int i = 0; i < pocetFaktur; ++i)
    {
        if (faktury[i] != nullptr)
        {
            double celkovaCena = faktury[i]->GetCenaCelkem();
            double dopravne = faktury[i]->GetDopravne();
            double zaplaceno = faktury[i]->GetZaplacenaCastka();
            double zbyvaZaplatit = (celkovaCena + dopravne) - zaplaceno;

            if (zbyvaZaplatit > 0)
            {
                cout << "-----------------------------" << endl;
                cout << "Faktura c.: " << faktury[i]->GetCisloFaktury() << endl;
                cout << "Dodavatel: " << faktury[i]->GetDodavatel()->GetNazev() << endl;
                cout << "Odberatel: " << faktury[i]->GetOdberatel()->GetNazev() << endl;
                cout << "Cena celkem s dopravou: " << celkovaCena + dopravne << " Kc" << endl;
                cout << "Zaplaceno: " << zaplaceno << " Kc" << endl;
                cout << "Zbyva zaplatit: " << zbyvaZaplatit << " Kc" << endl;
                nalezeno = true;
            }
        }
    }

    if (!nalezeno)
    {
        cout << "Zadne nezaplacene faktury." << endl;
    }
}

void Fakturace::PridatFirmu(ObchodniPartner* firma)
{
    ObchodniPartner** noveFirmy = new ObchodniPartner * [pocetFirem + 1];
    for (int i = 0; i < pocetFirem; ++i)
    {
        noveFirmy[i] = firmy[i];
    }
    noveFirmy[pocetFirem] = firma;
    delete[] firmy;
    firmy = noveFirmy;
    pocetFirem++;
}

void Fakturace::PridejOdberateleDoFaktury(Faktura* faktura, const string& icoFirmy)
{
    for (int i = 0; i < pocetFirem; ++i)
    {
        if (firmy[i]->GetIco() == icoFirmy)
        {
            if (firmy[i]->GetTyp() == "Odberatel")
            {
                faktura->PridatOdberatele((Odberatel*)firmy[i]);
                
                return;
            }
            else
            {
                cout << "Firma s ICO " << icoFirmy << " neni typu Odberatel." << endl;
                return;
            }
        }
    }
    cout << "Firma s ICO " << icoFirmy << " nebyla nalezena." << endl;
    
}

void Fakturace::PridejDodavateleDoFaktury(Faktura* faktura, const string& icoFirmy)
{
    for (int i = 0; i < pocetFirem; ++i)
    {
        if (firmy[i]->GetIco() == icoFirmy)
        {
            if (firmy[i]->GetTyp() == "Dodavatel")
            {
                faktura->PridatDodavatele((Dodavatel*)firmy[i]);
                return;
            }
            else
            {
                cout << "Firma s ICO " << icoFirmy << " neni typu Dodavatel." << endl;
                return;
            }
        }
    }
    cout << "Firma s ICO " << icoFirmy << " nebyla nalezena." << endl;
}




void Fakturace::VypisFirmy()
{
    for (int i = 0; i < pocetFirem; ++i)
    {
        firmy[i]->Print();
    }
}

