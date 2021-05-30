#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

#include "matrix.h"
#include "matrix.cpp"


 
int main(){
	srand(time(NULL));


	int n, m;
	cout << "Podaj wymiary pierwszej macierzy:\n";
	cin >> n >> m;


	Matrix a(n, m, "Pierwsza");
	cout << "Wypelnij macierz: ";
	cin >> a;
	cout << "Pierwsza macierz:\n" << a;


	cout << "Podaj wymiary drugiej macierzy:\n";
	cin >> n >> m;
	Matrix b(n, m, "Druga");
	cout << "Druga macierz:\n" << b;

	Matrix c = a + b;
	cout << "Dodawanie macierzy:\n" << c;

	c = a * b;
	if(c.getColumns())
		cout << "Mnozenie macierzy:\n" << c;

	int k = 0;
	cout << "Podaj mnoznik:";
	cin >> k;
	c = a * k;
	cout << "Mnozenie macierzy przez liczbe:\n" << c;

	c = transpose(a);
	cout << "Transpozycja macierzy:\n" << c;

	return 0;
}
