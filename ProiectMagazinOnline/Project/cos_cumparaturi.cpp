#include "cos_cumparaturi.h"
#include <iostream>
#include <iomanip>
using namespace std;

void CosCumparaturi::adaugaProdus(Produs* produs) {
    for (auto& entry : produse) {
        if (entry.first == produs) {
            entry.second++; // crestem cantitatea
            return;
        }
    }
    produse.push_back({ produs, 1 });
}

void CosCumparaturi::afiseazaCos() const {
    if (produse.empty()) {
        cout << "Cosul este gol.\n";
        return;
    }

    cout << "\n----- Produse in cos -----\n";
    cout << left << setw(22) << "Produs"
         << right << setw(10) << "Pret"
         << setw(10) << "Cant" << "\n";
    cout << string(42, '-') << "\n";

    for (const auto& entry : produse) {
        cout << left << setw(22) << entry.first->getNume()
             << right << fixed << setprecision(2)
             << setw(10) << entry.first->getPret()
             << setw(10) << entry.second << "\n";
    }

    cout << string(42, '-') << "\n";
    cout << right << setw(32) << "TOTAL: "
         << fixed << setprecision(2) << total() << " LEI\n";
}

void CosCumparaturi::afiseazaFacturaDetaliata() const {
    if (produse.empty()) {
        cout << "Cosul este gol. Nu se poate genera factura.\n";
        return;
    }

    cout << "\n---------------------- FACTURA -----------------------\n";
    cout << left << setw(4) << "Nr"
        << setw(22) << "Produs"
        << right << setw(6) << "Cant"
        << setw(12) << "Pret"
        << setw(14) << "Total" << "\n";

    cout << string(60, '-') << "\n";

    double totalFinal = 0;
    for (size_t i = 0; i < produse.size(); ++i) {
        const auto& entry = produse[i];
        double totalProdus = entry.first->getPret() * entry.second;
        totalFinal += totalProdus;

        cout << left << setw(4) << i + 1
            << setw(22) << entry.first->getNume()
            << right << setw(6) << entry.second
            << fixed << setprecision(2)
            << setw(12) << entry.first->getPret()
            << setw(14) << totalProdus << "\n";
    }

    cout << string(60, '-') << "\n";
    cout << right << setw(54) << "TOTAL DE PLATA: "
        << fixed << setprecision(2) << totalFinal << " LEI\n";
}




double CosCumparaturi::total() const {
    double suma = 0;
    for (const auto& entry : produse) {
        suma += entry.first->getPret() * entry.second;
    }
    return suma;
}

void CosCumparaturi::golesteCos() {
    produse.clear();
}
