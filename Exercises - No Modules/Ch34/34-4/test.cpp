#include "writeTextC.h"

int main()
{
	// This calls a C function called writeTextFromC()
	// that will then call a C++ function called writeTextFromCpp().
	writeTextFromC("Hello World!");
}