#define _CRT_SECURE_NO_WARNINGS
#include "cos_cumparaturi.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

// Adauga un produs in cos sau creste cantitatea daca deja exista
void CosCumparaturi::adaugaProdus(Produs* produs) {
    for (auto& entry : produse) {
        if (entry.first == produs) {
            entry.second++;
            return;
        }
    }
    produse.push_back({ produs, 1 });
}

// Afiseaza produsele din cos intr-un format tabelar
void CosCumparaturi::afiseazaCos() const {
    if (produse.empty()) {
        cout << "Cosul este gol.\n";
        return;
    }

    cout << "\n--- Produse in cos ---\n";
    cout << left << setw(22) << "Produs"
        << right << setw(10) << "Pret"
        << setw(10) << "Cant\n";
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

// Calculeaza totalul cosului
double CosCumparaturi::total() const {
    double suma = 0;
    for (const auto& entry : produse) {
        suma += entry.first->getPret() * entry.second;
    }
    return suma;
}

// Afiseaza factura detaliata si salveaza comanda in fisier
void CosCumparaturi::afiseazaFacturaDetaliata() const {
    if (produse.empty()) {
        cout << "Cosul este gol. Nu se poate genera factura.\n";
        return;
    }

    cout << "\n---------------- FACTURA ----------------\n";
    cout << left << setw(4) << "Nr"
        << setw(22) << "Produs"
        << right << setw(6) << "Cant"
        << setw(12) << "Pret"
        << setw(14) << "Total\n";
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

    // Salvam comanda in comenzi.txt
    ofstream fout("comenzi.txt", ios::app);
    if (fout.is_open()) {
        // Salvam data si ora
        time_t now = time(0);
        tm* localTime = localtime(&now);

        fout << "Comanda efectuata la: "
            << (1900 + localTime->tm_year) << "-"
            << (1 + localTime->tm_mon) << "-"
            << localTime->tm_mday << " "
            << localTime->tm_hour << ":"
            << localTime->tm_min << ":"
            << localTime->tm_sec << "\n";

        fout << left << setw(4) << "Nr"
            << setw(22) << "Produs"
            << right << setw(6) << "Cant"
            << setw(12) << "Pret"
            << setw(14) << "Total\n";
        fout << string(60, '-') << "\n";

        for (size_t i = 0; i < produse.size(); ++i) {
            const auto& entry = produse[i];
            double totalProdus = entry.first->getPret() * entry.second;

            fout << left << setw(4) << i + 1
                << setw(22) << entry.first->getNume()
                << right << setw(6) << entry.second
                << fixed << setprecision(2)
                << setw(12) << entry.first->getPret()
                << setw(14) << totalProdus << "\n";
        }

        fout << string(60, '-') << "\n";
        fout << right << setw(54) << "TOTAL DE PLATA: "
            << fixed << setprecision(2) << totalFinal << " RON\n";
        fout << "\n------------------------------------------------------------\n";
    }
}

// Goleste cosul
void CosCumparaturi::golesteCos() {
    produse.clear();
}

// Afiseaza comenzile efectuate din comenzi.txt
void CosCumparaturi::afiseazaComenzi() const {
    ifstream fin("comenzi.txt");
    if (!fin.is_open()) {
        cout << "Nu exista comenzi efectuate inca.\n";
        return;
    }

    string linie;
    while (getline(fin, linie)) {
        cout << linie << "\n";
    }

    fin.close();
}
