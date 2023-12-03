import simple_wrapper;
import std;

using namespace std;

int main()
{
	// Try wrapping an integer.
	int i{ 7 };
	SimpleWrapper intWrapper{ i };
	i = 2;
	println("wrapped value is {}", intWrapper.get());

	// The following now causes a compilation error.
	//string str{ "test" };
	//SimpleWrapper stringWrapper{ str };
	//str += "!";
	//println("wrapped value is {}", stringWrapper.get());
}
