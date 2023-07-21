import std;

using namespace std;

int main()
{
	any empty;
	any anInt{ 3 };
	any aString{ "An std::string."s };

	println("empty.has_value = {}", empty.has_value());
	println("anInt.has_value = {}\n", anInt.has_value());

	println("anInt wrapped type = {}", anInt.type().name());
	println("aString wrapped type = {}\n", aString.type().name());

	int theInt{ any_cast<int>(anInt) };
	println("{}", theInt);
	try {
		int test{ any_cast<int>(aString) };
		println("{}", test);
	} catch (const bad_any_cast& ex) {
		println("Exception: {}", ex.what());
	}


	any something{ 3 };              // Now it contains an integer.
	something = "An std::string"s;   // Now the same instance contains a string.


	vector<any> v;
	v.push_back(42);
	v.push_back("An std::string"s);

	println("{}", any_cast<string>(v[1]));
}
