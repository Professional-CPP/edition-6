import std;

using namespace std;

template<predicate<int, int> Matcher, invocable<size_t, int, int> MatchHandler>
void findMatches(span<const int> values1, span<const int> values2,
	Matcher matcher, MatchHandler handler)
{
	if (values1.size() != values2.size()) { return; } // Must be same size.

	for (size_t i{ 0 }; i < values1.size(); ++i) {
		if (matcher(values1[i], values2[i])) {
			handler(i, values1[i], values2[i]);
		}
	}
}

void printMatch(size_t position, int value1, int value2)
{
	println("Match found at position {} ({}, {})", position, value1, value2);
}

int main()
{
	// Define a generic lambda expression to find equal values.
	auto areEqual{ [](const auto& value1, const auto& value2) { return value1 == value2; } };

	// Use the generic lambda expression in a call to findMatches().
	vector values1{ 2, 5, 6, 9, 10, 1, 1 };
	vector values2{ 4, 4, 2, 9, 0, 3, 1 };
	println("Calling findMatches() using generic lambda expression:");
	findMatches(values1, values2, areEqual, printMatch);
}
