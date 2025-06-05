#pragma once
#include <string>

using namespace std;
//Abstraktní třída
class Firma
{
protected:
    string nazev;
    string adresa;

public:
    Firma(string nazev, string adresa);
    virtual ~Firma() = default;

    string GetNazev();
    string GetAdresa();

    virtual void Print();
};

