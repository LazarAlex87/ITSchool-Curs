#include "produs.h"
#include <iomanip> // pentru setprecision si fixed

// Constructor: initializeaza numele si pretul produsului
Produs::Produs(const string& nume, double pret) : nume(nume), pret(pret) {}

// Returneaza numele produsului
string Produs::getNume() const {
    return nume;
}

// Returneaza pretul produsului
double Produs::getPret() const {
    return pret;
}

// Supraincarcam operatorul << pentru afisarea produsului
ostream& operator<<(ostream& out, const Produs& produs) {
    out << produs.nume << " - "
        << fixed << setprecision(2) << produs.pret << " LEI";
    return out;
}
