#pragma once
#include <vector>
#include "produs.h"

// Clasa CosCumparaturi gestioneaza lista produselor adaugate in cos
class CosCumparaturi {
private:
    // Vector de perechi: pointer la produs + cantitatea respectiva
    std::vector<std::pair<Produs*, int>> produse;

public:
    // Adauga un produs in cos (daca exista deja, creste cantitatea)
    void adaugaProdus(Produs* produs);

    // Afiseaza cosul de cumparaturi intr-un format tabelar
    void afiseazaCos() const;

    // Calculeaza suma totala a produselor din cos
    double total() const;

    // Afiseaza factura detaliata cu lista produselor si total
    // Salveaza comanda si in fisierul comenzi.txt
    void afiseazaFacturaDetaliata() const;

    // Goleste toate produsele din cos
    void golesteCos();

    // Afiseaza toate comenzile efectuate, citind din fisierul comenzi.txt
    void afiseazaComenzi() const;
};
