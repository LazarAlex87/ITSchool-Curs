#pragma once
#include <vector>
#include "produs.h"

class CosCumparaturi {
private:
    std::vector<std::pair<Produs*, int>> produse;

public:
    void adaugaProdus(Produs* produs);
    void afiseazaCos() const;
    double total() const;
    void afiseazaFacturaDetaliata() const;
    void golesteCos();
};
