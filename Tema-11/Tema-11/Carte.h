#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <string>

class Carte {
protected:
    std::string titlu;
    std::string autor;
    int anPublicare;
    std::string categorie;
    int rand;
    int raft;
    bool imprumutata;

public:
    Carte(std::string titlu, std::string autor, int an, std::string categorie, int rand, int raft);
    virtual ~Carte() {}
    void afiseazaInformatii() const;
    void imprumuta();
    void returneaza();
    bool esteImprumutata() const;
    std::string getTitlu() const { return titlu; }
    std::string getCategorie() const { return categorie; }
    int getRand() const { return rand; }
    int getRaft() const { return raft; }
};

#endif
