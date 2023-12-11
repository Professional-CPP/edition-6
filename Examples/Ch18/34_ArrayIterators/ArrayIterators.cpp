import std;

using namespace std;

int main()
{
	const size_t count{ 10 };
	int values[count];     // standard C-style array

	// Initialize each element of the array to the value of its index.
	for (int i{ 0 }; i < count; ++i) {
		values[i] = i;
	}

	// Insert the contents of the array at the end of a vector.
	vector<int> vec;
	// Using C++23 append_range().
	vec.append_range(values);
	// Or: using insert().
	//vec.insert(end(vec), values, values + count);
	// Or: using insert() with std::cbegin() and std::cend().
	//vec.insert(end(vec), cbegin(values), cend(values));

	// Print the contents of the vector.
	println("{:n} ", vec);
}
