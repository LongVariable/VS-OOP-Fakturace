#pragma once
#include "ObchodniPartner.h"
class Dodavatel : public ObchodniPartner //dědění z Obchodní partner
{
private:
	string kontakt;
	string bankovniUcet;
	int dodaciLhuta;
public:
	Dodavatel(string ico, string nazev, string adresa, string kontaktRodic, string kontaktDodavatel, string bankovniUcet, int dodaciLhuta);
	string GetTyp() override;

	string GetKontakt();
	string GetBankovniUcet();
	int GetDodaciLhuta();
	void Print() override;	

};

