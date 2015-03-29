// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the FRACTION_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// FRACTION_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef FRACTION_EXPORTS
#define FRACTION_API __declspec(dllexport)
#else
#define FRACTION_API __declspec(dllimport)
#endif

// This class is exported from the Fraction.dll
class FRACTION_API CFraction {
public:
	CFraction(void);
	// TODO: add your methods here.
};

extern FRACTION_API int nFraction;

FRACTION_API int fnFraction(void);
