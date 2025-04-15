/*  Sa se implementeze o aplicatie biblieoteca in care sa avem 10 carti(titlu autor an publicare)
	pe care sa le putem imprumuta, sa aranjeze per categorie (ex: beletristica, istoria, bibliografie) rand, raft.
		1. Aplicatie sa fie structurata pe mai multe fisiere cpp
		2. Aplicatia sa utilizeze abstract classess as interfaces
*/

#include "Biblioteca.h"

int main() {
    Biblioteca biblioteca;

    biblioteca.adaugaCarte(new Carte("Ion", "Liviu Rebreanu", 1920, "Beletristica", 1, 1));
    biblioteca.adaugaCarte(new Carte("O scurta istorie a timpului", "Stephen Hawking", 1988, "Istorie", 2, 3));
    biblioteca.adaugaCarte(new Carte("Biografia lui Einstein", "Walter Isaacson", 2007, "Biografie", 3, 2));
    biblioteca.adaugaCarte(new Carte("Amintiri din copilarie", "Ion Creanga", 1880, "Beletristica", 1, 2));
    biblioteca.adaugaCarte(new Carte("Sapiens", "Yuval Noah Harari", 2011, "Istorie", 2, 1));
    biblioteca.adaugaCarte(new Carte("Brief Answers to the Big Questions", "Stephen Hawking", 2018, "Istorie", 2, 2));
    biblioteca.adaugaCarte(new Carte("Viata lui Nicolae Iorga", "Gheorghe I. Bratianu", 1939, "Biografie", 3, 1));
    biblioteca.adaugaCarte(new Carte("Crima si pedeapsa", "Dostoievski", 1866, "Beletristica", 1, 3));
    biblioteca.adaugaCarte(new Carte("Sherlock Holmes", "Arthur Conan Doyle", 1887, "Beletristica", 1, 4));
    biblioteca.adaugaCarte(new Carte("Steve Jobs", "Walter Isaacson", 2011, "Biografie", 3, 3));

    std::cout << "Lista cartilor din biblioteca (ordonata):\n";
    biblioteca.afiseazaCartiOrdonate(); 

    biblioteca.imprumutaCarte("Ion");
    biblioteca.returneazaCarte("Ion");

    return 0;
}

/*
   Carte.h          - Defineste clasa Carte cu titlu, autor, an, categorie, rand, raft ?i metode pentru imprumut / returnare
   Carte.cpp        - Implementeaza metodele clasei Carte
   IBiblioteca.h    - Interfata abstracta pentru gestionarea bibliotecii
   Biblioteca.h     - Clasa Biblioteca implementeaza IBiblioteca, gestionând cartile
   Biblioteca.cpp   - Implementarea metodelor pentru adaugare, afisare, imprumut si returnare a catilor
   Main.cpp         - Initializeaza biblioteca, adauga 10 carti, afiseaza lista sortata si testeaza functionalitatea
*/