import std;

using namespace std;


int main()
{
	{
		string s{ "Hello World!" };
		//println(s);   // Error! Does not compile.
		println("{}", s);
	}

	{
		constexpr auto formatString{ "Value: {}" };
		println(formatString, 11);  // Value: 11
	}
}