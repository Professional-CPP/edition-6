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
	vector<int> vectorOne, vectorTwo, vectorMerged;
	println("Enter values for first vector:");
	populateContainer(vectorOne);
	println("Enter values for second vector:");
	populateContainer(vectorTwo);

	// Sort both containers
	sort(begin(vectorOne), end(vectorOne));
	sort(begin(vectorTwo), end(vectorTwo));

	// Make sure the destination vector is large enough to hold the values
	// from both source vectors.
	vectorMerged.resize(size(vectorOne) + size(vectorTwo));

	merge(cbegin(vectorOne), cend(vectorOne),
		cbegin(vectorTwo), cend(vectorTwo), begin(vectorMerged));

	println("Merged vector: {:n}", vectorMerged);
}
