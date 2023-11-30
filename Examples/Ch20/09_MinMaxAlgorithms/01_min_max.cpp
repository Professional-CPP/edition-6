import std;

using namespace std;

int main()
{
	int x{ 4 }, y{ 5 };
	println("x is {} and y is {}", x, y);
	println("Max is {}", max(x, y));
	println("Min is {}", min(x, y));

	// Using max() and min() on more than two values.
	int x1{ 2 }, x2{ 9 }, x3{ 3 }, x4{ 12 };
	println("Max of 4 elements is {}", max({ x1, x2, x3, x4 }));
	println("Min of 4 elements is {}", min({ x1, x2, x3, x4 }));

	// Using minmax().
	auto p2{ minmax({ x1, x2, x3, x4 }) };	// p2 is of type pair<int, int>.
	println("Minmax of 4 elements is <{},{}>", p2.first, p2.second);

	// Using minmax() + structured bindings.
	auto [min1, max1] { minmax({ x1, x2, x3, x4 }) };
	println("Minmax of 4 elements is <{},{}>", min1, max1);

	// Using minmax_element() + structured bindings.
	vector values{ 11, 33, 22 };
	auto [min2, max2] { minmax_element(cbegin(values), cend(values)) };
	println("minmax_element() result: <{},{}>", *min2, *max2);
}
