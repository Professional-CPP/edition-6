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
	vector<int> myVector;
	populateContainer(myVector);

	while (true) {
		print("Enter a number to lookup (0 to stop): ");
		int number;
		cin >> number;
		if (number == 0) {
			break;
		}
		auto endIt{ cend(myVector) };
		//auto it{ find(cbegin(myVector), endIt, number) };
		//if (it == endIt) {
		if (auto it{ find(cbegin(myVector), endIt, number) }; it == endIt) {
			println("Could not find {}", number);
		} else {
			println("Found {}", *it);
		}
	}
}
