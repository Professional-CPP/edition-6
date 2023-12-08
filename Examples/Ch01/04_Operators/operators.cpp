import std;

using namespace std;

int main()
{
	int someInteger{ 256 };
	short someShort;
	long someLong;
	float someFloat;
	double someDouble;

	someInteger++;
	someInteger *= 2;
	// Conversion from larger integer type to smaller integer type
	// can cause a warning or error, hence static_cast() is required.
	someShort = static_cast<short>(someInteger);
	someLong = someShort * 10000;
	someFloat = someLong + 0.785f;
	// To make sure the division is performed with double precision,
	// someFloat is explicitly converted to double first.
	someDouble = static_cast<double>(someFloat) / 100000;

	println("{}", someDouble);
}
