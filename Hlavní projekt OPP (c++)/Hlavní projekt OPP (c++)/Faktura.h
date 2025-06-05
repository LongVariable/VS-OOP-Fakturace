#pragma once
#include "PolozkaFaktury.h"
#include "Platba.h"
#include "Date.h"
#include "Odberatel.h"
#include "Dodavatel.h"

class Faktura
{
private:
    int cisloFaktury;
    Date datumVystaveni;
    Date datumSplatnosti;
    vector<PolozkaFaktury> polozky;
    double cenaCelkem;

    string poznamka;
    double dopravne;

    bool zaplaceno;
    double uhrazenaCastka;

    Odberatel* odberatel;
    Dodavatel* dodavatel;

    static int objectCount;
    static double globalDopravne;

public:
    // přetěžování metod
    Faktura(int cF, Date dV, Date dS);
    Faktura(int cF, Date dV, Date dS, string poznamka);
    Faktura(int cF, Date dV, Date dS, double cenaCelkem);
    Faktura(int cF, Date dV, Date dS, string poznamka, double dopravne);
    Faktura(int cF, Date dV, Date dS, double cenaCelkem, double dopravne);
    Faktura(int cF, Date dV, Date dS, double cenaCelkem, string poznamka);
    Faktura(int cF, Date dV, Date dS, double cenaCelkem, string poznamka, double dopravne);
    ~Faktura();

    double GetCenaCelkem();
    double GetDopravne();
    double GetZaplacenaCastka();
    int GetCisloFaktury();
    Dodavatel* GetDodavatel();
    Odberatel* GetOdberatel();


    void PridejPolozku(PolozkaFaktury polozka);
    void VypocetCelkoveCeny();

    void PriradPlatbu(Platba& platba);
    void OznacJakoZaplacene();
    double VypocetZbyvajiciCastky();
    bool JeZaplaceno();

    void PridatOdberatele(Odberatel* odberatel);
    void PridatDodavatele(Dodavatel* dodavatel);

    void PrintFaktura();

    static int GetObjectCount();
    static double GetGlobalDopravne();
    static void SetGlobalDopravne(double dopravne);
};
