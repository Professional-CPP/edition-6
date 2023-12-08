import std;

using namespace std;

void func(int num, string_view str)
{
	println("func({}, {})", num, str);
}

int main()
{
	// Bind second argument to a fixed value.
	string myString{ "abc" };
	//auto f1{ bind(func, placeholders::_1, myString) };
	auto f1{ [&myString](int num) { func(num, myString); } };
	f1(16);

	// Rearrange arguments
	//auto f2{ bind(func, placeholders::_2, placeholders::_1) };
	auto f2{ [](string_view str, int num) { func(num, str); } };
	f2("Test", 32);
}

