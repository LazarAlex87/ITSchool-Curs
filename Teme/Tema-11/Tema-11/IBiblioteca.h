#ifndef IBIBLIOTECA_H
#define IBIBLIOTECA_H

#include "Carte.h"
#include <vector>

class IBiblioteca {
public:
    virtual ~IBiblioteca() {}
    virtual void adaugaCarte(Carte* carte) = 0;
    virtual void afiseazaCarti() const = 0;
    virtual void imprumutaCarte(const std::string& titlu) = 0;
    virtual void returneazaCarte(const std::string& titlu) = 0;
};

#endif