// 2.Sa se scrie o aplicatie care calculeaza cel mai mare divizor comun a 2 numere citite de la tastatura.

#include <iostream>
using namespace std;

int divizor(int a, int b) 
{
    while (b != 0) 
    {
        int rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}

int main() 
{
    int myNumber, myNumber1;

    cout << "Introduceti primul numar: " << endl;
    cin >> myNumber >> myNumber1;

    int rezultat = divizor(myNumber, myNumber1);
    cout << "Cel mai mare divizor comun al numerelor " << myNumber << " si " << myNumber1 << " este: " << rezultat << endl;

    return 0;
}