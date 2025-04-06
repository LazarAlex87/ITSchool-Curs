#include <iostream>
using namespace std;

void meniuUtilizatorAutentificat() {
    int optiune;

    do {
        cout << "\n----=== Meniu Utilizator ===----\n\n\n";
        cout << "      1. Lista Produse\n";
        cout << "      2. Cos de cumparaturi\n";
        cout << "      3. Finalizare comanda\n";
        cout << "      0. Deconectare\n";
        cout << "\n\nAlege o optiune: ";
        cin >> optiune;

        switch (optiune) {
        case 1:
            cout << "Afisam lista de produse...\n";
            break;
        case 2:
            cout << "Afisam cosul de cumparaturi...\n";
            break;
        case 3:
            cout << "Finalizam comanda...\n";
            break;
        case 0:
            cout << "Te-ai deconectat cu succes.\n";
            break;
        default:
            cout << "Optiune invalida. Reincercati.\n";
        }
    } while (optiune != 0);
}
