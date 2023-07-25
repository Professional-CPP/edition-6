import std;

using namespace std;

template <input_iterator InputIterator,
	sentinel_for<InputIterator> Sentinel,
	weakly_incrementable OutputIterator,
	typename Projection = std::identity,
	indirect_unary_predicate<projected<InputIterator, Projection>> Predicate>
OutputIterator find_all(InputIterator first, Sentinel last,
	OutputIterator dest, Predicate pred, Projection proj = {})
{
	while (first != last) {
		if (invoke(pred, invoke(proj, *first))) {
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
		[](int i){ return i == 10; },
		[](int i){ return i * 2; });

	println("Found {} matching elements: ", matches.size());

	for (const auto& it : matches) {
		println("{} at position {}", *it, distance(begin(vec), it));
	}
	println("");
}
