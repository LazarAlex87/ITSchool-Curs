#include <iostream>
#include <fstream>
#include <string>
#include <sstream>   // Pt a prelucra text linie cu linie, practic pt a separa campurile dintr-un string 
#include <cstdlib>   // Pt a genera cod random la inregistrare
#include <ctime>     // Pt a evidantia data si ora comenzilor in istoric
#include <stdexcept> // Pt tratarea exceptiilor: runtime_error , logic_error
#include "meniu_utilizator.h"

using namespace std;

// Declarare functie externa pentru incarcarea produselor din fisier
extern void incarcaProduseDinFisier(const string&);

// Functie pentru inregistrarea unui utilizator nou
// Genereaza un cod, il trimite prin email, verifica codul introdus
void inregistrare() {
    string email;
    cout << "=== Inregistrare ===\n";
    cout << "Introdu email: ";
    cin >> email;

    // Generam un cod random intre 10000 si 99999
    srand(time(0));
    int cod = rand() % 90000 + 10000;

    // Trimitem codul prin email folosind scriptul Python
    string comanda = "python trimite_email.py " + email + " cod " + to_string(cod);
    system(comanda.c_str());

    // Solicitam codul primit de la utilizator
    cout << "Am trimis un cod de verificare pe emailul tau.\n";
    cout << "Introdu codul primit: ";
    int cod_introdus;
    cin >> cod_introdus;

    if (cod_introdus == cod) {
        // Cod corect: cerem parola si salvam contul
        string parola;
        cout << "Cod corect! Acum seteaza parola: ";
        cin >> parola;

        ofstream fout("utilizatori.txt", ios::app);
        if (!fout) throw runtime_error("Nu se poate scrie in fisierul utilizatori.txt");
        fout << email << "," << parola << "\n";
        fout.close();

        cout << "Cont creat cu succes!\n";
    }
    else {
        // Cod introdus gresit
        cout << "Cod incorect. Inregistrare esuata.\n";
    }
}

// Functie pentru autentificare utilizator
// Verifica daca emailul si parola exista in fisierul utilizatori.txt
bool autentificare() {
    string email, parola;
    cout << "=== Autentificare ===\n";
    cout << "Introdu email: ";
    cin >> email;
    cout << "Introdu parola: ";
    cin >> parola;

    ifstream fin("utilizatori.txt");
    if (!fin) throw runtime_error("Nu s-a putut deschide utilizatori.txt");

    string linie, savedEmail, savedParola;
    while (getline(fin, linie)) {
        stringstream ss(linie);
        getline(ss, savedEmail, ',');
        getline(ss, savedParola);

        if (savedEmail == email) {
            if (savedParola == parola) {
                // Date corecte
                cout << "\n\nAutentificare reusita! Bine ai venit, " << email << "!\n";
                system("cls");
                return true;
            }
            else {
                // Parola gresita
                cout << "Parola gresita. Reincercati.\n";
                return false;
            }
        }
    }

    // Email inexistent
    cout << "Email inexistent. Reincercati.\n";
    return false;
}

// Functie pentru recuperarea parolei
// Trimite parola pe email daca adresa exista
void parolaUitata() {
    string email;
    cout << "=== Parola uitata ===\n";
    cout << "Introdu email: ";
    cin >> email;

    ifstream fin("utilizatori.txt");
    if (!fin) throw runtime_error("Nu s-a putut deschide utilizatori.txt");

    string linie, savedEmail, savedParola;
    while (getline(fin, linie)) {
        stringstream ss(linie);
        getline(ss, savedEmail, ',');
        getline(ss, savedParola);

        if (savedEmail == email) {
            string comanda = "python trimite_email.py " + email + " parola " + savedParola;
            system(comanda.c_str());

            cout << "Am trimis parola pe emailul dvs.\n";
            return;
        }
    }

    // Email inexistent
    cout << "Email inexistent. Reincercati.\n";
}

// Functia principala a aplicatiei
// Afiseaza meniul principal: Inregistrare, Autentificare, Parola uitata
int main() {
    try {
        // Incarcam lista de produse din fisier
        incarcaProduseDinFisier("produse.txt");
    }
    catch (const exception& e) {
        cout << "Eroare la incarcare produse: " << e.what() << "\n";
        return 1;
    }

    int optiune;
    bool autentificat = false;

    while (true) {
        if (!autentificat) {
            // Afisam meniul principal pentru utilizatorii neinregistrati
            cout << "\n----=== Magazin Online ===----\n\n";
            cout << "         1. Inregistrare\n";
            cout << "         2. Autentificare\n";
            cout << "         3. Parola uitata\n";
            cout << "         0. Iesire\n";
            cout << "\nAlege o optiune: ";

            try {
                if (!(cin >> optiune)) {
                    throw runtime_error("Trebuie sa introduci un numar!");
                }

                switch (optiune) {
                case 1:
                    inregistrare();
                    break;
                case 2:
                    autentificat = autentificare();
                    break;
                case 3:
                    parolaUitata();
                    break;
                case 0:
                    cout << "La revedere!\n";
                    return 0;
                default:
                    cout << "Optiune invalida. Reincercati.\n";
                }

            }
            catch (const exception& e) {
                // Tratare input invalid (ex: litere in loc de numere)
                cout << "Eroare: " << e.what() << "\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }

        }
        else {
            // Utilizator autentificat – acces la meniul secundar (produse, cos, comenzi)
            meniuUtilizatorAutentificat();
            autentificat = false; // dupa logout
        }
    }
}
