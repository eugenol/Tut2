// Tut2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "Fraction.h"

using namespace std;

void print(Fraction);
//Fraction read(void);

int main(int argc, char* argv[])
{
	Fraction frac1, frac2, res;
	int temp;

	cout << "Enter the numerator for fraction 1: ";
	cin >> temp;
	frac1.setNumerator(temp);

	cout << endl << "Enter the denominator for fraction 1: ";
	cin >> temp;
	frac1.setDenominator(temp);

	cout << endl << "Enter the numerator for fraction 2: ";
	cin >> temp;
	frac2.setNumerator(temp);

	cout << endl << "Enter the denominator for fraction 2: ";
	cin >> temp;
	frac2.setDenominator(temp);

	//With operator overloading

	res = frac1 + frac2;
	cout << endl << "Fraction 1 + Fraction 2 = ";
	print(res);

	res = frac1 - frac2;
	cout << endl << "Fraction 1 - Fraction 2 = ";
	print(res);

	res = frac1*frac2;
	cout << endl << "Fraction 1 * Fraction 2 = ";
	print(res);

	res = frac1 / frac2;
	cout << endl << "Fraction 1 / Fraction 2 = ";
	print(res);
	cout << endl;

	//read();

	return 0;
}


void print(Fraction temp)
{
	int frac = temp.getNumerator()%temp.getDenominator(), whole = temp.getNumerator() / temp.getDenominator();
	if (whole > 0)
	{
	if (frac == 0)
	cout << whole;
	else
		cout << whole << "  " << frac << "/" << temp.getDenominator();
	}
	else if (temp.getNumerator() == 0)
		cout << temp.getNumerator();
	else
		cout << temp.getNumerator() << "/" << temp.getDenominator();
};
/*
Fraction read(string temp)
{
	Fraction b;
	string temp;
	int whole;

	getline(cin,temp);

	cout << temp;

	return b;
};*/