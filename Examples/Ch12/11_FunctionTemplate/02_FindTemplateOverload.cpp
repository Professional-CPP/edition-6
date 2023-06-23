import std;

using namespace std;

template <typename T>
optional<size_t> Find(const T& value, const T* arr, size_t size)
{
	println("original");
	for (size_t i{ 0 }; i < size; ++i) {
		if (arr[i] == value) {
			return i; // Found it; return the index.
		}
	}
	return {}; // Failed to find it; return empty optional.
}

template <typename T, size_t N>
optional<size_t> Find(const T& value, const T(&arr)[N])
{
	return Find(value, arr, N);
}

optional<size_t> Find(const char* value, const char** arr, size_t size)
{
	println("overload");
	for (size_t i{ 0 }; i < size; ++i) {
		if (strcmp(arr[i], value) == 0) {
			return i; // Found it; return the index.
		}
	}
	return {}; // Failed to find it; return empty optional.
}

int main()
{
	// Using an array for word to make sure no literal pooling happens, see Chapter 2.
	const char word[]{ "two" };
	const char* words[]{ "one", "two", "three", "four" };
	const size_t sizeWords{ size(words) };
	optional<size_t> res{ Find(word, words, sizeWords) }; // Calls non-template find.
	if (res) { println("{}", *res); }
	else { println("Not found"); }

	res = Find<const char*>(word, words, sizeWords); // Calls template with T=const char*.
	if (res) { println("{}", *res); }
	else { println("Not found"); }
}
