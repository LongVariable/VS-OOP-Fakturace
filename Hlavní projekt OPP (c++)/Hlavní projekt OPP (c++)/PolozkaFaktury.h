#pragma once
#include <string>
#include <vector>

using namespace std;
class PolozkaFaktury
{
private:
	string nazev;
	int mnozstvi;
	double DPH;
	double cenaZaKus;
	double cenaCelkem;

	void VypocetCenyCelkem();

public:
	PolozkaFaktury(string nazev, int mnozstvi, double DPH, double cenaZaKus);

	string GetNazev();	
	int GetMnozstvi();
	double GetDPH();
	double GetCenaZaKus();
	double GetCenaCelkem();

	void PrintPolozkaFaktury();
};

