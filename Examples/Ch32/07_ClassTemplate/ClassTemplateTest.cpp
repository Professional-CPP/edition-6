import simple_wrapper;
import std;

using namespace std;

int main()
{
	// Try wrapping an integer.
	int i{ 7 };
	SimpleWrapper intWrapper{ i };  // Using CTAD.
	// Or without class template argument deduction (CTAD).
	SimpleWrapper<int> intWrapper2{ i };
	i = 2;
	println("wrapped value is {}", intWrapper.get());
	println("wrapped value is {}", intWrapper2.get());

	// Try wrapping a string.
	string str{ "test" };
	SimpleWrapper stringWrapper{ str };
	str += "!";
	println("wrapped value is {}", stringWrapper.get());
}
