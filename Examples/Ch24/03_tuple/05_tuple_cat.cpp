import std;

using namespace std;

int main()
{
	tuple t1{ 16, "Test"s, true };  // Using CTAD
	tuple t2{ 3.14, "string 2"s };
	// Or:
	//tuple<int, string, bool> t1{ 16, "Test", true };
	//tuple<double, string> t2{ 3.14, "string 2" };

	auto t3{ tuple_cat(t1, t2) };

	println("t3 = {}", t3);
}
