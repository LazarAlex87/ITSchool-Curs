/* 3.Sa se scrie o aplicatie care calculeaza suma produselor cumparate(sa avem aprox 20 de produse cu pretul dat de voi deja stabilit)
   si de la tastatura spunem ce vrem sa cumpram(ex mere pere si paine, daca produsul nu exista sa retuneze(nu mai avem pe stock)) si sa
   ne returneze suma totata ce o avem de platit.apoi introducem suma ce o dam "vanzatoarei" si ne returneaza restul pe care trebuie sa il primim.*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cumparaturi;
    string produse[] = { "mere", "pere", "paine", "lapte", "faina", "ulei", "zahar",
                         "cafea", "ceai", "banane", "portocale", "struguri", "iaurt",
                         "unt", "salam", "branza", "apa", "suc", "covrigi", "conserva" };
    double preturi[] = { 3.5, 3.8, 5.5, 4.0, 5.6, 7.5, 22.2,
                         1.8, 12.0, 3.5, 8.5, 14.0, 6.0,
                         7.3, 15.0, 10.0, 5.0, 8.0, 3.0, 27.5 };
    int numarProduse = sizeof(produse) / sizeof(produse[0]);

    cout << "Avem disponibile urmatoarele produse: \nmere, pere, paine, lapte, faina, ulei, zahar, \ncafea, ceai, banane, portocale, struguri, iaurt, \nunt, salam, branza, apa, suc, covrigi, conserva" << endl;
    cout << "Alegeti ce doriti sa cumparati: " << endl;
    getline(cin, cumparaturi);

    double total = 0.0;
    string produs = "";
    int i = 0;

    //Parcurgem fiecare caracter al listei "cumparaturi". Cand gasim un caracter diferit de ' ' il adaugam la produs,
    //si cand gasim ' ' sau ajungem la sf, inseamna ca avem un cuvant complet

    while (i <= cumparaturi.size())
        {
        if (i < cumparaturi.size() && cumparaturi[i] != ' ')
        {
            produs += cumparaturi[i];
        }
        else
        {
            bool gasit = false;
            for (int j = 0; j < numarProduse; j++)
            {
                if (produse[j] == produs)
                {
                    total += preturi[j];
                    gasit = true;
                    break;
                }
            }

            if (!gasit && !produs.empty())
            {
                cout << "Produsul '" << produs << "' nu mai este pe stoc." << endl;
            }

            produs = "";
        }
        i++;
    }

    cout << "Suma totala de platit este: " << total << " lei" << endl;

    double sumaPlatita;
    cout << "Introduceti suma platita: " << endl;
    cin >> sumaPlatita;

    if (sumaPlatita >= total)
    {
       double rest = sumaPlatita - total;
       cout << "Restul de primit: " << rest << " lei" << endl;
    }

    return 0;

}
