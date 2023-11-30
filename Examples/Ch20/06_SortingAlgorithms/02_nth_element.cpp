import std;

using namespace std;

// Function template to populate a container of ints.
// A constraint enforces that the container supports push_back(int).
template<typename Container>
	requires requires(Container& c, int i) { c.push_back(i); }
void populateContainer(Container& cont)
{
	while (true) {
		print("Enter a number (0 to stop): ");
		int value;
		cin >> value;
		if (value == 0) {
			break;
		}
		cont.push_back(value);
	}
}

int main()
{
	println("Enter at least five values.");
	
	vector<int> values;
	populateContainer(values);
	// Find the third largest value.
	nth_element(begin(values), begin(values) + 2, end(values), greater<>{});
	println("3rd largest value: {}", values[2]);


	// Get the 5 largest elements in sorted order.
	nth_element(begin(values), begin(values) + 4, end(values), greater<>{});
	// nth_element() has partitioned the elements, now sort the first subrange.
	sort(begin(values), begin(values) + 5);
	// And finally, output the sorted subrange.
	for_each_n(begin(values), 5, [](const auto& element) { print("{}  ", element); });
}
