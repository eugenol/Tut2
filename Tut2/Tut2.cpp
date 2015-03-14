// Tut2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "Fraction.h"

using namespace std;

Fraction readfraction(void);

int main(int argc, char* argv[])
{
	Fraction frac1, frac2, res;

	cout << "Enter fraction 1: ";
	cin >> frac1;
	// Loop until the fraction is read in correctly.
	while (cin.fail())
	{
		cout << "Error: Can not have zero in the denominator" << std::endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter fraction 1: ";
		cin >> frac1;
	}


	cout << "Enter fraction 2: ";
	cin >> frac2;
	// Loop until the fraction is read in correctly.
	while (cin.fail())
	{
		cout << "Error: Can not have zero in the denominator" << std::endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter fraction 2: ";
		cin >> frac2;
	}

	//run test cases with +,-,*,/ operators

	res = frac1 + frac2;
	cout << endl << "Fraction 1 + Fraction 2 = ";
	cout << res << endl;

	res = frac1 - frac2;
	cout << "Fraction 1 - Fraction 2 = ";
	cout << res << endl;

	res = frac1*frac2;
	cout << "Fraction 1 * Fraction 2 = ";
	cout << res<<endl;

	res = frac1 / frac2;
	cout << "Fraction 1 / Fraction 2 = ";
	cout << res<<endl;

	return 0;
}