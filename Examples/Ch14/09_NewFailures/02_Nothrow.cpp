import std;

using namespace std;

int main()
{
	size_t integerCount{ numeric_limits<size_t>::max() };
	println("Trying to allocate memory for {} integers.", integerCount);

	int* ptr{ new(nothrow) int[integerCount] };
	if (ptr == nullptr) {
		auto location{ source_location::current() };
		println(cerr, "{}({}): Unable to allocate memory!",
			location.file_name(), location.line());
		// Handle memory allocation failure.
		return 1;
	}
	// Proceed with function that assumes memory has been allocated.
}
