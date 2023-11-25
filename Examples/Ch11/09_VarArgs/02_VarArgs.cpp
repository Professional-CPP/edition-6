import std;
#include <cstdarg>
#include <cstdio>

using namespace std;

bool debug{ false };

void debugOut(const char* str, ...)
{
	if (debug) {
		va_list ap;
		va_start(ap, str);
		vfprintf(stderr, str, ap);
		va_end(ap);
	}
}

void printInts(unsigned num, ...)
{
	va_list ap;
	va_start(ap, num);
	for (unsigned i{ 0 }; i < num; ++i) {
		int temp{ va_arg(ap, int) };
		print("{} ", temp);
	}
	va_end(ap);
	println("");
}

int main()
{
	debug = true;
	debugOut("int %d\n", 5);
	debugOut("String %s and int %d\n", "hello", 5);
	debugOut("Many ints: %d, %d, %d, %d, %d\n", 1, 2, 3, 4, 5);

	printInts(5, 5, 4, 3, 2, 1);
}

