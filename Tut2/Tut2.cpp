// Tut2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "Fraction.h"

using namespace std;

void print(Fraction);
Fraction read(void);

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
	res.print();

	res = frac1 - frac2;
	cout << endl << "Fraction 1 - Fraction 2 = ";
	res.print();

	res = frac1*frac2;
	cout << endl << "Fraction 1 * Fraction 2 = ";
	res.print();

	res = frac1 / frac2;
	cout << endl << "Fraction 1 / Fraction 2 = ";
	res.print();
	cout << endl;

	cout << "Enter mixed fraction";
	res = read();

	return 0;
}

Fraction read(void)
{
	Fraction b;
	string temp;
//	int whole;

	getline(cin,temp);

	if (temp.find(" ") != string::npos)
	{
		string temp2 = temp.substr(0, temp.find(" ") - 1);
		cout << temp2;
	}

	return b;
};