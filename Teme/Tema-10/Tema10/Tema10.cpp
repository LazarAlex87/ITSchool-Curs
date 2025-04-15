/* Sa sa implementeze o aplicatie in care sa avem un magazin cu aproximativ 20 de produse dsi deja stabilite de voi
   si o anumita cantinate (ex. 10 saci de cartofi), daca clientul cere 11, sa se aduca produsul din depozit 
   (aici o sa folositi overloading pentru comparare copy/move constructor pentru a aduce produsele din depozit).
   Extra puteti sa stabiliti pretul produselor si sa calculati cat are de platit clientul, suma ce o primiti si cat trebuie sa oferiti rest.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Produs {
    string nume;
    int cantitate;
    double pret;

public:
    Produs(string nume, int cantitate, double pret);

    string get_nume() const;
    int get_cantitate() const;
    double get_pret() const;
    void adauga_stoc(int amount);
    void afisare() const;

    Produs& operator-(int amount);
};

Produs::Produs(string nume, int cantitate, double pret)
    : nume(nume), cantitate(cantitate), pret(pret) {
}

string Produs::get_nume() const {
    return nume;
}

int Produs::get_cantitate() const {
    return cantitate;
}

double Produs::get_pret() const {
    return pret;
}

void Produs::adauga_stoc(int amount) {
    cantitate += amount;
}

void Produs::afisare() const {
    cout << nume << " - Cantitate: " << cantitate << ", Pret: " << pret << " RON" << endl;
}

Produs& Produs::operator-(int amount) {
    cantitate -= amount;
    return *this;
}

class Magazin {
    vector<Produs> produse;

public:
    Magazin();

    void afisare_produse();
    void procesare_comanda(string nume, int cantitate_ceruta);
    double calcul_pret(string nume, int cantitate_ceruta);
};

Magazin::Magazin() {
    produse = {
        {"Cartofi", 10, 2.5}, {"Ceapa", 15, 1.8}, {"Rosii", 8, 4.0},
        {"Morcovi", 20, 2.2}, {"Lapte", 12, 6.0}, {"Branza", 5, 15.0},
        {"Paine", 30, 1.5}, {"Oua", 24, 0.8}, {"Zahar", 10, 5.5},
        {"Faina", 12, 3.5}, {"Ulei", 7, 9.0}, {"Cafea", 10, 18.0},
        {"Biscuiti", 20, 4.5}, {"Ciocolata", 10, 7.0}, {"Suc", 15, 4.0},
        {"Apa", 25, 2.0}, {"Sare", 10, 1.0}, {"Piper", 5, 3.0},
        {"Detergent", 8, 12.0}, {"Sapun", 15, 3.0}
    };
}

void Magazin::afisare_produse() {
    for (const auto& produs : produse) {
        produs.afisare();
    }
}

void Magazin::procesare_comanda(string nume, int cantitate_ceruta) {
    for (auto& produs : produse) {
        if (produs.get_nume() == nume) {
            cout << "Produs gasit: " << produs.get_nume() << endl;

            if (produs.get_cantitate() >= cantitate_ceruta) {
                produs = produs - cantitate_ceruta;
                cout << "Comanda completata. Cantitatea ramasa: " << produs.get_cantitate() << endl;
            }
            else {
                int deficit = cantitate_ceruta - produs.get_cantitate();
                cout << "Cantitate insuficienta! Se aduc " << deficit << " bucati din depozit." << endl;

                // Aducem produselor din depozit (Move constructor)
                Produs produs_depozit = move(produs);
                produs_depozit.adauga_stoc(deficit);
                produs_depozit = produs_depozit - cantitate_ceruta;

                produs = produs_depozit; // Actualizam stocul
                cout << "Comanda completata. Cantitatea ramasa: " << produs.get_cantitate() << endl;
            }

            return;
        }
    }

    cout << "Produsul " << nume << " nu exista in magazin!" << endl;
}

double Magazin::calcul_pret(string nume, int cantitate_ceruta) {
    for (const auto& produs : produse) {
        if (produs.get_nume() == nume) {
            return cantitate_ceruta * produs.get_pret();
        }
    }
    return 0.0;
}

int main() {
    Magazin magazin;
    string nume_produs;
    int cantitate;
    double pret_total, suma_primita;

    cout << "Produse disponibile in magazin:\n" << endl;
    magazin.afisare_produse();

    cout << "\nIntroduceti numele produsului dorit: ";
    cin >> nume_produs;
    cout << "Introduceti cantitatea dorita: ";
    cin >> cantitate;
        
    magazin.procesare_comanda(nume_produs, cantitate);
        
    pret_total = magazin.calcul_pret(nume_produs, cantitate);
    cout << "\nPret total: " << pret_total << " RON" << endl;
        
    cout << "Introduceti suma primita de la client: ";
    cin >> suma_primita;

    if (suma_primita >= pret_total) {
        cout << "Rest: " << suma_primita - pret_total << " RON" << endl;
    }
    else {
        cout << "Suma insuficienta! Mai trebuie " << pret_total - suma_primita << " RON." << endl;
    }

    return 0;
}

