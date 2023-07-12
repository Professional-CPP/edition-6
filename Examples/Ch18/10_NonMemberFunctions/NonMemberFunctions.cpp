import std;

using namespace std;

int main()
{
	vector vec{ 1, 2, 3 };
	println("{}", size(vec));
	println("{}", empty(vec));

	auto s1{ size(vec) };   // Type is size_t (unsigned)
	auto s2{ ssize(vec) };  // Type is long long (signed)
}
