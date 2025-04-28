#pragma once
#include <string>
#include <iostream>
using namespace std;

// Clasa Produs - reprezinta un articol disponibil in magazin
class Produs {
private:
    string nume;   // numele produsului
    double pret;   // pretul produsului

public:
    // Constructor care initializeaza numele si pretul
    Produs(const string& nume, double pret);

    // Getter pentru nume
    string getNume() const;

    // Getter pentru pret
    double getPret() const;

    // Supraincarcam operatorul << pentru afisarea unui produs
    friend ostream& operator<<(ostream& out, const Produs& produs);
};
