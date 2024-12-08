#include "writeTextCpp.h"
#include <print>

using namespace std;

void writeTextFromCpp(const char* text)
{
	println("C++ is writing:");
	println("{}", text);
}