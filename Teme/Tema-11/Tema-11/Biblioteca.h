#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "IBiblioteca.h"

class Biblioteca : public IBiblioteca {
private:
    std::vector<Carte*> carti;

public:
    ~Biblioteca();
    void adaugaCarte(Carte* carte) override;
    void afiseazaCarti() const override;
    void imprumutaCarte(const std::string& titlu) override;
    void returneazaCarte(const std::string& titlu) override;
    void afiseazaCartiOrdonate() const;
};

#endif