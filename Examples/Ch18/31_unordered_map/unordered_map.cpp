import std;

using namespace std;

int main()
{
	unordered_map<int, string> m{
		{1, "Item 1"},
		{2, "Item 2"},
		{3, "Item 3"},
		{4, "Item 4"},
	};

	// Using C++23 support for formatting/printing ranges.
	println("{}", m);

	// Using structured bindings.
	for (const auto&[key, value] : m) {
		print("{} = {}, ", key, value);
	}
	println("");

	// Without structured bindings.
	for (const auto& p : m) {
		print("{} = {}, ", p.first, p.second);
	}
	println("");
}
