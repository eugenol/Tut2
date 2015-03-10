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

	cout << "Enter the fraction 1: ";
	cin >> frac1;

	cout << "Enter the fraction 2: ";
	cin >> frac2;

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



Fraction readfraction()
{
	Fraction b;
	string temp;
	int whole = 0, num = 0, den = 1;

	getline(cin,temp);

	if (temp.find(" ") != string::npos) //Check if there is a space, if there is, then most likely a mixed fraction.
	{
		int pos = temp.find(" ");
		string temp2 = temp.substr(0, pos); //read in whole number part
		whole = stoi(temp2);

		if (temp.find("/", pos + 1) != string::npos) // read in fraction part
		{
			int pos2 = temp.find("/", pos + 1);
			temp2 = temp.substr(pos + 1, pos2);
			num = stoi(temp2);
			temp2 = temp.substr(pos2 + 1);
			num = stoi(temp2);

			b.setNumerator(whole*den + num);
			b.setDenominator(den);

		}
		else
			b.setNumerator(whole); //in case there was no fraction
	}
	else if (temp.find("/") != string::npos) //not a mixed fraction, fraction only
	{
			int pos = temp.find("/");
			string temp2 = temp.substr(0, pos);
			num = stoi(temp2);
			temp2 = temp.substr(pos + 1);
			den = stoi(temp2);


			b.setNumerator(num);
			b.setDenominator(den);
	}
	else //in case there is no fraction, read in whole number. 
	{
		num = stoi(temp);
		b.setNumerator(num); // denominator is set to one in the constructor
	}

	return b;
};