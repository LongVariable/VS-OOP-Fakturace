#pragma once
#include "Faktura.h"
#include "Platba.h"
#include "ObchodniPartner.h"
#include "Date.h"

class Fakturace
{
private:
	Faktura** faktury;
	Platba** platby;
	ObchodniPartner** firmy;
	int pocetFaktur;
	int pocetPlateb;
	int pocetFirem;

	
public:
	Fakturace(int faktury, int platby, int firmy);
	~Fakturace();
	void PridejFakturu(Faktura& faktura);
	void PridejPlatbu(Platba& platba);
	void PriradPlatbuKFakture(int cisloFaktury, Platba& platba);
	void VypisNezaplaceneFaktury();

	void PrintFaktury();
	void PrintPlatby();

	void PridatFirmu(ObchodniPartner* firma);
	void PridejOdberateleDoFaktury(Faktura* faktura, const string& icoFirmy);
	void PridejDodavateleDoFaktury(Faktura* faktura, const string& icoFirmy);

	void VypisFirmy();
};

