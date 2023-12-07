import std;

using namespace std;

int main()
{
	println("Enter integers, -1 to stop.");
	print("> ");

	// Option 1: using a range-based for loop.
	{
		vector<int> values;

		for (auto& value : ranges::istream_view<int>(cin)
			| views::take_while([](const auto& v) { return v != -1; })) {
			values.push_back(value);
		}

		println("Values: {}", values);
	}

	println("Enter integers, -1 to stop.");
	print("> ");

	// Option 2: no loop, but using a range-based vector constructor.
	{
		auto r{ ranges::istream_view<int>(cin)
			| views::take_while([](const auto& v) { return v != -1; }) };

		vector<int> values{ from_range, r };

		println("Values: {}", values);
	}

	println("Enter integers, -1 to stop.");
	print("> ");

	// Option 3: no loop, but using std::ranges::copy() and a back_inserter.
	{
		vector<int> values;

		ranges::copy(ranges::istream_view<int>(cin)
			| views::take_while([](const auto& v) { return v != -1; }),
			back_inserter(values));

		println("Values: {}", values);
	}
}
