/*Fraction Class Definition*/
#include <iostream>
#include "Fraction.h"

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

int Fraction::getNumerator(void) 
{
	return numerator;
}

int Fraction::getDenominator(void) 
{
	return denominator;
}

void Fraction::setFraction(int num, int den) 
{
	setNumerator(num);
	setDenominator(den);
}

void Fraction::print(void)
{
	int frac = numerator % denominator, whole = numerator / denominator;
	if (whole != 0) //Mixed fraction
	{
		if (frac == 0)
			cout << whole;
		else
			cout << whole << "  " << frac << "/" << denominator;
	}
	else if (numerator == 0)
		cout << numerator;
	else
		cout << numerator << "/" << denominator;
}

Fraction Fraction::operator+(Fraction &b) 
{
	Fraction result;

	result.numerator = numerator*b.denominator + denominator*b.numerator;
	result.denominator = denominator*b.denominator;
	result = pretty(result); //neaten up the fraction

	return result;
}

Fraction Fraction::operator-(Fraction &b) 
{
	Fraction result;

	result.numerator = numerator*b.denominator - denominator*b.numerator;
	result.denominator = denominator*b.denominator;
	result = pretty(result); //neaten up the fraction

	return result;
}

Fraction Fraction::operator*(Fraction &b) 
{
	Fraction result;

	result.numerator = numerator*b.numerator;
	result.denominator = denominator*b.denominator;
	result = pretty(result); //neaten up the fraction

	return result;
}

Fraction Fraction::operator/(Fraction &b) 
{
	Fraction result;

	result.numerator = numerator*b.denominator;
	result.denominator = denominator*b.numerator;
	result = pretty(result); //neaten up the fraction

	return result;
}

int Fraction::gcd(int a, int b) //find the greatest common divisor, used in pretty to clean up the fractions
{
	//if (b == 0) return a;
	//else return gcd(b, a%b);

	int temp=a;
	while (b != 0)
	{
		temp = b;
		b = a%b;
		a = temp;
	}
	return temp;
}

Fraction Fraction::pretty(Fraction &Temp) // simplifies the fractions.
{
	Fraction retfrac;

	int a = Temp.numerator, b = Temp.denominator;

	a = a >= 0 ? a : -a;
	b = b >= 0 ? b : -b;

	int div = gcd(a, b);
	
	retfrac.numerator = Temp.numerator / div;
	retfrac.denominator = Temp.denominator / div;
	
	if(retfrac.denominator < 0)
	{
		retfrac.numerator*=-1;
		retfrac.denominator*=-1;
	}

	return retfrac;
}

ostream &operator<<(ostream &os, const Fraction &b)
{
	int frac = b.numerator % b.denominator, whole = b.numerator / b.denominator;

	if (whole != 0) //Mixed fraction
	{
		if (frac == 0)
			cout << whole;
		else
			cout << whole << "  " << frac << "/" << b.denominator;
	}
	else if (b.numerator== 0)
		cout << b.numerator;
	else
		cout << b.numerator << "/" << b.denominator;

	return os;
}
istream & operator>>(istream &is, Fraction &b)
{
	return is;
}