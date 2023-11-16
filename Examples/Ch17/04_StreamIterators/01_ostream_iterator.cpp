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
	vector myVector{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// Use myCopy() to copy myVector to vectorCopy.
	vector<int> vectorCopy(myVector.size());
	myCopy(cbegin(myVector), cend(myVector), begin(vectorCopy));

	// Use the same myCopy() to print the contents of both vectors.
	myCopy(cbegin(myVector), cend(myVector), ostream_iterator<int> { cout, " " });
	println("");
	myCopy(cbegin(vectorCopy), cend(vectorCopy), ostream_iterator<int> { cout, " " });
	println("");
}
