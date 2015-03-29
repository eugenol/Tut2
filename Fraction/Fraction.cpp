// Fraction.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Fraction.h"


// This is an example of an exported variable
//FRACTION_API int nFraction=0;

// This is an example of an exported function.
//FRACTION_API int fnFraction(void)
//{
//	return 42;
//}

using namespace std;


//Constructor
Fraction::Fraction() {
	numerator = 0;
	denominator = 1;
}

//Destructor
Fraction::~Fraction() {};

void Fraction::setNumerator(int num)
{
	numerator = num;
}

void Fraction::setDenominator(int den)
{
	denominator = den;
}

int Fraction::getNumerator()
{
	return numerator;
}

int Fraction::getDenominator()
{
	return denominator;
}

void Fraction::setFraction(int num, int den)
{
	setNumerator(num);
	setDenominator(den);
}

Fraction Fraction::add(Fraction &b)
{
	Fraction result;

	result.numerator = numerator*b.denominator + denominator*b.numerator;
	result.denominator = denominator*b.denominator;

	return result;
}

Fraction Fraction::subtract(Fraction &b)
{
	Fraction result;

	result.numerator = numerator*b.denominator - denominator*b.numerator;
	result.denominator = denominator*b.denominator;

	return result;
}

Fraction Fraction::multiply(Fraction &b)
{
	Fraction result;

	result.numerator = numerator*b.numerator;
	result.denominator = denominator*b.denominator;

	return result;
}

Fraction Fraction::divide(Fraction &b)
{
	Fraction result;

	result.numerator = numerator*b.denominator;
	result.denominator = denominator*b.numerator;

	return result;
}

Fraction Fraction::operator+(Fraction &b)
{
	Fraction result;

	result.numerator = numerator*b.denominator + denominator*b.numerator;
	result.denominator = denominator*b.denominator;

	return result;
}

Fraction Fraction::operator-(Fraction &b)
{
	Fraction result;

	result.numerator = numerator*b.denominator - denominator*b.numerator;
	result.denominator = denominator*b.denominator;

	return result;
}

Fraction Fraction::operator*(Fraction &b)
{
	Fraction result;

	result.numerator = numerator*b.numerator;
	result.denominator = denominator*b.denominator;

	return result;
}

Fraction Fraction::operator/(Fraction &b)
{
	Fraction result;

	result.numerator = numerator*b.denominator;
	result.denominator = denominator*b.numerator;

	return result;
}

// Is this neccessary? It worked without it.
Fraction Fraction::operator=(Fraction &b)
{
	numerator = b.numerator;
	denominator = b.denominator;
	return *this;
}

int Fraction::gcd(int a, int b) //find the greatest common divisor, used in pretty to clean up the fractions
{
	//if (b == 0) return a;
	//else return gcd(b, a%b);

	int temp = a;
	while (b != 0)
	{
		temp = b;
		b = a%b;
		a = temp;
	}
	return temp;
}

Fraction Fraction::pretty() // simplifies the fractions.
{
	Fraction retfrac;

	int a = numerator, b = denominator;

	a = a >= 0 ? a : -a;
	b = b >= 0 ? b : -b;

	int div = gcd(a, b);

	retfrac.numerator = numerator / div;
	retfrac.denominator = denominator / div;

	if (retfrac.denominator < 0)
	{
		retfrac.numerator *= -1;
		retfrac.denominator *= -1;
	}

	return retfrac;
}

extern ostream &operator<<(ostream &os, const Fraction &b)
{
	if (b.denominator != 0) // ugly fix for now, avoid dividing by zero.
	{
		Fraction reduced = b;
		reduced = reduced.pretty();

		int frac = reduced.numerator % reduced.denominator, whole = reduced.numerator / reduced.denominator;

		if (whole != 0) //Mixed fraction
		{
			if (frac == 0)
				cout << whole;
			else
				cout << whole << "  " << frac << "/" << reduced.denominator;
		}
		else if (reduced.numerator == 0)
			cout << reduced.numerator;
		else
			cout << reduced.numerator << "/" << reduced.denominator;
	}
	else
		cout << "Error. Division by zero has occurred!";

	return os;
}

extern istream & operator>>(istream &is, Fraction &b)
{
	char slash = 0, temp;
	int whole = 0, num = 0, den = 1;
	cin >> whole;
	cin.get(temp);
	if (temp == '/')
	{
		cin >> den;
		num = whole;
		if (den == 0)
			is.setstate(ios::failbit); // error if denominator is zero.
	}
	else if (temp == ' ')
	{
		cin >> num >> slash >> den;
		num += whole*den;
		if (den == 0)
			is.setstate(ios::failbit); // error if denominator is zero.
	}
	else if (temp == '\n')
		num = whole;

	b.numerator = num;
	b.denominator = den;

	return is;
}