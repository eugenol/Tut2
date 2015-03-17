#ifndef FRACTION_H
#define FRACTION_H

//#include <iostream>

using namespace std; //Omission of this line was causing the errors! Some people say use std::ostream etc.. instead of using namespace std.

class Fraction {
private:
	int numerator;
	int denominator;

	int gcd(int a, int b);
	Fraction  pretty();

public:
	Fraction();
	~Fraction();

	void setNumerator(int num);
	void setDenominator(int den);
	int getNumerator();
	int getDenominator();
	void setFraction(int num, int den);

	Fraction add(Fraction &b);
	Fraction subtract(Fraction &b);
	Fraction multiply(Fraction &b);
	Fraction divide(Fraction &b);

	Fraction operator+(Fraction &b);
	Fraction operator-(Fraction &b);
	Fraction operator*(Fraction &b);
	Fraction operator/(Fraction &b);
	Fraction operator=(Fraction &b);
	
	friend ostream &operator<<(ostream &, const Fraction &);
	friend istream &operator>>(istream &, Fraction &);
};
#endif