import std;

using namespace std;

void printRange(string_view message, auto&& range)
{
	println("{}{:n}", message, range);
}

int main()
{
	// Create an infinite sequence of the numbers 10, 11, 12, ...
	auto values{ views::iota(10) };
	// Filter out all odd values, leaving only the even values.
	auto result1{ values | views::filter([](const auto& value) {return value % 2 == 0; }) };
	// Transform all values to their double value.
	auto result2{ result1 | views::transform([](const auto& value) {return value * 2.0; }) };
	// Take only the first ten elements.
	auto result3{ result2 | views::take(10) };
	printRange("Result: ", result3);
}
