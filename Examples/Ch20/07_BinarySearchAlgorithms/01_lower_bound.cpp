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
	vector<int> values;
	populateContainer(values);

	// Sort the container
	sort(begin(values), end(values));
	println("Sorted vector: {:n}", values);

	while (true) {
		int number;
		print("Enter a number to insert (0 to stop): ");
		cin >> number;
		if (number == 0) {
			break;
		}
		
		auto iter{ lower_bound(begin(values), end(values), number) };
		values.insert(iter, number);
		
		println("New vector: {:n}", values);
	}
}
