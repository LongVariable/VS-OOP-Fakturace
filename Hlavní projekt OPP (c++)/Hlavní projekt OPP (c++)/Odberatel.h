#pragma once
#include "ObchodniPartner.h"
class Odberatel : public ObchodniPartner //dědění z Obchodní partner
{
private: 
	string kontakt;
	double sleva;
	bool pravidelnyZakaznik;
public:
	Odberatel(string ico, string nazev, string adresa, string kontaktRodic, string kontaktOdberatel, double sleva, bool pravidelnyZakaznik);

	double GetSleva();
	bool JePravidelnyZakaznik();
	void NastavSlevu(double sleva);

	string GetTyp() override;
	void Print();
};

