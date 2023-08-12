import std;

using namespace std;

int main()
{
	auto sum{ [](auto a, auto b) { return a + b; } };
	println("{}", sum(11, 22));
	println("{}", sum(1.1, 2.2));
	println("{}", sum("Hello "s, "world!"s));
}