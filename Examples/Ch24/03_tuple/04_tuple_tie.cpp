import std;

using namespace std;

int main()
{
	tuple t1{ 16, "Test"s, true };  // Using CTAD
	// Or:
	//tuple<int, string, bool> t1{ 16, "Test", true };

	{
		int i{ 0 };
		string str;
		bool b{ false };
		println("Before: i = {}, str = \"{}\", b = {}", i, str, b);
		tie(i, str, b) = t1;
		println("After: i = {}, str = \"{}\", b = {}", i, str, b);
	}

	{
		int i{ 0 };
		bool b{ false };
		println("Before: i = {}, b = {}", i, b);
		tie(i, ignore, b) = t1;
		println("After: i = {}, b = {}", i, b);
	}
}