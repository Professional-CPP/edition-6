import std;

using namespace std;

template <forward_iterator ForwardIterator,
	output_iterator<ForwardIterator> OutputIterator,
	indirect_unary_predicate<ForwardIterator> Predicate>
OutputIterator find_all(ForwardIterator first, ForwardIterator last,
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
	vector<int> vec{ 5, 4, 5, 4, 10, 6, 5, 8, 10 };
	vector<vector<int>::iterator> matches;

	find_all(begin(vec), end(vec), back_inserter(matches),
		[](int i){ return i == 10; });

	println("Found {} matching elements: ", matches.size());

	for (const auto& it : matches) {
		println("{} at position {}", *it, distance(begin(vec), it));
	}
	println("");
}
