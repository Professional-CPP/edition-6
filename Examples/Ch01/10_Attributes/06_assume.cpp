import std;

using namespace std;

int divideBy32(int x)
{
	[[assume(x >= 0)]];
	return x / 32;
}

int main()
{
	println("Result: {}", divideBy32(64));
}
