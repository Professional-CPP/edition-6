import std;

using namespace std;

int main()
{
	println("int:");
	println("Max int value: {}", numeric_limits<int>::max());
	println("Min int value: {}", numeric_limits<int>::min());
	println("Lowest int value: {}", numeric_limits<int>::lowest());
	
	println("\ndouble:");
	println("Max double value: {}", numeric_limits<double>::max());
	println("Min double value: {}", numeric_limits<double>::min());
	println("Lowest double value: {}", numeric_limits<double>::lowest());
}