#pragma once
#include <iostream>
#include <string>
using namespace std;

class Produs {
private:
    string nume;
    double pret;

public:
    Produs(const string& nume, double pret);
    string getNume() const;
    double getPret() const;

    friend ostream& operator<<(ostream& out, const Produs& produs);
};
