import std;

using namespace std;

int main()
{
	print("{} ", conjunction_v<is_integral<int>, is_integral<short>>);
	print("{} ", conjunction_v<is_integral<int>, is_integral<double>>);

	print("{} ", disjunction_v<is_integral<int>, is_integral<double>, is_integral<short>>);

	print("{} ", negation_v<is_integral<int>>);
}
