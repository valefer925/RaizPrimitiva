#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// funcion booleana para verificar si n es primo
bool EsPrimo(int n)
{
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;
	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	return true;
}

// funcion para realizar el calculo de x pow n mod p
int Power(int x, unsigned int y, int p)
{
	int resto = 1;
	x = x % p;
	while (y > 0)
	{
		if (y & 1)
			resto = (resto * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return resto;
}

// encontramos lo factores primos de n
void FindPrimefactors(unordered_set<int>& s, int n)
{
	while (n % 2 == 0)
	{
		s.insert(2);
		n = n / 2;
	}

	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			s.insert(i);
			n = n / i;
		}
	}
	if (n > 2)
		s.insert(n);
}

// Hallamos la raiz primitiva usando las antenriores funciones
int FindPrimitive(int n)
{
	unordered_set<int> s;
	if (EsPrimo(n) == false)
		return -1;
	int phi = n - 1;

	FindPrimefactors(s, phi);

	for (int r = 2; r <= phi; r++)
	{
		bool flag = false;
		for (auto it = s.begin(); it != s.end(); it++)
		{
			if (Power(r, phi / (*it), n) == 1)
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
			return r;
	}

	return -1;
}

int main()
{
	cout << "Ingrese el numero: ";
	int n;
	cin >> n;
	// si n no es primo 
	if (FindPrimitive(n) == -1)
	{
		cout << "No es primo" << endl;
		main();
	}
	// si n es primo
	else
		cout << "La raiz primitiva mas pequeña de " << n << " es " << FindPrimitive(n);




	return 0;
}