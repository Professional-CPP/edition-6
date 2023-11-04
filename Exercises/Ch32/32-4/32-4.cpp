import std;

using namespace std;

int main()
{
	auto sum{ [] <typename T> (const T& a, const T& b) { return a + b; } };
	println("{}", sum(11, 22));
	println("{}", sum(1.1, 2.2));
	println("{}", sum("Hello "s, "world!"s));
	//println("{}", sum("Hello "s, 1)); // Doesn't work, different types.
}