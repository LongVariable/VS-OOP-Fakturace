#include <iostream>
#include <string>

#include "Fakturace.h"
#include "Faktura.h"
#include "Platba.h"
#include "Firma.h"
#include "Dodavatel.h"
#include "Odberatel.h"

using namespace std;

int main()
{
    int pocetFaktur = 10;
    int pocetPlateb = 10;
    int pocetFirem = 10;

    Fakturace fakturace(pocetFaktur, pocetPlateb, pocetFirem);

    std::string dodavatelAdresy[10] = {
        "Praha 1, Vodickova 10", "Brno, Hlavni 55", "Ostrava, Masarykovo namesti 15",
        "Plzen, Klatovska 30", "Liberec, Prazska 5", "Olomouc, Horni namesti 12",
        "Usti nad Labem, Mirove namesti 1", "Hradec Kralove, Gocarova 22",
        "Ceske Budejovice, Lannova 6", "Zlin, Trida Tomase Bati 7"
    };

    std::string odberatelAdresy[10] = {
        "Karlovy Vary, Moskevska 11", "Pardubice, Trida Miru 20", "Jihlava, Masarykovo namesti 8",
        "Teplice, Skolni 4", "Kladno, Vanova 2", "Most, Budovatelu 9",
        "Opava, Ostrozna 14", "Frydek-Mistek, Hlavni 17", "Karvina, Masarykovo namesti 3",
        "Jablonec nad Nisou, Mirove namesti 5"
    };

    std::string obchdoniPartneriTelefony[20] = {
        "+420401234567",
        "+420402234567",
        "+420403234567",
        "+420404234567",
        "+420405234567",
        "+420406234567",
        "+420407234567",
        "+420408234567",
        "+420409234567",
        "+420410234567",
        "+420411234567",
        "+420412234567",
        "+420413234567",
        "+420414234567",
        "+420415234567",
        "+420416234567",
        "+420417234567",
        "+420418234567",
        "+420419234567",
        "+420420234567"
    };

    std::string dodavateleTelefony[10] = {
        "+420601234567",
        "+420602234567",
        "+420603234567",
        "+420604234567",
        "+420605234567",
        "+420606234567",
        "+420607234567",
        "+420608234567",
        "+420609234567",
        "+420610234567"
    };

    std::string odberateleTelefony[10] = {
       "+420701234567",
       "+420702234567",
       "+420703234567",
       "+420704234567",
       "+420705234567",
       "+420706234567",
       "+420707234567",
       "+420708234567",
       "+420709234567",
       "+420710234567"
    };

    for (int i = 0; i < 10; i++)
    {
        //polymorfismus
        ObchodniPartner* dodavatel = new Dodavatel("D0000" + to_string(i), "Dodavatel " + to_string(i), dodavatelAdresy[i], obchdoniPartneriTelefony[i], dodavateleTelefony[i], "128945" + to_string(i + 10) + "/0800", i + 3 * 2);
        fakturace.PridatFirmu(dodavatel);
    }
    for (int i = 0; i < 10; i++)
    {
        bool pZ = true;
        if (i > 5)
            pZ = false;
        //polymorfismus
        ObchodniPartner* odberatel = new Odberatel("O1000" + to_string(i), "Odberatel " + to_string(i), odberatelAdresy[i], obchdoniPartneriTelefony[i+10], odberateleTelefony[i], 4.5, pZ);
        fakturace.PridatFirmu(odberatel);
    }
    cout << "---- Vypis firem ----" << endl;
    fakturace.VypisFirmy();
    cout << endl;

    Date datumVystaveni = { 12,5,2025 };
    Date datumSplatnosti = { 22,5,2025 };
    Faktura faktura1(1, datumVystaveni, datumSplatnosti, "Nakup nabytku", 500);
    Faktura faktura2(2, datumVystaveni, datumSplatnosti, 6000, "Servisni prace");

    PolozkaFaktury polozka1("Skrin", 1, 21.0, 12000);
    PolozkaFaktury polozka2("Stul", 1, 21.0, 6000);
    PolozkaFaktury polozka3("Skrin", 4, 21.0, 2000);

    faktura1.PridejPolozku(polozka1);
    faktura1.PridejPolozku(polozka2);
    faktura1.PridejPolozku(polozka3);

    fakturace.PridejFakturu(faktura1);
    fakturace.PridejFakturu(faktura2);
   

    fakturace.PridejDodavateleDoFaktury(&faktura1, "D00002");
    fakturace.PridejOdberateleDoFaktury(&faktura1, "O10005");

    fakturace.PridejDodavateleDoFaktury(&faktura2, "D00004");
    fakturace.PridejOdberateleDoFaktury(&faktura2, "O10005");

    cout << "\n---- Vypis faktur ----" << endl;
    fakturace.PrintFaktury();
    cout << endl;

    Date datumPlatby = { 18,5,2025 };
    Platba platba1(1,datumPlatby, 25000, "Bankovni prevod");
    Platba platba2(2,datumPlatby, 6000, "Hotovost");

    fakturace.PridejPlatbu(platba1);
    fakturace.PridejPlatbu(platba2);

    cout << "\n---- Vypis plateb ----" << endl;
    fakturace.PrintPlatby();

    cout << "\n---- Prirazeni plateb k fakturam ----" << endl;
    fakturace.PriradPlatbuKFakture(1, platba1);
    fakturace.PriradPlatbuKFakture(2, platba2);

    cout << "\n---- Nezaplacene faktury ----" << endl;
    fakturace.VypisNezaplaceneFaktury();

    Dodavatel* dodavatel = new Dodavatel("D0000" + to_string(4), "Dodavatel " + to_string(4), "Adresa", "+420 587 954 112", "123456789", "128945" + to_string(0 + 10) + "/0800", 3 * 2);
    ObchodniPartner* obchodniPartner = dodavatel;

    cout << dodavatel->GetKontakt() << endl;
    cout << obchodniPartner->GetKontakt();

    getchar();
    return 0;
}
