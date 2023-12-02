import std;

using namespace std;

class Squarer
{
public:
	int operator()(int value) const;       // First overloaded function call operator.
	int doSquare(int value) const;         // Normal member function.
	double operator()(double value) const; // Second overloaded function call operator.
};

// Implementation of first overloaded function call operator.
int Squarer::operator()(int value) const
{
	return doSquare(value);
}

// Implementation of normal member function.
int Squarer::doSquare(int value) const
{
	return value * value;
}

// Implementation of second overloaded function call operator.
double Squarer::operator()(double value) const
{
	return value * value;
}

int main()
{
	int x{ 3 };
	Squarer square;

	int xSquared{ square(x) };                      // Call the function call operator.
	int xSquaredAgain{ square.doSquare(xSquared) }; // Call the normal member function.

	println("{} squared is {}, and squared again is {}.", x, xSquared, xSquaredAgain);

	double d{ 1.23 };
	double dSquared{ square(d) };
	println("{} squared is {}.", d, dSquared);
}

