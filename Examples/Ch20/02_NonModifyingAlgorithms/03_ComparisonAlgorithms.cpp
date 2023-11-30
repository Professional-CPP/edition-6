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
	list<int> myList;

	println("Populate the vector:");
	populateContainer(myVector);
	println("Populate the list:");
	populateContainer(myList);

	// equal() and mismatch() accepting four iterators
	if (equal(cbegin(myVector), cend(myVector), cbegin(myList), cend(myList))) {
		println("The two containers have equal elements");
	} else {
		// If the containers were not equal, find out why not
		auto miss{ mismatch(cbegin(myVector), cend(myVector),
			cbegin(myList), cend(myList)) };
		println("The following initial elements are the same in "
			"the vector and the list:");
		for (auto iter{ cbegin(myVector) }; iter != miss.first; ++iter) {
			print("{}\t", *iter);
		}
		println("");
	}

	// Pre-C++14: equal() and mismatch() accepting three iterators
	//if (myList.size() == myVector.size() &&
	//	equal(cbegin(myVector), cend(myVector), cbegin(myList))) {
	//	cout << "The two containers have equal elements" << endl;
	//} else {
	//	if (myList.size() < myVector.size()) {
	//		cout << "Sorry, the list is not long enough." << endl;
	//		return 1;
	//	} else {
	//		// If the containers were not equal, find out why not
	//		auto miss{ mismatch(cbegin(myVector), cend(myVector), cbegin(myList)) };
	//		cout << "The following initial elements are the same in the vector and the list:" << endl;
	//		for (auto iter{ cbegin(myVector) }; iter != miss.first; ++iter) {
	//			cout << *iter << '\t';
	//		}
	//		cout << endl;
	//	}
	//}

	// Now order them
	if (lexicographical_compare(cbegin(myVector), cend(myVector), cbegin(myList), cend(myList))) {
		println("The vector is lexicographically first.");
	} else {
		println("The list is lexicographically first.");
	}
}
