import std;

using namespace std;

int main()
{
	// The list of elements to be searched.
	vector myVector{ 5, 6, 9, 8, 8, 3 };
	auto beginIter{ cbegin(myVector) };
	auto endIter{ cend(myVector) };

	// Find the first element that does not satisfy the given lambda expression.
	auto it{ find_if_not(beginIter, endIter, [](int i) { return i < 8; }) };
	if (it != endIter) {
		println("First element not < 8 is {}", *it);
	}

	// Find the first pair of matching consecutive elements.
	it = adjacent_find(beginIter, endIter);
	if (it != endIter) {
		println("Found two consecutive equal elements with value {}", *it);
	}

	// Find the first of two values.
	vector targets{ 8, 9 };
	it = find_first_of(beginIter, endIter, cbegin(targets), cend(targets));
	if (it != endIter) {
		println("Found one of 8 or 9: {}", *it);
	}

	// Find the first subsequence.
	vector sub{ 8, 3 };
	it = search(beginIter, endIter, cbegin(sub), cend(sub));
	if (it != endIter) {
		println("Found subsequence {{8,3}}");
	} else {
		println("Unable to find subsequence {{8,3}}");
	}

	// Find the last subsequence (which is the same as the first in this example).
	auto it2{ find_end(beginIter, endIter, cbegin(sub), cend(sub)) };
	if (it != it2) {
		println("Error: search and find_end found different subsequences "
			"even though there is only one match.");
	}

	// Find the first subsequence of two consecutive 8s.
	it = search_n(beginIter, endIter, 2, 8);
	if (it != endIter) {
		println("Found two consecutive 8s");
	} else {
		println("Unable to find two consecutive 8s");
	}
}
