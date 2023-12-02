import std;

using namespace std;

// A class representing a length. The length is always stored in meters.
class Length
{
public:
	long double getMeters() const { return m_length; }

	// The user-defined literals _km and _m are friends of Length so they
	// can use the private constructor.
	friend Length operator ""_km(long double d);
	friend Length operator ""_m(long double d);
	//friend Length operator ""_m(const char* str);

private:
	// Private constructor because users should only be able to construct a
	// Length using the provided user-defined literals.
	Length(long double length) : m_length{ length } {}

	long double m_length;
};

// Cooked _km literal operator
Length operator ""_km(long double d)
{
	return Length{ d * 1000 }; // Convert to meters.
}

// Cooked _m literal operator
Length operator ""_m(long double d)
{
	return Length{ d };
}

// Raw _m literal operator
//Length operator ""_m(const char* str)
//{
//	// Implementation omitted; it requires parsing the C-style string
//	// converting it to a long double, and constructing a Length.
//	...
//}


// Cooked _s literal operator
string operator ""_s(const char* str, size_t len)
{
	return string{ str, len };
}

int main()
{
	Length d1{ 1.2_km };
	auto d2{ 1.2_m };
	println("d1 = {}m; d2 = {}m", d1.getMeters(), d2.getMeters());

	// Cooked _s literal operator
	string str1{ "Hello World"_s };
	auto str2{ "Hello World"_s };   // str2 has as type string
	auto str3{ "Hello World" };     // str3 has as type const char*

	println("{}", str1);
	println("{}", str2);
	println("{}", str3);
}
