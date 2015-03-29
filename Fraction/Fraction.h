// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the FRACTION_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// FRACTION_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifndef FRACTION_H
#define FRACTION_H

#ifdef FRACTION_EXPORTS
#define FRACTION_API __declspec(dllexport)
#else
#define FRACTION_API __declspec(dllimport)
#endif

#include <iostream>

// This class is exported from the Fraction.dll

class FRACTION_API Fraction {
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

	extern friend std::ostream &operator<<(std::ostream &, const Fraction &);
	extern friend std::istream &operator>>(std::istream &, Fraction &);
};
#endif


//extern FRACTION_API int nFraction;

//FRACTION_API int fnFraction(void);
