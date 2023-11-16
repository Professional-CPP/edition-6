import std;

using namespace std;

// Copies a range given by a begin and end iterator to a target range.
template<input_iterator InputIter,
	output_iterator<iter_reference_t<InputIter>> OutputIter>
void myCopy(InputIter begin, InputIter end, OutputIter target)
{
	for (auto iter{ begin }; iter != end; ++iter, ++target) {
		*target = *iter;
	}
}

int main()
{
	vector vectorOne{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	set<int> setOne;

	//insert_iterator<set<int>> inserter{ setOne, begin(setOne) };
	//myCopy(cbegin(vectorOne), cend(vectorOne), inserter);

	//myCopy(cbegin(vectorOne), cend(vectorOne), inserter(setOne, begin(setOne)));

	// Using class template argument deduction.
	myCopy(cbegin(vectorOne), cend(vectorOne), insert_iterator{ setOne, begin(setOne) });

	println("{:n}", setOne);
}
