#include "Carte.h"

Carte::Carte(std::string titlu, std::string autor, int an, std::string categorie, int rand, int raft)
    : titlu(titlu), autor(autor), anPublicare(an), categorie(categorie), rand(rand), raft(raft), imprumutata(false) {
}

void Carte::afiseazaInformatii() const {
    std::cout << "Titlu: " << titlu << ", Autor: " << autor << ", An: " << anPublicare
        << ", Categorie: " << categorie << ", Rand: " << rand << ", Raft: " << raft
        << ", Imprumutata: " << (imprumutata ? "Da" : "Nu") << std::endl;
}

void Carte::imprumuta() {
    if (!imprumutata) {
        imprumutata = true;
        std::cout << "Cartea \"" << titlu << "\" a fost imprumutata.\n";
    }
    else {
        std::cout << "Cartea este deja imprumutata.\n";
    }
}

void Carte::returneaza() {
    if (imprumutata) {
        imprumutata = false;
        std::cout << "Cartea \"" << titlu << "\" a fost returnata.\n";
    }
    else {
        std::cout << "Cartea nu era imprumutata.\n";
    }
}

bool Carte::esteImprumutata() const {
    return imprumutata;
}