import std;

using namespace std;

int main()
{
	pair<int, string> p1{ 16, "Hello World" };
	pair p2{ true, 0.123f };
	println("p1 = ({}, {})", p1.first, p1.second);
	println("p2 = ({}, {})", p2.first, p2.second);

	// Starting with C++23, println() has full support for pair.
	println("p1 = {}", p1);
	println("p2 = {}", p2);
}
