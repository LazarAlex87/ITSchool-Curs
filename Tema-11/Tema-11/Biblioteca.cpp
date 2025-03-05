#include "Biblioteca.h"
#include <algorithm>

Biblioteca::~Biblioteca() {
    for (auto& carte : carti)
        delete carte;
}

void Biblioteca::adaugaCarte(Carte* carte) {
    carti.push_back(carte);
}

void Biblioteca::afiseazaCarti() const {
    for (const auto& carte : carti)
        carte->afiseazaInformatii();
}

void Biblioteca::imprumutaCarte(const std::string& titlu) {
    for (auto& carte : carti) {
        if (carte->esteImprumutata() == false && carte->getTitlu() == titlu) {
            carte->imprumuta();
            return;
        }
    }
    std::cout << "Cartea nu a fost gasita sau este deja imprumutata.\n";
}

void Biblioteca::returneazaCarte(const std::string& titlu) {
    for (auto& carte : carti) {
        if (carte->esteImprumutata() == true && carte->getTitlu() == titlu) {
            carte->returneaza();
            return;
        }
    }
    std::cout << "Cartea nu a fost gasita sau nu era imprumutata.\n";
}

void Biblioteca::afiseazaCartiOrdonate() const {
    std::vector<Carte*> cartiOrdonate = carti; 

    std::sort(cartiOrdonate.begin(), cartiOrdonate.end(), [](Carte* a, Carte* b) {
        if (a->getCategorie() != b->getCategorie())
            return a->getCategorie() < b->getCategorie();
        if (a->getRand() != b->getRand())
            return a->getRand() < b->getRand();
        return a->getRaft() < b->getRaft();
        });

    for (const auto& carte : cartiOrdonate) {
        carte->afiseazaInformatii();
    }
}