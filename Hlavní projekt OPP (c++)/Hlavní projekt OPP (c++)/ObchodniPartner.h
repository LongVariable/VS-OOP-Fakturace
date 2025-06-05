#pragma once
#include "Firma.h"
class ObchodniPartner : public Firma //dědění z Firmy
{
protected:
    string ico;
    string kontakt;

public:
    ObchodniPartner(string ico, string nazev,  string adresa,  string kontakt);
    string GetIco();
    string GetKontakt();
    virtual string GetTyp() = 0;
    void Print() override;
};

