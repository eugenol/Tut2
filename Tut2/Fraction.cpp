/*Fraction Class Definition*/
#include <iostream>
#include "Fraction.h"

using namespace std;

	//Constructor
Fraction::Fraction() {
	numerator = 0;
	denominator = 1;
};

//Destructor
Fraction::~Fraction() {};

void Fraction::setNumerator(int num) 
{
	numerator = num;
};

void Fraction::setDenominator(int den) 
{
	denominator = den;
};

int Fraction::getNumerator(void) 
{
	return numerator;
};

int Fraction::getDenominator(void) 
{
	return denominator;
};

void Fraction::setFraction(int num, int den) 
{
	setNumerator(num);
	setDenominator(den);
};

void Fraction::print(void)
{
	int frac = numerator % denominator, whole = numerator / denominator;
	if (whole > 0)
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
};

Fraction Fraction::operator+(Fraction &b) 
{
	Fraction result;

	result.numerator = numerator*b.denominator + denominator*b.numerator;
	result.denominator = denominator*b.denominator;

	return result;
};

Fraction Fraction::operator-(Fraction &b) 
{
	Fraction result;

	result.numerator = numerator*b.denominator - denominator*b.numerator;
	result.denominator = denominator*b.denominator;

	return result;
};

Fraction Fraction::operator*(Fraction &b) 
{
	Fraction result;

	result.numerator = numerator*b.numerator;
	result.denominator = denominator*b.denominator;

	return result;
};

Fraction Fraction::operator/(Fraction &b) 
{
	Fraction result;

	result.numerator = numerator*b.denominator;
	result.denominator = denominator*b.numerator;

	return result;
};