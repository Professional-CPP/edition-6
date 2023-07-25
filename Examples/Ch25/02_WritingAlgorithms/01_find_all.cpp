import std;

using namespace std;

template <input_iterator InputIterator,
	weakly_incrementable OutputIterator,
	indirect_unary_predicate<InputIterator> Predicate>
OutputIterator find_all(InputIterator first, InputIterator last,
	OutputIterator dest, Predicate pred)
{
	while (first != last) {
		if (invoke(pred, *first)) {
			*dest = first;
			++dest;
		}
		++first;
	}
	return dest;
}

int main()
{
	vector vec{ 5, 4, 5, 4, 10, 6, 5, 8, 10 };
	vector<vector<int>::iterator> matches;

	find_all(begin(vec), end(vec), back_inserter(matches),
		[](int i){ return i == 10; });

	println("Found {} matching elements: ", matches.size());

	for (const auto& it : matches) {
		println("{} at position {}", *it, distance(begin(vec), it));
	}
	println("");
}
