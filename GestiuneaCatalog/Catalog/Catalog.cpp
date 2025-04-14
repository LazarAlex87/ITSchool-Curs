/*  Sa se implementeze o aplicatie care sa gestioneze catalogul unei clase si fiecarui 
    elev sa ii se atribuie un loc in banca(rand/coloana) si sa putem gestiona prezenta 
    cu datele salvate intr un fisier. Folositi clase.
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Elev {                                                        
public:
    string nume;
    int rand;
    int coloana;
    bool prezent;

    Elev(string n = "", int r = 0, int c = 0, bool p = false)
        : nume(n), rand(r), coloana(c), prezent(p) {
    }
};

class Catalog {
public:
    vector<Elev> elevi;

    void adaugaElev() {
        string nume;
        int rand, coloana;
        cin.ignore();                   //folosim pt a curata bufferul ininte de getline, altfel s-ar citi ENTERUL ramas
        cout << "Nume elev: ";
        getline(cin, nume);
        cout << "Rand: ";
        cin >> rand;
        cout << "Coloana: ";
        cin >> coloana;

        elevi.push_back(Elev(nume, rand, coloana, false));  //cream un obiect Elev pe care il adaugam in vector ca fiind absent la inceput
        
        salveazaInFisier("catalog.txt");
    }

    void afiseazaCatalog() {                                //parcurgem toti elevii si afisam informariile lor
        for (auto& e : elevi) {
            cout << e.nume << " (Rand: " << e.rand << ", Coloana: " << e.coloana << ") - "
                << (e.prezent ? "Prezent" : "Absent") << endl;
        }
    }

    void marcheazaPrezenta() {
        string nume;
        cin.ignore();
        cout << "Introdu numele elevului pentru prezenta: ";
        getline(cin, nume);
        for (auto& e : elevi) {                              //cautam elevul in vectorul de elevi
            if (e.nume == nume) {
                e.prezent = true;
                cout << "Prezenta notata pentru elevul: " << nume << endl;
                salveazaInFisier("catalog.txt");
                return;
            }
        }
        cout << "Elevul nu a fost gasit.\n";                //daca nu gasim elevul
    } 

    void salveazaInFisier(string numeFisier) {
        ofstream fout(numeFisier);                          //deschidem fisierul pentru scriere
        for (auto& e : elevi) {                             //scriem fiecare elev in fisier si folosim | ca separator intre nume si restul
            fout << e.nume << "|" << e.rand << " " << e.coloana << " " << e.prezent << endl;
        }
        fout.close();
    }

    void incarcaDinFisier(string numeFisier) {
        ifstream fin(numeFisier);                           //deschidem fisierul pt citire
        string linie;
        while (getline(fin, linie)) {                       //citim linie cu linie
            size_t poz = linie.find('|');                   //cauta separatorul |
            if (poz != string::npos) {
                string nume = linie.substr(0, poz);         //ia partea din stg |
                string rest = linie.substr(poz + 1);        //  -- || --    dr  |

                //cauta spatiile care separa rand,coloana,prezent
                size_t spatiu1 = rest.find(' ');
                size_t spatiu2 = rest.find(' ', spatiu1 + 1);

                //extragem numerele ca int
                int rand = stoi(rest.substr(0, spatiu1));
                int coloana = stoi(rest.substr(spatiu1 + 1, spatiu2 - spatiu1 - 1));
                int prezent = stoi(rest.substr(spatiu2 + 1));

                elevi.push_back(Elev(nume, rand, coloana, prezent));    //creaza Elev si il adauga in vector
            }
        }
        fin.close();
    }
};

int main() {
    Catalog catalog;
    catalog.incarcaDinFisier("catalog.txt");

    int optiune;
    do {
        cout << "\n1. Adauga elev\n2. Afiseaza catalog\n3. Marcheaza prezenta\n0. Iesire\n";
        cout << "\nOptiune: ";
        cin >> optiune;

        if (optiune == 1) {
            catalog.adaugaElev();
        }
        else if (optiune == 2) {
            catalog.afiseazaCatalog();
        }
        else if (optiune == 3) {
            catalog.marcheazaPrezenta();
        }

    } while (optiune != 0);

    return 0;
}
