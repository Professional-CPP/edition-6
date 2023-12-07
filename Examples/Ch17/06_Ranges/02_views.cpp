import std;

using namespace std;

void printRange(string_view message, auto&& range)
{
	println("{}{:n}", message, range);
}

template <typename InputIter, typename OutputIter>
void myCopy(InputIter begin, InputIter end, OutputIter target)
{
	for (auto iter{ begin }; iter != end; ++iter, ++target) { *target = *iter; }
}

int main()
{
	vector values{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printRange("Original sequence: ", values);

	// Filter out all odd values, leaving only the even values.
	auto result1{ values | views::filter([](const auto& value) { return value % 2 == 0; }) };
	//Or:
	//  auto result1{ ranges::filter_view{ values, [](const auto& value) { return value % 2 == 0; } } };
	printRange("Only even values: ", result1);

	// Transform all values to their double value.
	auto result2{ result1 | views::transform([](const auto& value) { return value * 2.0; }) };
	printRange("Values doubled: ", result2);

	// Drop the first 2 elements.
	auto result3{ result2 | views::drop(2) };
	printRange("First two dropped: ", result3);

	// Reverse the view.
	auto result4{ result3 | views::reverse };
	printRange("Sequence reversed: ", result4);

	// C++23: views::zip
	vector v1{ 1, 2 };
	vector v2{ 'a', 'b', 'c' };
	auto result5{ views::zip(v1, v2) }; // (1,'a'),(2,'b')
	printRange("views::zip: ", result5);

	// C++23: views::adjacent
	vector v3{ 1, 2, 3, 4, 5 };
	auto result6{ v3 | views::adjacent<2> }; // (1,2),(2,3),(3,4),(4,5)
	printRange("views::adjacent: ", result6);

	// C++23: views::chunk
	auto result7{ v3 | views::chunk(2) }; // (1,2),(3,4),(5)
	printRange("views::chunk: ", result7);

	// C++23: views::stride
	auto result8{ v3 | views::stride(2) }; // 1,3,5
	printRange("views::stride: ", result8);

	// C++23: views::enumerate + views::split
	string lorem{ "Lorem ipsum dolor sit amet" };
	for (auto [index, word] : lorem | views::split(' ') | views::enumerate) {
		print("{}:'{}' ", index, string_view{ word }); // 0:'Lorem' 1:'ipsum' 2:'dolor' 3:'sit' 4:'amet'
	}
	println("");

	// C++23: views::as_rvalue
	vector<string> words{ "Lorem", "ipsum", "dolor", "sit", "amet" };
	vector<string> movedWords;
	auto rvalueView{ words | views::as_rvalue };
	myCopy(begin(rvalueView), end(rvalueView), back_inserter(movedWords));
	printRange("movedWords: ", movedWords);

	// C++23: Cartesian product of vector v with itself.
	vector v{ 0, 1, 2 };
	for (auto&& [a, b] : views::cartesian_product(v, v)) {
		print("({},{}) ", a, b); // (0,0) (0,1) (0,2) (1,0) (1,1) (1,2) (2,0) (2,1) (2,2)
	}
	println("");
}
