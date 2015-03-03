#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
	int numerator;
	int denominator;

public:
	Fraction();
	~Fraction();

	void setNumerator(int num);
	void setDenominator(int den);
	int getNumerator(void);
	int getDenominator(void);
	void setFraction(int num, int den);

	Fraction add(const Fraction &b);
	Fraction subtract(const Fraction &b);
	Fraction multiply(const Fraction &b);
	Fraction divide(const Fraction &b);

	/*Trying out operator overloading*/
	Fraction operator+(Fraction &b);
	Fraction operator-(Fraction &b);
	Fraction operator*(Fraction &b);
	Fraction operator/(Fraction &b);
};

#endif