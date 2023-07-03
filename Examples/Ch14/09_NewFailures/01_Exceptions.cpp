import std;

using namespace std;

int main()
{
	int* ptr{ nullptr };
	size_t integerCount{ numeric_limits<size_t>::max() };
	println("Trying to allocate memory for {} integers.", integerCount);

	try {
		ptr = new int[integerCount];
	} catch (const bad_alloc& e) {
		auto location{ source_location::current() };
		println(cerr, "{}({}): Unable to allocate memory: {}",
			location.file_name(), location.line(), e.what());
		// Handle memory allocation failure.
		return 1;
	}
	// Proceed with function that assumes memory has been allocated.
}
