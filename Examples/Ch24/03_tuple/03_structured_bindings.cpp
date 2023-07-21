import std;

using namespace std;

int main()
{
	tuple t1{ 16, "Test"s, true };   // Using CTAD
	// Or:
	//tuple<int, string, bool> t1{ 16, "Test", true };

	auto [i, str, b] { t1 };
	println("Decomposed: i = {}, str = \"{}\", b = {}", i, str, b);

	println("Before: {}", t1);

	auto& [i2, str2, b2] { t1 };
	i2 *= 2;
	str2 = "Hello World";
	b2 = !b2;

	println("After: {}", t1);
}