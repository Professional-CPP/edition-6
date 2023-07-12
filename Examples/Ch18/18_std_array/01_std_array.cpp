import std;

using namespace std;

int main()
{
	// Create an array of 3 integers and initialize them
	// with the given initializer_list using uniform initialization.
	array<int, 3> arr{ 9, 8, 7 };
	// Output the size of the array.
	println("Array size = {}", arr.size()); // or std::size(arr);
	// Output the contents using C++23's support for formatting ranges.
	println("{:n}", arr);
	// Output the contents again using a range-based for loop.
	for (const auto& i : arr) {
		print("{} ", i);
	}
	println("");

	println("Performing arr.fill(3)...");
	// Use the fill member function to change the contents of the array.
	arr.fill(3);
	// Output the contents of the array using iterators.
	for (auto iter{ cbegin(arr) }; iter != cend(arr); ++iter) {
		print("{} ", *iter);
	}
	println("");
}
