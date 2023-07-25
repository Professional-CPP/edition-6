import std;

using namespace std;

template<input_iterator InputIterator,
	weakly_incrementable OutputIterator,
	indirect_unary_predicate<InputIterator> Predicate,
	typename UnaryOperation>
OutputIterator transform_if(InputIterator first, InputIterator last,
	OutputIterator output, Predicate pred, UnaryOperation op)
{
	auto iter{ first };
	while (iter != last) {
		if (invoke(pred, *iter)) {
			*output = op(*iter);
		} else {
			*output = *iter;
		}
		++output;
		++iter;
	}
	return output;
}

int main()
{
	vector values{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (auto& value : values) { print("{} ", value); }
	println("");

	transform_if(begin(values), end(values), begin(values),
		[](const auto& value) { return value % 2 != 0; },
		[](const auto& value) { return value * 2; });

	for (auto& value : values) { print("{} ", value); }
	println("");
}