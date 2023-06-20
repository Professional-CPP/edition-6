import std;

using namespace std;

int main()
{
	{
		// width
		int i{ 42 };
		println("|{:5}|", i);       // |   42|
		println("|{:{}}|", i, 7);   // |     42|
		println("|{1:{0}}|", 7, i); // |     42|
	}

	println("");

	{
		// [fill]align
		int i{ 42 };
		println("|{:7}|", i);     // |     42|
		println("|{:<7}|", i);    // |42     |
		println("|{:_>7}|", i);   // |_____42|
		println("|{:_^7}|", i);   // |__42___|

		println("|{:=>16}|", "");  // |================|
	}

	println("");

	{
		// sign
		int i{ 42 };
		println("|{:<5}|", i);   // |42   |
		println("|{:<+5}|", i);  // |+42  |
		println("|{:< 5}|", i);  // | 42  |
		println("|{:< 5}|", -i); // |-42  |
	}

	println("");

	{
		// Integral types
		int i{ 42 };
		println("|{:10d}|", i);   // |        42|
		println("|{:10b}|", i);   // |    101010|
		println("|{:#10b}|", i);  // |  0b101010|
		println("|{:10X}|", i);   // |        2A|
		println("|{:#10X}|", i);  // |      0X2A|
	}

	println("");

	{
		// String types
		string s{ "ProCpp" };
		println("|{:_^10}|", s); // |__ProCpp__|
	}

	println("");

	{
		// Floating-point types
		double d{ 3.1415 / 2.3 };
		println("|{:12g}|", d);                         // |     1.36587|
		println("|{:12.2}|", d);                        // |         1.4|
		println("|{:12e}|", d);                         // |1.365870e+00|

		int width{ 12 };
		int precision{ 3 };
		println("|{2:{0}.{1}f}|", width, precision, d); // |       1.366|
		println("|{2:{0}.{1}}|", width, precision, d);  // |        1.37|
	}

	println("");

	{
		// 0
		int i{ 42 };
		println("|{:06d}|", i);   // |000042|
		println("|{:+06d}|", i);  // |+00042|
		println("|{:06X}|", i);   // |00002A|
		println("|{:#06X}|", i);  // |0X002A|
	}

	println("");

	{
		float f{ 1.2f };
		cout << format(std::locale{ "nl" }, "|{:Lg}|\n", f);  // |1,2|
	}

	println("");
}
