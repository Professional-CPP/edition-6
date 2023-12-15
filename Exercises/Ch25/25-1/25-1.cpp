import std;

using namespace std;

template<forward_iterator ForwardIterator,
	output_iterator<iter_reference_t<ForwardIterator>> OutputIterator,
	indirect_unary_predicate<ForwardIterator> Predicate,
	invocable<iter_reference_t<ForwardIterator>> UnaryOperation>
OutputIterator transform_if(ForwardIterator first, ForwardIterator last,
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
	array values{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	println("{:n}", values);

	vector<int> result;
	transform_if(begin(values), end(values), back_insert_iterator{ result },
		[](const auto& value) { return value % 2 != 0; },
		[](const auto& value) { return value * 2; });

	println("{:n}", result);
}
