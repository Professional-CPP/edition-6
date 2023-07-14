import std;

using namespace std;

void func(int num, string_view str)
{
	println("func({}, {})", num, str);
}

int main()
{
	auto f5{ bind_front(func, 42) };
	f5("Hello");

	auto f6{ bind_back(func, "Hello") };
	f6(42);
}
