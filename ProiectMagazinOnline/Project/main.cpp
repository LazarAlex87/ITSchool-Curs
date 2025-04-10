#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "meniu_utilizator.h"

using namespace std;

void inregistrare() {
    string email;
    cout << "=== Inregistrare ===\n";
    cout << "Introdu email: ";
    cin >> email;

    //generam un cod random intre 10000 si 99999 pt a fi trimis pe email
    srand(time(0));
    int cod = rand() % 90000 + 10000; 

    //trimite codul pe email
    string comanda = "python trimite_email.py " + email + " cod " + to_string(cod);
    system(comanda.c_str());

    cout << "Am trimis un cod de verificare pe emailul tau.\n";
    cout << "Introdu codul primit: ";
    int cod_introdus;
    cin >> cod_introdus;

    if (cod_introdus == cod) {
        string parola;
        cout << "Cod corect! Acum seteaza parola: ";
        cin >> parola;

        ofstream fout("utilizatori.txt", ios::app);
        if (fout.is_open()) {
            fout << email << "," << parola << "\n";
            fout.close();
            cout << "Cont creat cu succes!\n";
        }
        else {
            cout << "Eroare la deschiderea fisierului!\n";
        }
    }
    else {
        cout << "Cod incorect. Inregistrare esuata.\n";
    }
}

bool autentificare() {
    string email, parola;
    cout << "=== Autentificare ===\n";
    cout << "Introdu email: ";
    cin >> email;
    cout << "Introdu parola: ";
    cin >> parola;

    ifstream fin("utilizatori.txt");
    string linie, savedEmail, savedParola;

    if (fin.is_open()) {
        while (getline(fin, linie)) {
            stringstream ss(linie);
            getline(ss, savedEmail, ',');
            getline(ss, savedParola);

            if (savedEmail == email) {
                if (savedParola == parola) {
                    cout << "\n\nAutentificare reusita! Bine ai venit, " << email << "!\n";
                    return true;
                }
                else {
                    cout << "Parola gresita. Reincercati.\n";
                    return false;
                }
            }
        }
        cout << "Email inexistent. Reincercati.\n";
        return false;
    }
    else {
        cout << "Eroare la deschiderea fisierului!\n";
        return false;
    }
}

void parolaUitata() {
    string email;
    cout << "=== Parola uitata ===\n";
    cout << "Introdu email: ";
    cin >> email;

    ifstream fin("utilizatori.txt");
    string linie, savedEmail, savedParola;

    if (fin.is_open()) {
        while (getline(fin, linie)) {
            stringstream ss(linie);
            getline(ss, savedEmail, ',');
            getline(ss, savedParola);

            if (savedEmail == email) {
                string comanda = "python trimite_email.py " + email + " parola " + savedParola;
                system(comanda.c_str());

                cout << "Am trimis parola pe emailul dvs.!\n";
                return;
            }
        }
        cout << "Email inexistent. Reincercati.\n";
    }
    else {
        cout << "Eroare la deschiderea fisierului!\n";
    }
}


int main() {
    int optiune;
    bool autentificat = false;

    while (true) {
        if (!autentificat) {
            cout << "\n----=== Magazin Online ===----\n\n\n";
            cout << "         1. Inregistrare\n";
            cout << "         2. Autentificare\n";
            cout << "         3. Parola uitata\n";
            cout << "         0. Iesire\n";
            cout << "\n\nAlege o optiune: ";
            cin >> optiune;

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
        else {
            meniuUtilizatorAutentificat();
            autentificat = false; 
        }
    }
}
