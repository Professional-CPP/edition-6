#include "writeTextC.h"
#include "writeTextCpp.h"

void writeTextFromC(const char* text)
{
	// Delegate to writeTextFromCpp()
	writeTextFromCpp(text);
}
