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
	vector<int> vectorTwo;

	back_insert_iterator<vector<int>> inserter{ vectorTwo };
	//myCopy(cbegin(vectorOne), cend(vectorOne), inserter);

	//myCopy(cbegin(vectorOne), cend(vectorOne), back_inserter(vectorTwo));

	// Using class template argument deduction.
	myCopy(cbegin(vectorOne), cend(vectorOne), back_insert_iterator{ vectorTwo });

	println("{:n}", vectorTwo);
}
