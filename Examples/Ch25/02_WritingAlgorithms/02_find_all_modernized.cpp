import std;

using namespace std;

template <forward_iterator ForwardIterator,
	sentinel_for<ForwardIterator> Sentinel,
	output_iterator<ForwardIterator> OutputIterator,
	typename Projection = std::identity,
	indirect_unary_predicate<projected<ForwardIterator, Projection>> Predicate>
OutputIterator find_all(ForwardIterator first, Sentinel last,
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
	vector<int> vec{ 5, 4, 5, 4, 10, 6, 5, 8, 10 };
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
