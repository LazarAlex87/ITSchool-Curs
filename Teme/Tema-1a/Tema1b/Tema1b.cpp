#include <iostream>
using namespace std;


unsigned int minim(unsigned int a, unsigned int b, unsigned int c) {  //return cel mai mic numar
    if (a <= b && a <= c) 
        return a;
    else if (b <= a && b <= c) 
        return b;
    else 
        return c;
}                       

unsigned double maxim(unsigned double a, unsigned double b, unsigned double c) {  //return cel mai mare numar
    if (a >= b && a >= c) 
        return a;
    else if (b >= a && b >= c) 
        return b;
    else 
        return c;
}

int main() {        //am notat pt exercitiile 10 si 12 in loc de a, b, c  cu   a1, a2 , a3 , b1 , b2 , b3 ...etc 
   
    unsigned int a1 = 7, b1 = 9, c1 = 3;
    unsigned int nrMic = minim(a1, b1, c1);
    cout << "Cel mai mic numar dintre " << a1 << ", " << b1 << ", si " << c1 << " este: " << nrMic << endl; 

    
    unsigned double a2 = 72.3, b2 = 1387.12344, c2 = 6;
    unsigned double nrMare = maxim(a2, b2, c2);
    cout << "Cel mai mare numar dintre " << a2 << ", " << b2 << ", si " << c2 << " este: " << nrMare << endl;
       
    const float a3 = 23.6;   
    float rezultat = a3 * 72;
    float comparare = 1500.3;

    cout << "Comparatie intre " << rezultat << " si " << comparare << ": \n";
    if (rezultat > comparare)
        cout << rezultat << " este mai mare." << endl;
    else
        cout << comparare << " este mai mare." << endl;

    //ex 13 nu am inteles exact cerinta
    double y = 2379.8909;
    float z = 11.4;
    int k = y / z;

    cout << "Rezultatul impartirii lui " << y << " la " << z << " este: " << k << " (numar intreg)" << endl;

    return 0;
}

