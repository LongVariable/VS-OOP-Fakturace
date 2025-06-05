	#pragma once
	#include <string>
	#include "Date.h"
	using namespace std;

	class Platba
	{
	private: 
		int cislo;
		Date datumPlatby;
		double castka;
		string typPlatby;
	public:
		Platba(int cislo,Date datumPlatby, double castka, string typPlatby);

		int GetCisloPlatby();
		Date GetDatumPlatby();
		double GetCastka();
		string GetTypPlatby();

		void PrintPlatba();
	};

