#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "produs.h"
#include "cos_cumparaturi.h"

using namespace std;

vector<Produs> listaProduse;
CosCumparaturi cosClient;

void incarcaProduseDinFisier(const string& numeFisier) {
    ifstream fin(numeFisier);
    if (!fin.is_open()) {
        throw runtime_error("Nu s-a putut deschide fisierul: " + numeFisier);
    }

    string linie;
    while (getline(fin, linie)) {
        stringstream ss(linie);
        string nume;
        double pret;

        getline(ss, nume, ',');
        if (!(ss >> pret)) {
            throw logic_error("Format invalid in fisier la linia: " + linie);
        }

        listaProduse.emplace_back(nume, pret);
    }

    fin.close();
}

void meniuUtilizatorAutentificat() {
    int optiune;

    do {
        cout << "\n----=== Meniu Utilizator ===----\n\n";
        cout << "      1. Lista Produse\n";
        cout << "      2. Cos de cumparaturi\n";
        cout << "      3. Finalizare comanda\n";
        cout << "      0. Deconectare\n";
        cout << "\nAlege o optiune: ";
        cin >> optiune;

        switch (optiune) {
        case 1:
            while (true) {
                cout << "\n--- Lista de Produse ---\n";
                cout << left << setw(4) << "ID"
                    << setw(25) << "Produs"
                    << setw(10) << "Pret (RON)\n";
                cout << string(40, '-') << "\n";

                for (size_t i = 0; i < listaProduse.size(); ++i) {
                    cout << left << setw(4) << i + 1
                        << setw(25) << listaProduse[i].getNume()
                        << fixed << setprecision(2)
                        << listaProduse[i].getPret() << "\n";
                }

                cout << "\nIntrodu ID produs (0 pentru inapoi): ";
                int idProdus;
                if (!(cin >> idProdus)) {
                    cout << "Input invalid. Introdu un numar.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                if (idProdus == 0)
                    break;

                if (idProdus < 1 || idProdus >(int)listaProduse.size()) {
                    cout << "ID invalid! Reincearca.\n";
                    continue;
                }

                cout << "Cantitate dorita: ";
                int cantitate;
                if (!(cin >> cantitate) || cantitate <= 0) {
                    cout << "Cantitate invalida! Introdu un numar pozitiv.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                for (int i = 0; i < cantitate; ++i) {
                    cosClient.adaugaProdus(&listaProduse[idProdus - 1]);
                }

                cout << "Produs adaugat in cos (" << cantitate << " x " << listaProduse[idProdus - 1].getNume() << ").\n";
            }
            break;

        case 2:
            cosClient.afiseazaCos();
            break;

        case 3:
            cosClient.afiseazaFacturaDetaliata();
            cosClient.golesteCos();
            cout << "Comanda finalizata. Va multumim!\n";
            break;

        case 0:
            cout << "Te-ai deconectat cu succes.\n";
            break;

        default:
            cout << "Optiune invalida. Reincercati.\n";
        }
    } while (optiune != 0);
}