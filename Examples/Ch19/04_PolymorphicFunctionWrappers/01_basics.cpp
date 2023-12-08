import std;

using namespace std;

void func(int num, string_view str)
{
	println("func({}, {})", num, str);
}

void func2(const int& num, string_view str)
{
	println("func2({}, {})", num, str);
}

int main()
{
	{
		function<void(int, string_view)> f1{ func };
		f1(1, "test");
		
		f1 = func2;
		f1(1, "test");
	}

	{
		// With class template argument deduction
		function f1{ func };
		f1(1, "test");

		f1 = func2;
		f1(1, "test");
	}
}
