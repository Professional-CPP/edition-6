import std;

using namespace std;

int main()
{
	{
		string a{ "12" };
		string b{ "34" };
		string c{ a + b };    // c is "1234"
		println("{}", c);

		a += b;    // a is "1234"
		println("{}", a);
	}

	println("");

	{
		string a{ "Hello" };
		string b{ "World" };
		println("'{}' < '{}' = {}", a, b, a < b);
		println("'{}' > '{}' = {}", a, b, a > b);
	}

	println("");

	{
		string a{ "12" };
		string b{ "34" };

		auto result{ a.compare(b) };
		if (result < 0) { println("less"); }
		if (result > 0) { println("greater"); }
		if (result == 0) { println("equal"); }
	}

	println("");

	{
		// C++20 three-way comparison operator
		string a{ "12" };
		string b{ "34" };
		auto result{ a <=> b };
		if (is_gt(result)) { println("greater"); }
		if (is_lt(result)) { println("less"); }
		if (is_eq(result)) { println("equal"); }
	}

	println("");

	{
		string myString{ "hello" };

		myString += ", there";

		string myOtherString{ myString };

		if (myString == myOtherString) {
			myOtherString[0] = 'H';
		}

		println("{}", myString);
		println("{}", myOtherString);
	}

	println("");

	{
		string strHello{ "Hello!!" };
		string strWorld{ "The World..." };
		auto position{ strHello.find("!!") };
		if (position != string::npos) {
			// Found the "!!" substring, now replace it.
			strHello.replace(position, 2, strWorld.substr(3, 6));
		}
		println("{}", strHello);

		// Test contains().
		string toFind{ "World" };
		println("{}", strWorld.contains(toFind));  // true
		println("{}", strWorld.contains('.'));     // true
		println("{}", strWorld.contains("Hello")); // false
	}
	
	println("");

	{
		auto string1{ "Hello World" };    // string1 is a const char*.
		auto& string2{ "Hello World" };   // string2 is a const char[12].
		auto string3{ "Hello World"s };   // string3 is an std::string.
	}
}
