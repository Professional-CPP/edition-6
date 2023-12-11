import std;

using namespace std;

int main()
{
	string str1{ "Hello" };
	string str2{ "World" };

	// Create a vector of references to strings.
	vector<reference_wrapper<string>> vec{ ref(str1) };
	vec.push_back(ref(str2));  // push_back() works as well.

	// Modify the string referred to by the second reference in the vector.
	vec[1].get() += "!";

	// The end result is that str2 is modified.
	println("{} {}", str1, str2);
}