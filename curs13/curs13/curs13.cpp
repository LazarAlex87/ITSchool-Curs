#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Film {
private:
    string nume;
    double rating;
    int vazut;
public:
    
    Film(const string& nume, double rating, int vazut)
        : nume(nume), rating(rating), vazut(vazut) {}

    
    string get_nume() const { return nume; }
    double get_rating() const { return rating; }
    int get_vazut() const { return vazut; }
        
    void incrementare_vizionari() { vazut++; }
        
    void afisare() const {
        cout << "Film: " << nume << ", Rating: " << rating
                  << ", Vazut de " << vazut << " ori\n";
    }
};
class Colectie {
private:
    vector<Film> filme;

public:
    void adauga_film(const string& nume, double rating, int vazut) {
        for (const auto& film : filme) {
            if (film.get_nume() == nume) {
                cout << "Film deja existent in colectie!\n";
                return;
            }
        }
        
        filme.emplace_back(nume, rating, vazut);
        cout << "Film adaugat cu succes!\n";
    }

    void incrementare_vizionari(const string& nume) {
        for (auto& film : filme) {
            if (film.get_nume() == nume) {
                film.incrementare_vizionari();
                cout << "Vizionari incrementate pentru filmul: " << nume << "\n";
                return;
            }
        }
        cout << "Filmul nu a fost gasit in colectie!\n";
    }
        
    void afisare_colectie() const {
        if (filme.empty()) {
            cout << "Colectia este goala!\n";
            return;
        }
        for (const auto& film : filme) {
            film.afisare();
        }
    }
};

int main() {
    Colectie colectie;
    int optiune;

    do {
        cout << "\nMeniu:\n";
        cout << "1. Adauga film\n";
        cout << "2. Incrementare vizionari\n";
        cout << "3. Afisare colectie\n";
        cout << "4. Iesire\n";
        cout << "\nAlege o optiune: ";
        cin >> optiune;

        switch (optiune) {
        case 1: {
            string nume;
            double rating;
            int vazut;

            cout << "Introdu numele filmului: ";
            cin.ignore(); 
            getline(cin, nume);

            cout << "Introdu rating-ul filmului: ";
            cin >> rating;

            cout << "De cate ori a fost vazut: ";
            cin >> vazut;

            colectie.adauga_film(nume, rating, vazut);
            break;
        }
        case 2: {
            string nume;

            cout << "Introdu numele filmului pentru incrementare: ";
            cin.ignore(); 
            getline(cin, nume);

            colectie.incrementare_vizionari(nume);
            break;
        }
        case 3:
            colectie.afisare_colectie();
            break;

        case 4:
            cout << "Iesire...\n";
            break;

        default:
            cout << "Optiune invalida!\n";
        }

    } while (optiune != 4);

    return 0;
}