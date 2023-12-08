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

class IsLargerThan
{
public:
	explicit IsLargerThan(int value) : m_value{ value } {}

	bool operator()(int value1, int value2) const {
		return value1 > m_value && value2 > m_value;
	}

private:
	int m_value;
};

int main()
{
	vector values1{ 2, 500, 6, 9, 10, 101, 1 };
	vector values2{ 4, 4, 2, 9, 0, 300, 1 };

	findMatches(values1, values2, IsLargerThan{ 100 }, printMatch);
}
