//1. Folosind structuri, apoi puteti sa folositi clase. La o statie meteo se trec temperaturile inregistrate intr-o saptamana.
//Sa se prelucreze aceste date afiaandu-se zilele in care temperatura a fost maxima.
//2. Se considera un program care descrie organizarea personalului unei institutii folosind clase.
//O clasa numita Angajat detine date si functii referitoare la un angajat al institutiei.

/*ex1
#include <iostream>
#include <vector>
using namespace std;

struct Zi {
    string nume;
    double temperatura;
};

void afisareZileTemperaturaMaxima(const vector<Zi>& zile) 
{
    double maxTemp = zile[0].temperatura;
    
    for (const auto& zi : zile) {
        if (zi.temperatura > maxTemp) {
            maxTemp = zi.temperatura;
        }
    }

    cout << "Zilele cu temperatura maxima (" << maxTemp << " grade):\n";
    for (const auto& zi : zile) {
        if (zi.temperatura == maxTemp) {
            cout << zi.nume << endl;
        }
    }
}

int main() 
{
    vector<Zi> saptamana = {
                                 {"Luni", 10.5},
                                 {"Marti", 11.1},
                                 {"Miercuri", 18.7},
                                 {"Joi", 19.1},
                                 {"Vineri", 19.2},
                                 {"Sambata", 19.1},
                                 {"Duminica", 19.2}
                           };

    afisareZileTemperaturaMaxima(saptamana);

    return 0;
}
*/

//ex2
#include <iostream>
#include <string>
using namespace std;

class Angajat {
private:
    string nume;
    float salariu;
    int nrore;

public:
    void numeAngajat() 
    {
        nume = "Popescu ";
    }

   
    float getSalariu() 
    {
        const float salarPeOra = 15.0;
        cout << "Popescu are " << salarPeOra << " lei castig pe ora. \nIntroduceti cate ore a lucrat Popescu: " << endl;
        cin >> nrore;
        salariu = nrore * salarPeOra;
        return salariu;
    }

    void display() 
    {
        cout << "Angajatul " << nume << "a castigat " << salariu << " lei, pentru " << nrore << " ore lucrate" << endl;
    }
};

int main() 
{
    Angajat Salariat;

    Salariat.numeAngajat();   
    Salariat.getSalariu();    
    Salariat.display();       

    return 0;
}
