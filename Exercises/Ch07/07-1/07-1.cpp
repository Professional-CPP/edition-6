import std;

using namespace std;

int main()
{
	const size_t numberOfElements{ 10 };
	int* values{ new int[numberOfElements] };

	// Set values to their index value.
	for (int index{ 0 }; index < numberOfElements; ++index) {
		values[index] = index;
	}

	// Set last value to 99.
	values[10] = 99; //// Array indices are zero-based, so the index of the 
	                 //// last value is 9, not 10.

	// Print all values.
	for (int index{ 0 }; index <= numberOfElements; ++index) { //// Out-of-bounds access due to <= instead of <
		print("{} ", values[index]);
	}

	//// Freeing the memory buffer is missing here.
}
