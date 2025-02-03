/*  Exercitiul 1: Folosind clasa friend implementati o aplicatie in care sa aveti calculati volumul unei cutii :
                  - clasa cutie sa contina initializarea constructorului si metoda de afisare a dimensiunilor cutiei
                  - clasa friend o sa contina metoda caluleaza volum si afisaza volumul si metoda care modifica dimensiunea cutiei
                  - in main cream obictul cutiamica calculam volumul si modificam cutiei si afisam dimensiunile */


#include <iostream>
#include <vector>
#include <string>

using namespace std;


class CutieFriend;

class Cutie {
    double lungime;
    double latime;
    double inaltime;

public:    
    Cutie(double l, double w, double h)
        : lungime(l), latime(w), inaltime(h) {
    }
        
    friend class CutieFriend;
       
    void afiseazaDimensiuni() const {
        cout << "Dimensiuni cutie: " << lungime << " x " << latime << " x " << inaltime << endl;
    }
};

class CutieFriend {
public:    
    void calculeazaVolum(const Cutie& c) {
        double volum = c.lungime * c.latime * c.inaltime;
        cout << "Volumul cutiei este: " << volum << "\n" << endl;
    }
        
    void modificaDimensiuni(Cutie& c, double newL, double newW, double newH) {
        c.lungime = newL;
        c.latime = newW;
        c.inaltime = newH;
    }
};

/*  Exercitiul 2: Implementati clasa “persoana” care contine metoda de afisare a varstei si numelui,
    clasa child  “angajat” ne spune ce functie ocupa angajatul, si metoda care afisaza numele jobului. */

class persoana {
    string nume;
    int varsta;

public:
    persoana(string n, int v) : nume(n), varsta(v) {}

    void afiseazaPersoana() const;
};

void persoana::afiseazaPersoana() const {
    cout << "Nume: " << nume << ", Varsta: " << varsta << endl;
}

class angajat : public persoana {
private:
    string functie;

public:
    angajat(string n, int v, string f)
        : persoana(n, v), functie(f) {
    }

    void afiseazaFunctie() const;    
};

void angajat::afiseazaFunctie() const {
    cout << "Functie: " << functie << endl;
}

int main() { 
    // Exercitiul 1:
    Cutie cutiamica(10, 5, 3);
    cutiamica.afiseazaDimensiuni();
       
    CutieFriend cf;
    
    cf.calculeazaVolum(cutiamica);
    
    cf.modificaDimensiuni(cutiamica, 7, 4, 2);
    
    cutiamica.afiseazaDimensiuni();
    cf.calculeazaVolum(cutiamica);

    // Exercitiul 2 :
    angajat a("Alex Lazar", 37, "Programator");

    a.afiseazaPersoana();
    a.afiseazaFunctie();


    return 0;
}

