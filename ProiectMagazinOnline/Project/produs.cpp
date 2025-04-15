#include <iostream>
#include <iomanip>
#include "produs.h"

Produs::Produs(const string& nume, double pret) : nume(nume), pret(pret) {}

string Produs::getNume() const {
    return nume;
}

double Produs::getPret() const {
    return pret;
}

ostream& operator<<(ostream& out, const Produs& produs) {
    out << produs.nume << " - " << fixed << setprecision(2) << produs.pret << " RON";
    return out;
}
