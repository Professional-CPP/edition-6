import std;

using namespace std;

int main()
{
	auto arr1{ to_array({ 11, 22, 33 }) }; // Type is array<int, 3>

	double carray[]{ 9, 8, 7, 6 };
	auto arr2{ to_array(carray) };         // Type is array<double, 4>
}