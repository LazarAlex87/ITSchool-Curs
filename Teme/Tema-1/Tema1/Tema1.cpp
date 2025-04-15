#include <iostream>
#include <string>
using namespace std;

void my_func_rezolvare_ex123() {
	//Rezolvare exercitii 1 2 3

	int myNumber = 50;
	float myNumber1 = 75.5;
	myNumber++ ;
	myNumber1-- ;

	cout << "myNumber dupa incrementare: " << myNumber << endl;
	cout << "myNumber1 dupa decrementare: " << myNumber1 << endl;
}


int my_func_rezolvare_ex45(int a, float b) {

	int suma = static_cast<int>(a + b);
	float sumareal = a + b;                   //ex 4

	float rezultatSuma = (suma * 5) / 12.0;
	float rezultatSumareal = (sumareal * 5) / 12.0;
	float rest = rezultatSumareal - (int)rezultatSumareal;   //ex 5

	cout << "Partea fractionala a impartirii pentru sumareal: " << rest << endl;

	return 0;
}

int my_func_rezolvare_ex6789() {
	
	string nume = "Lazar";							//ex 6
	string prenume = "Alex";						//ex 7
	string nume_complet = nume + " " + prenume;		//ex 8

	cout << "Nume complet: " << nume_complet << endl;


	string sirul_meu = "Acesta este continutul initial al sirului";   //ex 9
	cout << sirul_meu << endl;
	
	return 0;
}

int main() {

	int a = 50;
	float b = 75.5;

	my_func_rezolvare_ex123();
	my_func_rezolvare_ex45(a, b);
	my_func_rezolvare_ex6789();

	return 0;
}

