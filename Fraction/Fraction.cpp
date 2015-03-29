// Fraction.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Fraction.h"


// This is an example of an exported variable
FRACTION_API int nFraction=0;

// This is an example of an exported function.
FRACTION_API int fnFraction(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Fraction.h for the class definition
CFraction::CFraction()
{
	return;
}
