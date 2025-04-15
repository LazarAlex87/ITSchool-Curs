#include <iostream>
#include <string>
using namespace std;

//1.Scrieti un program pentru a stoca n elemente intr-un array si afisati elementele folosind un pointer.
//2.Scrieti un program pentru a gasi factorialul unui numar dat folosind pointeri.
//3.Scrieti un program pentru a numara numarul de vocale si consoane dintr-un sir folosind un pointer.
//4.Scrieti un program pentru a afisa in ordine crescatoare elementele unui array citit de la tastatura folosind un pointer.

int main()
{
    cout << "...---=== Exercitiul 1 ====---...." << endl;
    cout << "__________________________________" << endl;

    int n, sortare;

    cout << "Introduceti cate elemente doriti in Array: " << endl;
    cin >> n;

    int* array = new int[n];

    cout << "Introduceti elementele:" << endl;
    for (int i = 0; i < n; ++i) 
        cin >> array[i];
    
    cout << "Elementele din Array sunt:" << endl;
    
    for (int i = 0; i < n; ++i) 
        cout << *(array + i) << "" << endl;
    
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int sort = 0; sort < n - i - 1; sort++)
        {
            if (array[sort] > array[sort + 1])
            {
                sortare = array[sort];
                array[sort] = array[sort + 1];
                array[sort + 1] = sortare;
            }
        }
    }

    cout << "Acum sunt si ordonate crescator pentru exercitiul 4 :) : " << endl;

    for (int i = 0; i < n; i++) 
        cout << array[i] << endl;


    cout << "...---=== Exercitiul 2 ====---...." << endl;
    cout << "__________________________________" << endl;

    int f;
    int factorial = 1;
    int* pt = &factorial;

    cout << "Introduceti un numar: ";
    cin >> f;

    for (int j = 1; j <= f; ++j) 
        *pt *= j; 
    

    cout << "Factorialul lui " << f << " este: " << *pt << endl;

    cout << "...---=== Exercitiul 3 ====---...." << endl;
    cout << "__________________________________" << endl;

    char str[100];
    int voc = 0, cons = 0;

    cin.ignore(); 

    cout << "Introduceti un sir de caractere: ";
    cin.getline(str, 100);

    char* ptr = str;

    while (*ptr != '\0') {
        if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z')) 
        {
                if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u' ||
                    *ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U') 
                    ++voc;
                else 
                    ++cons;
        }
        ++ptr;
    }
        
    cout << "Numar vocale: " << voc << endl;
    cout << "Numar consoane: " << cons << endl;

    cout << " ....----=== Exercitiul 4 ====----...." << endl;
    cout << "___---=== Rezolvarea la ex 1 ===---___" << endl;
    
    
    return 0;
}