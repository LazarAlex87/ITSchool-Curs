// 1.Sa se scrie o aplicatie care verifica daca un numar n, citit de la tastatura, este prim sau nu.

#include <iostream>
using namespace std;

bool nrPrim(int n)
{
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;

	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int main()
{
	int n;
	cout << "Introduceti un numar: " << endl;
	cin >> n;
	if (nrPrim(n))
		cout << "Numarul introdus este PRIM" << endl;
	else
		cout << "Numarul introdus NU este Prim" << endl;

	return 0;
}
