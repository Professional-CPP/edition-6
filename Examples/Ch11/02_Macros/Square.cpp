import std;

using namespace std;

#define SQUARE(x) ((x) * (x)) // No semicolon after the macro definition!
//#define SQUARE(x) (x * x)

int main()
{
	println("{}", SQUARE(5));
	println("{}", SQUARE(2 + 3));
}
