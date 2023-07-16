import std;

using namespace std;

int main()
{
	vector<int> values(20);
	ranges::iota(values, 1);

	deque<int> evens, odds;
	ranges::partition_copy(values,
		back_inserter(evens),
		front_inserter(odds),
		[](int i) { return i % 2 == 0; });

	println("Even numbers: {:n}", evens);
	println("Odd numbers:  {:n}", odds);
}